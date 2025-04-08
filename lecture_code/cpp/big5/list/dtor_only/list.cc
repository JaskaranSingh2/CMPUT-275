#include "list.h"


List::Node::~Node() {
  delete next;
}

List::~List() { delete head; }


List &List::addToFront(int n) {
  head = new Node{n, head};
  ++len;
  return *this;
}

void List::setIth(int i, int val) {
  // Assumes caller has checked i is less than length
  Node *cur = head;
  for (int j = 0; j < i; ++j, cur = cur->next);
  cur->data = val;
}

int List::getIth(int i) const {
  Node *cur = head;
  for (int j = 0; j < i; ++j, cur = cur->next);
  return cur->data;
}


/*
// This implementation works, and it's not WRONG to write it
// like this, but we're going to write our other definition
// to observe some helpful behaviour of C++.
List::~List() {
  Node *cur = head;
  while (cur) {
    Node *next = cur->next;
    delete cur;
    cur = next;
  }
}
*/
