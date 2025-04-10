#!/bin/bash
YOUR="./numerals"
SAMPLE="./numerals_sample"

run_test() {
    local infile="$1"
    echo "===== Running $infile ====="
    echo "--- Input:"
    cat "$infile"
    echo

    your_output=$($YOUR < "$infile")
    sample_output=$($SAMPLE < "$infile")

    echo "--- Your Output:"
    echo "$your_output"
    echo "--- Sample Output:"
    echo "$sample_output"

    if diff -u <(echo "$sample_output") <(echo "$your_output") > /dev/null; then
        echo "✅ Match"
    else
        echo "❌ Mismatch"
        diff -u <(echo "$sample_output") <(echo "$your_output")
    fi
    echo
}

# Run provided test files
for infile in test*.in; do
    [[ $infile == *"args"* ]] && continue
    run_test "$infile"
done

# Additional test cases
echo "III"     | tee /tmp/testcase | run_test /tmp/testcase        # 3
echo "IV"      | tee /tmp/testcase | run_test /tmp/testcase        # 4
echo "XLIV"    | tee /tmp/testcase | run_test /tmp/testcase        # 44
echo "MMMCMXCIX" | tee /tmp/testcase | run_test /tmp/testcase      # 3999
echo "IX"      | tee /tmp/testcase | run_test /tmp/testcase        # 9
echo "XLI"     | tee /tmp/testcase | run_test /tmp/testcase        # 41
echo "MCMXC"   | tee /tmp/testcase | run_test /tmp/testcase        # 1990