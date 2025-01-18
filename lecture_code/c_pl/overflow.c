// Try compiling this program with different return values below 256 and above
// and see what you get when you run the program and access the exit code!
// Note: Our Linux kernel represents exit statuses with an 8-bit fixed width integer.
// Try to understand why you get the reuslts you do!
int main() {
  return 257;
}
