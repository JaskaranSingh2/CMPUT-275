#include <iostream>
using namespace std;

int fib(int n) {
  if (n == 0 || n == 1) return 1;
  return fib(n-1) + fib(n-2);
}

struct Bar {
  int len;
  int *arr;

  Bar() : len{40}, arr{new int[len]} {
    // A default constructed bar is an array of 100 ints
    for (int i = 0; i < len; ++i) {
      arr[i] = fib(i);
    }
  }

  Bar(int n) : len{n}, arr{new int[len]} {
    for (int i = 0; i < len; ++i) {
      arr[i] = fib(i);
    }
  }
};

struct Foo {
  int len;
  Bar b;
  #ifndef USEMIL
  Foo(int n)  {
    len = n;
    b = Bar{len};
  }
  #else
  Foo(int n) : len{n}, b{len} {}
  #endif
};

int main() {
  Foo f{5};
}
