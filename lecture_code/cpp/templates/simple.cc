#include <iostream>
using namespace std;

struct Foo {
  int x, y;
  bool operator>(const Foo &o) {
    return x > o.x || x == o.x && y > o.y;
  }
};

ostream &operator<<(ostream & out, const Foo &rhs) {
  return out << "[" <<rhs.x << ", " << rhs.y << "]" << endl;
}

template <typename T>
T mymax(T a, T b) {
  return a > b ? a : b;
}

int main() {
  int a = 10, b = 5;
  char c1 = 'a', c2 = 'A';
  Foo f1{1, 5};
  Foo f2{3, 1};
  cout << mymax(a,b) << endl;
  //cout << mymax<int>(a,b) << endl;
  cout << mymax(c1, c2) << endl;
  //cout << mymax<char>(c1, c2) << endl;
  #ifndef OMITFOO
  cout << mymax(f1, f2) << endl;
  #endif
  //cout << mymax<Foo>(f1, f2) << endl;
}


