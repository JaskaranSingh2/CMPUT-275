#include "list.h"
#include <iostream>
using namespace std;

int main() {
  int c;
  List l;
  while (cin >> c) {
    l.push(c);
  }
  for (int i = 0; i < l.length(); ++i) {
    cout << l.ith(i) << endl;
  }
}
