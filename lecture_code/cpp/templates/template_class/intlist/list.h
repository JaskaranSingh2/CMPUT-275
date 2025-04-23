#ifndef LIST_H_
#define LIST_H_

class List {
  int len, cap;
  int *arr;
  void swap(List &o);
 public:
  List();
  List(const List &);
  List(List &&);
  List &operator=(const List &);
  List &operator=(List &&);
  ~List();
  void push(int elem); // Add to back
  int pop(int i); // Removes element at index i
  int ith(int i);
  void setIth(int i, int elem);
  int length() { return len; }

  List &operator++(); // Prefix increment operator
  List operator++(int); // Postfix increment operator
};

#endif
