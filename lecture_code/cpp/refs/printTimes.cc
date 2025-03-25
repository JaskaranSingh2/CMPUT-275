#include <iostream>
using namespace std;
void printNTimes1(int &n, int times) {
  for (int i = 0; i < times; ++i) {
    cout << n << endl;
  }
}

void printNTimes2(const int &n, int times) {
  for (int i = 0; i < times; ++i) {
    cout << n << endl;
  }
}


int main() {
  int x = 3;
  printNTimes1(x, 5);

  // printNTimes1(5, x); Won't compile! Can't pass 5 for lvalue ref param
  printNTimes2(5, x);
}
