#!/bin/bash

for x in One Two Three; do
  echo "Start of loop body"
  echo ${x}
done


for x in $(cat /home/rob/w25_cmput275/bash_scripts/alice.txt); do
  echo The word is: ${x}
done
