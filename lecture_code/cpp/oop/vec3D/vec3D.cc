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
  Vec3D operator+(const Vec3D &rhs) const;
  friend ostream &operator<<(ostream &, const Vec3D &);

  // The same is true for any operator, so any operator we want
  // to define where the left hand side is not the class type itself
  // must be defined outside of the class, and may need to be a friend.
  // This multiplication operator is defined between
  // a left hand operand of a Vec3D (pointed at by the implicit this)
  // and a right hand operand of an integer scalar
  // Once again, if we want to define an operator where the integer
  // scalar is first, it cannot be a member.

  // The Vec3D that we are multiplying, should not be mutated by multiplication
  // That should just create a new Vec3D. How do we promise that we will not
  // mutate the object pointed at by the this parameter? That is, how do we
  // mark the object pointed at by this as "const"?
  Vec3D operator*(int scalar) const;
};

Vec3D Vec3D::operator*(int scalar) const {
  return Vec3D{x*scalar, y*scalar, z*scalar};
}

Vec3D operator*(int scalar, const Vec3D &rhs) {
  return rhs*scalar;
}

Vec3D Vec3D::operator+(const Vec3D &rhs) const {
  Vec3D ret{x+rhs.x, y+rhs.y, z+rhs.z};
  return ret;
}

ostream &operator<<(ostream &out, const Vec3D &v) {
  return out << '[' << v.x << ',' << v.y << ',' << v.z << ']';
}


int main() {
  Vec3D v{1, 2, 3};
  Vec3D w{8, -1, 2};
  Vec3D q = v+w;
  cout << v << "+" << w << "=" << q  << endl;
  cout << v*3 << endl;
  cout << 3*v << endl;
}


