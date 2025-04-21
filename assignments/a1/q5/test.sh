#!/bin/bash
YOUR="./divisors"
SAMPLE="./divisors_sample"

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
