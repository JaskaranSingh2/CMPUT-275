#include "list.h"
#include <iostream>

using namespace std;


int main() {
  List l;
  l.addToFront(3).addToFront(2).addToFront(1);
  l = l;
  for (int i = 0; i < l.length(); ++i) cout << l.getIth(i) << " ";
  cout << endl;
}
