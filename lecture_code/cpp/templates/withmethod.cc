#include <iostream>
#include <string>
using namespace std;
emplate <typename T>
void foo(T a) {
  cout << a.bar() << endl;
}

struct Friend {
  std::string bar() {
    return "friend";
  }
};

struct Enemy {
  std::string bar() {
    return "enemy";
  }
};

int main() {
  foo(Friend{});
  foo(Enemy{});
}
