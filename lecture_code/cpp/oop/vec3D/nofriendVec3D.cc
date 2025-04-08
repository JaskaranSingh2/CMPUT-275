#include <iostream>
using namespace std;

class Vec3D {
  int x, y, z;
 public:
  Vec3D(int x, int y, int z) : x{x}, y{y}, z{z} {};
  // When overloading an operator as a method, the object
  // pointed at by the this pointer is implicitly the first
  // operand.
  // So, we can only provide 0 or 1 parameters for operator+
  // 0 if we want to define the unary operator +
  // 1 if we want to the define binary operator+, in this case
  // the parameter is the right hand side (second operand).
  Vec3D operator+(const Vec3D &rhs) {
    Vec3D ret{x+rhs.x, y+rhs.y, z+rhs.z};
    return ret;
  }

};

int Vec3D::prod() {
  return v.x*v.y*v.z;
}

/*
ostream &Vec3D::operator<<(ostream &out, const Vec3D &v) {
  return out << '[' << v.x << ',' << v.y << ',' << v.z << ']';
}
*/


int main() {
  Vec3D v{1, 2, 3};
  Vec3D w{8, -1, 2};
  Vec3D q = v+w;
  //cout << v << "+" << w << "=" << q  << endl;
}


