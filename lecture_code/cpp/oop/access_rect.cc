#include <iostream>
using namespace std;

struct Rect {
  private:
    int x, y, w, h;
  public:
    Rect(int x, int y, int w, int h) : x{x}, y{y}, w{w > 0 ? w : 1}, h{h > 0 ? h : 1} {}
    Rect() : x{0}, y{0}, w{1}, h{1} {}
};

int main() {
  Rect r{1, 2, 4, 6};
  Rect q;
  r.w = -1;
  //cout << "Rectangle located at " << r.x << "," << r.y << " with width " << r.w << " and height " << r.h << endl;
}
