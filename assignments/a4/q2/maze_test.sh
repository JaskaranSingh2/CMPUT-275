#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
NC='\033[0m'

SAMPLE="./maze_sample"
USER_PROGRAM="./maze"

# Array of input files
input_files=($(seq -f "test%.0f" 1 4))

passed=0
failed=0

# Function to run a test with specific file
run_test() {
    local test=$1
    echo -e "${BLUE}Testing with input file: $test${NC}"

    # Create temporary files for outputs
    YOUR_OUTPUT="your_output.txt"
    SAMPLE_OUTPUT="sample_output.txt"
    
    # Run both implementations
    $USER_PROGRAM $(cat "$test.args") < "$test.in" > $YOUR_OUTPUT
    your_status=$?
    
    $SAMPLE $(cat "$test.args") < "$test.in" > $SAMPLE_OUTPUT
    sample_status=$?

    # Compare outputs
    if cmp -s "$YOUR_OUTPUT" "$SAMPLE_OUTPUT"; then
        echo -e "${GREEN}Output: PASS ✅${NC}"
        ((passed++))
    else
        echo -e "${RED}Output: FAIL ❌${NC}"
        
        # Compare file sizes
        YOUR_SIZE=$(wc -c < "$YOUR_OUTPUT")
        SAMPLE_SIZE=$(wc -c < "$SAMPLE_OUTPUT")
        
        echo "Your output size: $YOUR_SIZE bytes"
        echo "Sample output size: $SAMPLE_SIZE bytes"
        
        # Create visible whitespace versions
        YOUR_VISIBLE="your_visible.txt"
        SAMPLE_VISIBLE="sample_visible.txt"
        
        > $YOUR_VISIBLE
        > $SAMPLE_VISIBLE
        
        # Process files to make whitespace visible
        while IFS= read -r line; do
            echo "$line" | sed 's/ /·/g' >> $YOUR_VISIBLE
        done < "$YOUR_OUTPUT"
        
        while IFS= read -r line; do
            echo "$line" | sed 's/ /·/g' >> $SAMPLE_VISIBLE
        done < "$SAMPLE_OUTPUT"
        
        # Show differences with visible whitespace
        echo -e "${YELLOW}Differences with whitespace made visible (· = space):${NC}"
        echo "< = Sample output, > = Your output"
        diff -u --color=always $SAMPLE_VISIBLE $YOUR_VISIBLE | grep -v "^@@" | grep -v "^---" | grep -v "^+++"
        
        # Show first differing byte locations
        echo -e "${BLUE}First differing byte locations:${NC}"
        cmp -l $SAMPLE_OUTPUT $YOUR_OUTPUT | head -n 5
        
        # Compare normalized versions (remove all whitespace)
        YOUR_NORM="your_norm.txt"
        SAMPLE_NORM="sample_norm.txt"
        
        tr -d '[:space:]' < $YOUR_OUTPUT > $YOUR_NORM
        tr -d '[:space:]' < $SAMPLE_OUTPUT > $SAMPLE_NORM
        
        if cmp -s "$YOUR_NORM" "$SAMPLE_NORM"; then
            echo -e "${GREEN}Content matches after normalizing whitespace!${NC}"
            echo "Only whitespace formatting differs."
        else
            echo -e "${RED}Contents differ beyond just whitespace.${NC}"
        fi
        
        # Clean up temporary comparison files
        rm -f $YOUR_VISIBLE $SAMPLE_VISIBLE $YOUR_NORM $SAMPLE_NORM
        ((failed++))
    fi

    # Compare exit statuses
    if [ "$your_status" -eq "$sample_status" ]; then
        echo -e "${GREEN}Exit Status: PASS ✅${NC}"
    else
        echo -e "${RED}Exit Status: FAIL ❌${NC}"
        echo "  Your exit status:    $your_status"
        echo "  Sample exit status:  $sample_status"
    fi

    echo "----------------------------------------"
}

# Check if sample executable exists
if [ ! -f "$SAMPLE" ]; then
    echo -e "${RED}Error: Sample executable ($SAMPLE) not found!${NC}"
    exit 1
fi

# Check if user program exists
if [ ! -f "$USER_PROGRAM" ]; then
    echo -e "${RED}Error: User program ($USER_PROGRAM) not found!${NC}"
    exit 1
fi

# Run tests for each input file
for test in "${input_files[@]}"; do
    if [ ! -f "${test}.in" ]; then
        echo -e "${YELLOW}Warning: Test file ${test}.in not found, skipping...${NC}"
        continue
    fi
    run_test $test
done

echo -e "Final Results: ${GREEN}Passed: $passed${NC}, ${RED}Failed: $failed${NC}"

# Clean up temporary files
rm -f your_output.txt sample_output.txt

exit $failed
