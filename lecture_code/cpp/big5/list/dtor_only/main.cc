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
  // list L is 1 2 3
  // So list P should become 1 2 3 here
  List p = l;
  // List p should be come 5 2 3 here
  // BUT! We observe that this call to set ith mutates
  // my original list l as well... that doesn't seem good!
  p.setIth(0, 5);
  // List p should become -1 5 2 3 here
  // This /DOESN'T/ mutate my original list l... why does
  // getIth mutate it while addToFront doesn't? Either the
  // lists should be aliases completely or not at all!
  p.addToFront(-1);
  cout << "Printing p first:" << endl;
  for (int i = 0 ; i < p.length(); ++i) cout << p.getIth(i) << endl;
  // Even weirder, we observe that this setIth call DOESN'T mutate
  // the original list l, while the previous setIth call did.
  // Once again, either our objects should be total aliases for
  // one another, or they should be completely distinct lists
  // What does the client programmer likely want here? Most likely
  // if they're creating a new list they want a completely brand new
  // list with no aliasing, if they wanted aliasing they could just
  // use a reference!
  p.setIth(0, -20);
  cout << "Printing p second:" << endl;
  for (int i = 0 ; i < p.length(); ++i) cout << p.getIth(i) << endl;
  cout << "Printing l:" << endl;
  // List L should still be 1 2 3, we the client programmer have
  // not changed it!
  for (int i = 0; i < l.length(); ++i) cout << l.getIth(i) << endl;
}
