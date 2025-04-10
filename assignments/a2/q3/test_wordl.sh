#!/bin/bash

# Colors
GREEN='\033[1;32m'
RED='\033[1;31m'
BLUE='\033[1;34m'
YELLOW='\033[1;33m'
NC='\033[0m'

YOUR="./wordl"
SAMPLE="./wordl_sample"

passed=0
failed=0
total=0

run_test() {
    local infile="$1"
    local argfile="$2"
    local code=$(cat "$argfile")

    ((total++))
    echo -e "${BLUE}===== Running $infile with code word: $code =====${NC}"
    echo -e "${YELLOW}--- Input:${NC}"
    cat "$infile"
    echo

    # Run programs
    your_output=$($YOUR "$code" < "$infile")
    sample_output=$($SAMPLE "$code" < "$infile")

    # Write to temporary files
    echo "$your_output" > my_output.txt
    echo "$sample_output" > sample_output.txt

    # echo -e "${YELLOW}--- Your Output (visible whitespace):${NC}"
    # cat -A my_output.txt
    # echo -e "${YELLOW}--- Sample Output (visible whitespace):${NC}"
    # cat -A sample_output.txt

    if cmp -s my_output.txt sample_output.txt; then
        echo -e "${GREEN}✅ Output matches exactly!${NC}"
        ((passed++))
    else
        echo -e "${RED}❌ Output differs.${NC}"

        echo -e "${BLUE}--- Size Comparison:${NC}"
        echo "Yours:   $(wc -c < my_output.txt) bytes"
        echo "Sample: $(wc -c < sample_output.txt) bytes"

        echo -e "${BLUE}--- Diff (showing invisible whitespace as ·):${NC}"
        sed 's/ /·/g' sample_output.txt > sample_visible.txt
        sed 's/ /·/g' my_output.txt > my_visible.txt
        diff -u --color=always sample_visible.txt my_visible.txt | grep -v "^@@" | grep -v "^---" | grep -v "^+++"

        ((failed++))

        echo -e "${BLUE}--- Sample Output:${NC}"
        cat sample_output.txt
        echo -e "${BLUE}--- Test Output:${NC}"
        cat my_output.txt
    fi

    echo -e "${NC}----------------------------------------"
    rm -f my_output.txt sample_output.txt sample_visible.txt my_visible.txt
}

# Run matching .in/.args files
for infile in test*.in; do
    base="${infile%.in}"
    argfile="${base}.args"
    if [ -f "$argfile" ]; then
        run_test "$infile" "$argfile"
    fi
done

# Additional manual test cases
echo -e "bevel\neenie\nverge\n" > /tmp/testcase.in
echo "verge" > /tmp/testcase.args
run_test /tmp/testcase.in /tmp/testcase.args

echo -e "aaaaa\naaaaa\naaaaa\naaaaa\naaaaa\naaaaa\n" > /tmp/testcase.in
echo "zzzzz" > /tmp/testcase.args
run_test /tmp/testcase.in /tmp/testcase.args

echo -e "abcde\nfghij\nklmno\npqrst\nuvwxy\nzzzzz\n" > /tmp/testcase.in
echo "abcde" > /tmp/testcase.args
run_test /tmp/testcase.in /tmp/testcase.args

rm -f /tmp/testcase.in /tmp/testcase.args

# Summary
echo -e "${BLUE}===== TEST SUMMARY =====${NC}"
echo -e "Total tests: $total"
echo -e "${GREEN}✅ Passed: $passed${NC}"
echo -e "${RED}❌ Failed: $failed${NC}"