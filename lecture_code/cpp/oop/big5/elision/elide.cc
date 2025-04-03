#include <iostream>
using namespace std;

int global = 0;

struct Foo {
  int x, y;
  Foo(int x, int y) : x{x}, y{y} {
    global = global + 1;
    cout << "int param ctor called" << endl;
  }
  Foo(const Foo &o) : x{o.x}, y{o.y} {
    global = global + 1;
    cout << "copy ctor called" << endl;
  }
  Foo(Foo &&o) : x{o.x}, y{o.y} {
    global = global + 1;
    cout << "move ctor called" << endl;
  }
};

Foo makeFoo(int n) {
  Foo ret{n*2, n/2};
  return ret;
}
int main() {
  Foo f{makeFoo(5)};
  cout << global << endl;
}
