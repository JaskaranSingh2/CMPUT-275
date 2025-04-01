#!/bin/bash

# Array of test cases
test_cases=(
# Test Case 1: Basic Maze Navigation
"XXXXX
XSOX
XXOX
XOGX
XXXXX

p
me p
ms p
mw p
mn p
me p
me p
ms p
p"

# Test Case 2: Teleporter Basic Usage
"XXXXXXX
XSX
XXXXX
X1X1X
XXXXX
XGX
XXXXXXX

p
me p
me p
me p
ms p
ms p
ms p
p"

# Test Case 3: Ice Sliding Mechanics
"XXXXXXXXX
XSX
XXXXXIIX
XXIIIIGX
XXXXXXXX
XX
XXXXXXXXX

p
me p
me p
me p
ms p
ms p
me p
p"

# Test Case 4: Teleporter to Goal
"XXXXX
XS1XX
XXXXX
XX1GX
XXXXX

p
me p
p"

# Test Case 5: Ice to Goal Direct Path
"XXXXXXXXX
XSX
XIIIIIIGX
XXXXXXXXX

p
me p
p"

# Test Case 6: Complex Navigation with Reset
"XXXXXXXXX
XSXX
XXXXXX
X1XXX
XXXXXX
X1XXXXX
XXGX
XXXXXXXXX

p
me p
me p
ms p
ms p
ms p
r p
me p
me p
ms p
ms p
ms p
me p
p"

# Test Case 7: Multiple Goal Choices
"XXXXXXX
XSX
XXXXX
XGXGX
XXXXXXX

p
me p
me p
me p
ms p
p"

# Test Case 8: Multiple Teleporter Chains
"XXXXXXXXX
XSX
X1XXXXX2X
XX
X3XXXXX4X
XX
X5XXXXXGX
XX
XXXXXXXXX

p
me p
ms p
ms p
me p
ms p
ms p
me p
p"

# Test Case 9: Edge Case - Start Next to Goal
"XXXXX
XSGXX
XXXXX

p
me p
p"

# Test Case 10: Ice Corner Navigation
"XXXXXXXXX
XSX
XIIIIIIIX
XIIX
XIXXXIX
XIIX
XIIIIIIGX
XXXXXXXXX

p
me p
ms p
ms p
ms p
ms p
me p
p"

# Test Case 11: Dead End Maze Navigation
"XXXXXXXXXXX
XSX
XXXXXXXXX
XXXX
XXXXXXX
XXXXX
XXXXXXX
XXXX
XXXXXXXXX
XGX
XXXXXXXXXXX

p
me p
me p
me p
ms p
ms p
ms p
ms p
me p
me p
me p
ms p
p"

# Test Case 12: Teleporter Loop
"XXXXXXXXX
XS12X
XX
X34X
XX
X56X
XG1X
X23X
X45X
X6X
XXXXXXXXX

p
me p
me p
me p
me p
me p
me p
ms p
ms p
ms p
ms p
ms p
ms p
mw p
mw p
mw p
mw p
mw p
p"

# Test Case 13: Ice Sliding with Direction Changes
"XXXXXXXXXXXXXXXXX
XSGX
XXXXXXXXXXXXXXX
XXIIIIIIIIIIIXX
XXIIIIIIIIIIIXX
XXIIIIIIIIIIIXX
XXIIIIIIIIIIIXX
XXXXXXXXXXXXXXX
XX
XXXXXXXXXXXXXXXXX

p
me p
me p
me p
ms p
me p
me p
me p
me p
me p
ms p
ms p
ms p
mw p
mw p
mw p
me p
p"

# Test Case 14: Narrow Path Navigation
"XXXXXXXXXXXXX
XSGX
XXXXXXXXXXX
XXXX
XXXXXXXXX
XXXXXX
XXXXXXX
XXXXXXX
XXXXXXX
XXXX
XXXXXXXXXXXXX

p
me p
me p
me p
me p
ms p
ms p
ms p
me p
me p
ms p
ms p
ms p
me p
p"

# Test Case 15: Boundary Teleporter
"XXXXXXX
1SX
XXXXXX1
XX
XXXXXXX
XGX
XXXXXXX

p
mw p
p"

# Test Case 16: Complex Mixed Features
"XXXXXXXXXXX
XSX1X
XXIXXXXXX
XIXX
XIIIXXXX
X2IIIXX
XXXIXXXXIXX
XIIX
XXXX2XXIX
X1IGX
XXXXXXXXXXX

p
me p
me p
ms p
ms p
ms p
me p
me p
ms p
ms p
mw p
mw p
ms p
ms p
me p
me p
me p
p"
)

# Create test files starting from number 4
for i in {0..15}; do
  file_num=$((i + 4))
  echo -e "${test_cases[i]}" > "test${file_num}.in"
  echo "Created test${file_num}.in"
done

echo "All test files have been created!"