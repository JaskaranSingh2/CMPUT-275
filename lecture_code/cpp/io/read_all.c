#include <iostream>

int main() {
  int total = 0;
  int n;
  while (!std::cin.eof()) {
    if (std::cin >> n) total += n;
    else {
      std::cin.clear();
      std::cin.ignore();
    }
  }
  std::cout << total << std::endl;
}
