#ifndef LIST_H_
#define LIST_H_
// This type is now a template type.
template <typename T>
class List {
  int len, cap;
  T *arr;
  void swap(List &o);
 public:
  List();
  List(const List &);
  List(List &&);
  List &operator=(const List &);
  List &operator=(List &&);
  ~List();
  void push(T elem); // Add to back
  T pop(int i); // Removes element at index i
  T ith(int i);
  void setIth(int i, T elem);
  int length() { return len; }

  T &operator[](int index); // Overloaded index operator
};

#include "list.h"
#include <utility>

template <typename T>
List<T>::List() : len{0}, cap{4}, arr{new T[cap]} {}

template <typename T>
List<T>::List(const List &o) : len{o.len}, cap{o.cap}, arr{new T[cap]} {
  for (int i = 0; i < len; ++i) arr[i] = o.arr[i];
}

template <typename T>
List<T>::List(List &&o) : len{o.len}, cap{o.cap}, arr{o.arr} {
  o.arr = nullptr;
  o.len = 0;
  o.cap = 0;
}

template <typename T>
void List<T>::swap(List &o) {
  std::swap(len, o.len);
  std::swap(cap, o.cap);
  std::swap(arr, o.arr);
}

template <typename T>
List<T> &List<T>::operator=(const List &o) {
  List tmp{o};
  swap(tmp);
  return *this;
}

template <typename T>
List<T> &List<T>::operator=(List &&o) {
  swap(o);
  return *this;
}

template <typename T>
List<T>::~List() {
  delete[] arr;
}

template <typename T>
void List<T>::push(T elem) {
  if (len == cap) {
    T *newArr = new T[cap*2];
    for (int i = 0; i < len; ++i) {
      newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    cap = cap*2;
  }
  arr[len++] = elem;
}

template <typename T>
T List<T>::pop(int i) {
  T ret = arr[i];
  for (int j = i; j < len-1; ++j) {
    arr[j] = arr[j+1];
  }
  --len;
  return ret;
}


template <typename T>
T List<T>::ith(int i) {
  return arr[i];
}

template <typename T>
void List<T>::setIth(int i, T elem) {
  arr[i] = elem;
}

template <typename T>
T &List<T>::operator[](int i) {
  return arr[i];
}
#endif
