#include <stdio.h>
#include <math.h>

struct Point2D {
  float x, y;
};


float distance(struct Point2D p1, struct Point2D p2) {
  float xDelta = p1.x - p2.x;
  float yDelta = p1.y - p2.y;
  float xsq = xDelta*xDelta;
  float ysq = yDelta*yDelta;
  return sqrt(xsq+ysq);
}

void printPoint(struct Point2D p1) {
  printf("(%.2f, %.2f)", p1.x, p1.y);
}

