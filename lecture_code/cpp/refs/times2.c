#include <iostream>
using namespace std;
void times2(int &n) {
  n = n*2;
}

int main() {
  int x = 10;
  times2(x);
  cout << x << endl;
}
