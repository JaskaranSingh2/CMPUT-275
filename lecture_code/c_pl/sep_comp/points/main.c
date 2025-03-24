#include <stdio.h>
#include "point.h"

int main() {
  struct Point2D p1;
  p1.x = 3.6;
  p1.y = 5.2;
  struct Point2D p2;
  p2.x = 4.7;
  p2.y = 8.9;
  printPoint(p1);
  printf(" ");
  printPoint(p2);
  printf("\nDistance: %.2f\n", distance(p1, p2));
}
