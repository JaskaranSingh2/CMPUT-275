#include "list.h"
#include <utility>
#include <cassert>
#include <iostream>
using namespace std;

List::Node::Node(int data, Node *next) : data{data}, next{next} {};
List::Node::Node(const Node &o) : data{o.data}, next{o.next ? new Node{*o.next} : nullptr} {}
List::Node::~Node() {
  delete next;
}


void List::swap(List &o) {
  std::swap(len, o.len);
  std::swap(head, o.head);
}

List::List() : len{0}, head{nullptr} {}

List::~List() {
  delete head;
}

List::List(const List &o) : len{o.len}, head{o.head ? new Node{*o.head} : nullptr} {
  #ifdef DEBUG
  cout << "List Copy Ctor Called" << endl;
  #endif
}

List::List(List &&o) : len{o.len}, head{o.head} {
  #ifdef DEBUG
  cout << "List Move Ctor Called" << endl;
  #endif
  o.len = 0;
  o.head = nullptr;
}

List &List::operator=(const List &o) {
  #ifdef DEBUG
  cout << "List CAO called" << endl;
  #endif
  List tmp{o};
  swap(tmp);
  return *this;
}

List &List::operator=(List &&o) {
  #ifdef DEBUG
  cout << "List MAO called" << endl;
  #endif
  swap(o);
  return *this;
}

List &List::addToFront(int data) {
  head = new Node{data, head};
  ++len;
  return *this;
}

int List::ith(int i) {
  assert(i < len);
  Node *cur = head;
  for (int j = 0; j < i; ++j, cur=cur->next);
  return cur->data;
}

void List::setIth(int i, int elem) {
  assert (i < len);
  Node *cur = head;
  for (int j = 0; j < i; ++j, cur=cur->next);
  cur->data = elem;
}

int List::length() { return len; }


ostream &operator<<(ostream &out, const List &l) {
  if (l.len == 0) return out;
  List::Node *cur = l.head;
  out << cur->data;
  for (cur = cur->next; cur; cur = cur->next) {
    out << " " << cur->data;
  }
  return out;
}
