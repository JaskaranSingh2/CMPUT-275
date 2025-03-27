#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  // mutates 2x the larger integer and 1/2 the smaller integer
  int &max = a < b ? b : a;
  int &min = a < b ? a : b;
  max = max*2;
  min = min/2;
  cout << max << " " << min << endl;;
}
