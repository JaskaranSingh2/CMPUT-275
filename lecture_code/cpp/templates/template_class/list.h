#ifndef LIST_H_
#define LIST_H_

class List {
  int len, cap;
  int *arr;
 public:
  List();
  List(const List &);
  List(List &&);
  List &operator=(const List &);
  List &operator=(List &&);

  void push(int elem); // Add to back
  int pop(int i); // Removes element at index i
  int ith(int i);
  int setIth(int i, int elem);
};

#endif
