#include <iostream>
#include <cassert>
using namespace std;

struct Rect {
  int x, y, w, h;

  Rect(int x, int y, int w, int h) {
    assert(w > 0); assert(h > 0);
    this->x = x;
    this->y = y;
    if (w <= 0) {
      cout << "Initializing rect with width <= 0, this is error setting it to 1" << endl;
      w = 1;
    }
    this->w = w;
    if (h <= 0) {
      cout << "Initializing rect with height <= 0, this is error setting it to 1" << endl;
      h = 1;
    }
    this->h = h;
  }

  #ifdef DEFAULTCTOR
  Rect() {
    cout << "Default ctor called" << endl;
    x = 0; y = 0;
    w = 1; h = 1;
  }
  #endif

  int area() {
    // In methods identifiers that match with our
    // objects fields implicitly resolve to
    // this->identifier
    // (Unless otherwise shadowed by more recent scope)
    return w*h;
  }

  Rect &bigger(Rect &other) {
    if (w*h > other.w*other.h) {
      return *this;
    } else {
      return other;
    }
  }

  void setHeight(int h) {
    // In this function, "h" means the parameter h.
    // if we want to access our objects field h we must
    // now explicitly say this->h
    this->h = h;
  }
};


int main() {
  // The following definitions will become illegal
  // when we add our constructor with 4 ints.
  #ifdef BADCONSTRUCT
  Rect A{0, 0}; // leaving out width and height
  Rect B{0, 0, -3}; // leaving out height
  Rect C; // leaving out everything
  Rect D{0}; // Leaving out y, w, h
  #endif
  // end illegal constructions
  // starts here
  Rect r1{0, 0, 5, 3};
  Rect r2{0, 0, 2, 2};
  cout << r1.area() << endl;
  cout << r2.area() << endl;
  Rect &larger = r1.bigger(r2);
  cout << "The larger area is: " << larger.area() << endl;
  larger.setHeight(1);
  cout << r1.area() << endl;
  Rect x; // x needs to be default constructed here
  // Which for our program means we need the compilation
  // flag DEFAULTCTOR
  Rect r3{5, 2, -10, 2};
  cout << "The area of r3: " << larger.area() << endl;
}
