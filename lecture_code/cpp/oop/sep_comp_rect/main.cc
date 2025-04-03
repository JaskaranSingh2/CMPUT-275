#include "rect.h"
#include <iostream>
using namespace std;

int main() {
  Rect r1{1, 2, 3, 4};
  Rect r2;
  cout << r1.area() << endl;
  cout << r2.area() << endl;
}
