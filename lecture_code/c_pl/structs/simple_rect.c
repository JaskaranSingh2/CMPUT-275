#include <stdio.h>

struct Rect {
  int x, y, w, h;
};


int main() {
  struct Rect r1;
  r1.x = 5;
  r1.y = 10;
  r1.w = 2;
  r1.h = 4;
  printf("%lu\n", sizeof(r1));
}
