#include <iostream>

class List {
  struct Node {
    int data;
    Node *next;
    Node(int data, Node *next);
    Node(const Node &o);
    ~Node();
  };
  int len;
  Node *head;
  void swap(List &o);
 public:
  List(); // Default Constructor
  ~List(); // Destructor
  List(const List &o); // Copy Constructor
  List(List &&o); // Move constructor
  List &operator=(const List &o); // Copy assignment operator
  List &operator=(List &&o); // Move assignment operator
  int ith(int i);
  void setIth(int i, int elem);
  int length();
  List &addToFront(int data);
  friend std::ostream& operator<<(std::ostream &, const List &);
};
