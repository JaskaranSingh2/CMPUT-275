#!/bin/bash

# Array of input files
input_files=($(seq -f "sample%.0f.in" 1 26))

# Loop through each input file
for input_file in "${input_files[@]}"; do
    echo "Testing with input file: $input_file"

    # Run your implementation
    ./int_set < "$input_file" > your_output.txt
    your_status=$?

    # Run the sample implementation
    ./intset_sample < "$input_file" > sample_output.txt
    sample_status=$?

    # Compare outputs
    if diff -q your_output.txt sample_output.txt >/dev/null; then
        echo "Output: PASS ✅"
    else
        echo "Output: FAIL ❌"
        echo "Differences:"
        echo "Your output:"
        cat your_output.txt
        echo "Sample output:"
        cat sample_output.txt
    fi

    # Compare exit statuses
    if [ "$your_status" -eq "$sample_status" ]; then
        echo "Exit Status: PASS ✅"
    else
        echo "Exit Status: FAIL ❌"
        echo "  Your exit status:    $your_status"
        echo "  Sample exit status:  $sample_status"
    fi

    echo "-----------------------------------"
done

# Clean up temporary files
rm -f your_output.txt sample_output.txt