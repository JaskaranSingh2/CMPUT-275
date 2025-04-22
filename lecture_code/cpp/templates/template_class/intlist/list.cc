#include "list.h"
#include <utility>
List::List() : len{0}, cap{4}, arr{new int[cap]} {}
List::List(const List &o) : len{o.len}, cap{o.cap}, arr{new int[cap]} {
  for (int i = 0; i < len; ++i) arr[i] = o.arr[i];
}
List::List(List &&o) : len{o.len}, cap{o.cap}, arr{o.arr} {
  o.arr = nullptr;
  o.len = 0;
  o.cap = 0;
}

void List::swap(List &o) {
  std::swap(len, o.len);
  std::swap(cap, o.cap);
  std::swap(arr, o.arr);
}

List &List::operator=(const List &o) {
  List tmp{o};
  swap(tmp);
  return *this;
}
List &List::operator=(List &&o) {
  swap(o);
  return *this;
}

List::~List() {
  delete[] arr;
}

void List::push(int elem) {
  if (len == cap) {
    int *newArr = new int[cap*2];
    for (int i = 0; i < len; ++i) {
      newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    cap = cap*2;
  }
  arr[len++] = elem;
}

int List::pop(int i) {
  int ret = arr[i];
  for (int j = i; j < len-1; ++j) {
    arr[j] = arr[j+1];
  }
  --len;
  return ret;
}

int List::ith(int i) {
  return arr[i];
}

void List::setIth(int i, int elem) {
  arr[i] = elem;
}

List &List::operator++() {  // Prefix ++
  // Let's say that increment on a list increments
  // each item in it.
  for (int i = 0; i < len; ++i) {
    ++arr[i];
  }
  return *this;
}

List List::operator++(int) {  // Postfix++
  List temp{*this};
  ++*this;
  return temp;
}
