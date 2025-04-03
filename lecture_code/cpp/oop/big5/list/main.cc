#include "list.h"
#include <iostream>

using namespace std;


List inc(List l) {
  for (int i = 0; i < l.length(); ++i) {
    l.setIth(i, l.ith(i)+1);
  }
  return l;
}

int main() {
  List l;
  l.addToFront(1).addToFront(2).addToFront(3);
  cout << l << endl;
  List l2 = inc(l);
  cout << l2 << endl;
  l2 = inc(l2);
  cout << l2 << endl;
  l2 = l;
  cout << l2 << endl;
}
