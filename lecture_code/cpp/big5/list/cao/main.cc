#include "list.h"
#include <iostream>
using namespace std;

int main() {
  List l;
  l.addToFront(3).addToFront(2).addToFront(1);
  // The "Daisy chaining" of our method calls above is possible due to the fact
  // that addToFront returns a reference to the list that was added to. Is this
  // necessary? No, it's perfectly fine for that method to return void and the
  // caller must make the calls separately, in fact it may even be easier to read
  // This is just something you may like to do in the future so here we've provided
  // an example of it.
  // l.addToFront(3);
  // l.addToFront(2);
  // l.addToFront(1);

  for (int i = 0; i < l.length(); ++i) {
    cout << l.getIth(i) << endl;
  }
  List p = l;
  p.setIth(0, 5);
  p.addToFront(-1);
  cout << "Printing p first:" << endl;
  for (int i = 0 ; i < p.length(); ++i) cout << p.getIth(i) << endl;
  p.setIth(0, -20);
  cout << "Printing p second:" << endl;
  for (int i = 0 ; i < p.length(); ++i) cout << p.getIth(i) << endl;
  cout << "Printing l:" << endl;
  for (int i = 0; i < l.length(); ++i) cout << l.getIth(i) << endl;

  List l3;
  l3.addToFront(5).addToFront(6);
  l3 = p;
  l3.setIth(0, 42);
  cout << "Printing l3:" << endl;
  for (int i = 0; i < l3.length(); ++i) cout << l3.getIth(i) << endl;

  cout << "Printing p:" << endl;
  for (int i = 0; i < p.length(); ++i) cout << p.getIth(i) << endl;

}
