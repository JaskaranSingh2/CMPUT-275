#include <iostream>
using namespace std;

int main() {
  /*
    You cannot "reseat" a reference, i.e. make it refer to a new piece
    of data, because a reference behaves in all instances like the data
    it refers to! Consider:
  */
  int x = 0;
  int y = 10;
  int &ref = x;
  ref = 5; // ref behaves as x, so x is now 5.
  cout << x << endl;
  ref = y; // Does this make ref refer to y?
  // NO! remember, a reference behaves as the thing it refers to
  // so this line is effectively the same as x = y;
  // so, x is now 10
  cout << x << endl;

  // Further confirmation that ref = y did not make our reference
  // refer to y:
  ref = 2;
  cout << y << endl; // still 10! ref refers to x for its whole life
}
