#!/usr/bin/python3
import sys
readStdin = True
if len(sys.argv) > 1:
  readStdin = False
  for fname in sys.argv[1:]:
    print(f"DEBUG: Reading from file {fname}", file=sys.stderr)
    f = open(fname, "r")
    data = f.read()
    print(data, end="")

while readStdin:
  print(f"DEBUG: Reading from stdin", file=sys.stderr)
  line = sys.stdin.readline()
  if not line:
    break
  else:
    print(line, end="")


print("I'm finished now, there is no more input")
