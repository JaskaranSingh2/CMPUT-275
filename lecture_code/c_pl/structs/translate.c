#include <stdio.h>

struct Rect {
  int x, y, w, h;
};

void printRect(struct Rect r1) {
  printf("Rect size %dx%d located at (%d, %d)\n", r1.w, r1.h, r1.x, r1.y);
}

void translate(struct Rect *r, int xd, int yd) {
  r->x = r->x + xd;
  r->y = r->y + yd;
}


int main() {
  struct Rect r = {.x=5, .y=10, .w=3, .h=7};
  printRect(r);
  translate(&r, 5, 3);
  printRect(r);
}
