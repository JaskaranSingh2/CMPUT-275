#include <iostream>
using namespace std;
struct Student {
  int crsCount;
  float gpa;
  const int sID;
  Student(int crsCount, float gpa, int id) : crsCount{crsCount}, gpa{gpa}, sID{id} {
  }
};


int main() {
  Student s{5, 3.4, 111111};
  Student s2{4, 1.9, 2222222};
  cout << s.sID << endl;
  cout << s2.sID << endl;
}
