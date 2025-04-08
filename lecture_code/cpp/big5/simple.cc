#include <iostream>
using namespace std;

// This is not a full ADT since the client programmer
// is going to know about the implementation, and
// the fields are public. This is
// a node that effectively implements a linked list.
struct Node {
  int data;
  Node *next;
  Node(int data, Node *next) : data{data}, next{next} {}
};

int main() {
  // Aside - in C++ we use the definition nullptr for
  // the null pointer instead of NULL. It will always
  // type match which is not true for NULL.
  Node *p = new Node{1, new Node{2, new Node{3, nullptr}}};
  for (Node *cur = p; cur; cur = cur->next) {
    cout << cur->data << " ";
  }
  cout << endl;
}
