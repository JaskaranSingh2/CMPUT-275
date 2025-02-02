#!/bin/bash

echo "$1"

if [[-z "$1"]]; then
    echo "Usage: $0 <test-set-file>" >&2 # Send this to stderr
fi

file_stems = (cat "$1")

for file_stem in file_stems; do
    if [[-e "${file_stem}.desc"]]; then # Although the curly-braces aren't necessary here I just maintain them for neatness.
        cat "${file_stem}.desc"
    fi
done