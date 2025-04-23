#include <iostream>
#include "list.h"
using namespace std;

int main() {
  List<int> l;
  int x;
  while (cin >> x) {
    l.push(x);
  }
  for (int i = 0; i < l.length(); ++i) {
    cout << l.ith(i) << endl;
  }
}
