#include <iostream>

using namespace std;


void foo(int &n) {
  cout << "lvalue ref to int " <<  n << endl;
}

void foo(int &&n) {
  cout << "rvalue ref to int " << n << endl;
}

int main() {
  int x = 1;
  int y = 2;
  foo(x);
  foo(y);
  foo(x+y);
}
