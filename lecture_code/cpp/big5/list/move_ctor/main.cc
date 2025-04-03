#include "list.h"
#include <iostream>
using namespace std;

List inc(List l) {
  // Takes in list and returns an incremented copy of it.
  for (int i = 0; i < l.length(); ++i) {
    l.setIth(i, l.getIth(i) + 1);
  }
  return l;
}

int main() {
  List l1;
  l1.addToFront(1).addToFront(2).addToFront(3);
  List l2{inc(l1)};
}
