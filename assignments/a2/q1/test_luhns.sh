#!/bin/bash
YOUR="./luhns"
SAMPLE="./luhns_sample"

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

# Additional edge tests
echo "=== Additional Edge Cases ==="

echo "1234567812345670" | tee /tmp/testcase | run_test /tmp/testcase
echo "0"               | tee /tmp/testcase | run_test /tmp/testcase
echo "9999999999999999" | tee /tmp/testcase | run_test /tmp/testcase
echo "79927398713"    | tee /tmp/testcase | run_test /tmp/testcase
echo "79927398710"    | tee /tmp/testcase | run_test /tmp/testcase  # Invalid checksum
echo "abcd1234"       | tee /tmp/testcase | run_test /tmp/testcase  # Should stop on first non-digit