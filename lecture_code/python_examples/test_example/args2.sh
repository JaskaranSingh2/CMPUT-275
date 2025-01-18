#!/bin/bash

myFunction() {
  echo "Wrong arg ${1}! It must be > 5"
}

echo "Your arg was ${1}"

if [ $1 -le 5 ]; then
  myFunction
else
  echo "Good job!"
fi
