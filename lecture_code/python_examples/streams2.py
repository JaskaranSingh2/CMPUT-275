import sys
# This program expects input of the form
# num
# text
# num
# text
#  ....
# where each num is 1 or 2, 1 means print the following line to stdout
# 2 means print the following line to stderr
while True:
  num = sys.stdin.readline()
  if not num:
    break
  num = int(num)
  line = sys.stdin.readline()
  if not line:
    break
  if num == 1:
    print(line, end="")
  if num == 2:
    print(line, end="", file=sys.stderr)
