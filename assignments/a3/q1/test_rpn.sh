#!/bin/bash

while IFS= read -r test_case; do
    # Run your implementation
    your_output=$(echo "$test_case" | ./rpn)
    your_status=$?

    # Run the sample implementation
    sample_output=$(echo "$test_case" | ./rpn_sample)
    sample_status=$?

    # Compare outputs and exit statuses
    if [ "$your_output" == "$sample_output" ] && [ "$your_status" -eq "$sample_status" ]; then
        echo "Test case '$test_case': PASS ✅"
    else
        echo "Test case '$test_case': FAIL ❌"
        echo "  Your output:    '$your_output' (exit status: $your_status)"
        echo "  Sample output:  '$sample_output' (exit status: $sample_status)"
    fi
done < test_cases.txt