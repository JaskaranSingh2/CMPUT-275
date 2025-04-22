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
};

#endif
