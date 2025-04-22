#include <iostream>
using namespace std;

int main() {
  const int x = 5;
  int a, b;
  cin >> a >> b;
  {
    int &&rval = a+b;
    const int &l = x;
    rval = 2;
  }
}
