#!/bin/bash

# test_transformer.sh - A script to test the transformer program against the sample executable
# Usage: ./test_transformer.sh
# This script will test PPM files and precisely locate whitespace differences

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# Test files to use
TEST_FILES=("beach.ppm" "creek.ppm" "lines.ppm")

# Option combinations to test
OPTION_SETS=("" "-f" "-s" "-f -s")

# Function to run a test with specific file and options
run_test() {
    local test_file=$1
    local options=$2
    
    echo -e "${BLUE}Testing with file: $test_file, options: $options${NC}"
    
    # Create temporary files for outputs
    MY_OUTPUT="my_output.ppm"
    SAMPLE_OUTPUT="sample_output.ppm"
    
    # Run both executables with the same input and options
    ./transformer $options < $test_file > $MY_OUTPUT
    MY_EXIT_STATUS=$?
    
    ./ppm_sample $options < $test_file > $SAMPLE_OUTPUT
    SAMPLE_EXIT_STATUS=$?
    
    # Compare exit statuses
    echo "Exit status comparison:"
    if [ $MY_EXIT_STATUS -eq $SAMPLE_EXIT_STATUS ]; then
        echo -e "${GREEN}Exit statuses match: $MY_EXIT_STATUS${NC}"
    else
        echo -e "${RED}Exit statuses differ: Mine=$MY_EXIT_STATUS, Sample=$SAMPLE_EXIT_STATUS${NC}"
    fi
    
    # Compare outputs
    echo "Output comparison:"
    if cmp -s "$MY_OUTPUT" "$SAMPLE_OUTPUT"; then
        echo -e "${GREEN}Outputs match exactly!${NC}"
    else
        echo -e "${YELLOW}Outputs differ - locating whitespace differences:${NC}"
        
        # Compare file sizes
        MY_SIZE=$(wc -c < "$MY_OUTPUT")
        SAMPLE_SIZE=$(wc -c < "$SAMPLE_OUTPUT")
        
        echo "My output size: $MY_SIZE bytes"
        echo "Sample output size: $SAMPLE_SIZE bytes"
        
        # Check header differences (first 3 lines)
        echo -e "${BLUE}Header comparison (showing invisible characters):${NC}"
        echo "Sample header:"
        head -n 3 $SAMPLE_OUTPUT | cat -A
        echo "My header:"
        head -n 3 $MY_OUTPUT | cat -A
        
        # Convert files to show all whitespace characters visibly
        echo -e "${BLUE}Locating exact differences:${NC}"
        
        # Compare files line by line
        DIFF_FOUND=0
        LINE_NUM=0
        
        # Use temporary files for the special whitespace-visible versions
        MY_VISIBLE="my_visible.txt"
        SAMPLE_VISIBLE="sample_visible.txt"
        
        > $MY_VISIBLE
        > $SAMPLE_VISIBLE
        
        # Process each file to make whitespace visible
        while IFS= read -r line; do
            # Replace spaces with visible character and preserve other whitespace
            echo "$line" | sed 's/ /·/g' >> $MY_VISIBLE
        done < "$MY_OUTPUT"
        
        while IFS= read -r line; do
            # Replace spaces with visible character and preserve other whitespace
            echo "$line" | sed 's/ /·/g' >> $SAMPLE_VISIBLE
        done < "$SAMPLE_OUTPUT"
        
        # Now diff the visible versions to see whitespace differences
        echo -e "${YELLOW}Showing differences with whitespace made visible (· = space):${NC}"
        echo "< = Sample output, > = My output"
        
        # Show differences in context, with line numbers
        diff -u --color=always $SAMPLE_VISIBLE $MY_VISIBLE | grep -v "^@@" | grep -v "^---" | grep -v "^+++"
        
        # Additional hexdump for precise byte-level inspection
        echo -e "${BLUE}First differing byte location:${NC}"
        cmp -l $SAMPLE_OUTPUT $MY_OUTPUT | head -n 5
        
        # Clean up temporary files
        rm -f $MY_VISIBLE $SAMPLE_VISIBLE
        
        # Compare normalized versions (remove all whitespace differences)
        MY_NORM="my_norm.txt"
        SAMPLE_NORM="sample_norm.txt"
        
        # Normalize files (keep only numbers)
        tr -d '[:space:]' < $MY_OUTPUT > $MY_NORM
        tr -d '[:space:]' < $SAMPLE_OUTPUT > $SAMPLE_NORM
        
        if cmp -s "$MY_NORM" "$SAMPLE_NORM"; then
            echo -e "${GREEN}Content matches after normalizing whitespace!${NC}"
            echo "Only whitespace formatting differs, not the actual pixel values."
        else
            echo -e "${RED}Contents differ beyond just whitespace.${NC}"
            # Compare the numerical content
            echo "Numerical differences (after removing all whitespace):"
            diff $SAMPLE_NORM $MY_NORM | head
        fi
        
        # Clean up normalized files
        rm -f $MY_NORM $SAMPLE_NORM
    fi
    
    # Clean up temporary files
    rm -f $MY_OUTPUT $SAMPLE_OUTPUT
    
    echo "----------------------------------------"
}

# Compile our solution
echo "Compiling transformer.c..."
gcc -Wall -Wvla -Werror transformer.c -o transformer
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed!${NC}"
    exit 1
fi
echo -e "${GREEN}Compilation successful!${NC}"

# Make sure we have the sample executable
if [ ! -f "./ppm_sample" ]; then
    echo -e "${RED}Error: ppm_sample executable not found!${NC}"
    echo "Make sure you have the sample executable in the current directory."
    exit 1
fi

# Check if all test files exist
MISSING_FILES=0
for file in "${TEST_FILES[@]}"; do
    if [ ! -f "$file" ]; then
        echo -e "${RED}Error: Test file $file not found!${NC}"
        MISSING_FILES=1
    fi
done

if [ $MISSING_FILES -eq 1 ]; then
    echo "Would you like to test with only available files? (y/n)"
    read -r CONTINUE
    if [ "$CONTINUE" != "y" ]; then
        echo "Exiting."
        exit 1
    fi
    # Filter to only existing files
    AVAILABLE_FILES=()
    for file in "${TEST_FILES[@]}"; do
        if [ -f "$file" ]; then
            AVAILABLE_FILES+=("$file")
        fi
    done
    TEST_FILES=("${AVAILABLE_FILES[@]}")
fi

# Run tests with all combinations
for file in "${TEST_FILES[@]}"; do
    for options in "${OPTION_SETS[@]}"; do
        run_test $file "$options"
    done
done

echo -e "${GREEN}All tests completed!${NC}"