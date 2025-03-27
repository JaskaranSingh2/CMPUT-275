#include <iostream>


int main() {
  int n;
  int total = 0;
  for (std::cin >> n; !std::cin.fail(); std::cin >> n) {
    total = total + n;
  }
  std::cout << "The total was: " << total << std::endl;
}
