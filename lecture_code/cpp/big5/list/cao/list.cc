#include "list.h"
#include <utility>
// Utility header has many useful small little functions
// The one we want right now is... std::swap
// which swaps two plain old data types without a copy


void List::swap(List &other) {
/*
  // Absolutely can write this function this way,
  // but might as well use std::swap
  int myData = data;
  Node *myHead = head;
  data = other.data;
  head = other.head;
  other.head = myHead;
  other.data = myData;
*/
  std::swap(len, other.len);
  std::swap(head, other.head);
}

List::Node::~Node() {
  delete next;
}

List::Node::Node(const Node &other) : data{other.data}, next{other.next ? new Node{*other.next} : nullptr} {}

List::~List() { delete head; }

List::List(const List &other) : len{other.len}, head{other.head ? new Node{*other.head} : nullptr}
{}

List &List::operator=(const List &other) {
  List tmp{other}; // Invoke our copy constructor to copy other
  swap(tmp); // Swap ourselves with tmp
  return *this;
}


/*
// This copy assginment operator works, and is not bad!
// However, the copy-and-swap idiom is simpler and reuses
// the code we already wrote in the copy constructor, so
// has less chance of a bug if we've already guaranteed our
// copy constructor works correctly!
List &List::operator=(const List &other) {
  if (this == &other) return *this;
  Node *oldHead = head;
  head = other.head ? new Node{*other.head} : nullptr;
  // Once we have successfully assigned, then we should free the old head.
  delete oldHead;
  len = other.len;
  return *this;
}
*/


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
