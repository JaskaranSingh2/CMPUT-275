#include <iostream>
// You should generally never use
// using namespace in a header file.
// e.g. in a header file you should not write
// using namespace std;

// Because including a header simply pastes the code in the client
// programmer's file, if you write using namespace std; for example
// in your header, then the client programmer who wants to use
// your library is also forced to use namespace std; However,
// They may have had definitions whose name clashed with
// standard library definitions, and so they purposefully chose
// not to pull those definitions out of the std namespace into
// their global namespace, but now you have forced that on them.


class List {
  // Node here is a private nested class
  // It's actual name is the Node class of the
  // List class, i.e. List::Node
  // Since it is private, only members of List
  // can use this data type.
  struct Node {
    int data;
    Node *next;
    Node(int data, Node *next) : data{data}, next{next} {}
    ~Node();
    Node(const Node &other);
  };
  int len;
  Node *head;
  void swap(List &other);
 public:
  List() : len{0}, head{nullptr} {} // Default constructor
  List &operator=(const List &other); // Copy assignment operator
  List(const List &other); // Copy constructor
  ~List(); // Destructor
  List &addToFront(int n);
  int length() { return len; }
  void setIth(int i, int val);
  int getIth(int i) const;

};
