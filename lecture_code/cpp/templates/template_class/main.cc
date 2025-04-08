#include "list.h"
#include <iostream>
using namespace std;

int main() {
  char c;
  List l;
  while (cin >> c) {
    l.addToFront(c);
  }
  for (int i = 0; i < l.length(); ++i) {
    cout << l.ith(i) << endl;
  }
}
