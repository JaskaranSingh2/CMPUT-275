#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

SAMPLE="./multipliers_sample"
USER_PROGRAM="./multipliers"

TESTS="sample1 sample2 "

passed=0
failed=0

for test in $TESTS; do
    echo "Running $test..."
    $SAMPLE  < "$test.in" > sample.out 2> sample.err
    SAMPLE_EXIT=$?
    $USER_PROGRAM  < "$test.in" > user.out 2> user.err
    USER_EXIT=$?

    echo "--- Expected Output ---"
    cat sample.out
    echo "--- Actual Output ---"
    cat user.out
    echo "--- Expected Exit Status: $SAMPLE_EXIT ---"
    echo "--- Actual Exit Status: $USER_EXIT ---"

    if diff -q sample.out user.out >/dev/null && [ $SAMPLE_EXIT -eq $USER_EXIT ]; then
        echo -e "${GREEN}PASSED${NC}"
        ((passed++))
    else
        echo -e "${RED}FAILED${NC}"
        ((failed++))
    fi
done

echo "Passed: $passed, Failed: $failed"
rm -f sample.out user.out sample.err user.err
exit $failed