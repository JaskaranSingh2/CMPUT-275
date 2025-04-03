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

  // Note: while we /can/ define this operator as
  // a member function, it is not wise to do so.
  // Because the first operand is implicitly the object
  // itself, so this is defining the << operator where
  // the left hand side is a Vec3D and the right hand side
  // is a ostream.
  // So to use this you would have to write something like...
  // v << cout;
  ostream &operator<<(ostream& out) {
    out << "[" << x << ", " << y << ", " << z << "]";
    return out;
  }

};



int main() {
  Vec3D v{1, 2, 3};
  Vec3D w{8, -1, 2};
  Vec3D q = v+w;
  // If we overload the operator as a method, then this
  // is the behaviour we end up with because the stream
  // must be the right hand side operand when printing
  // our data type...
  // this is not good
  (q << ((w << ((v << cout) << "+")) << "=")) << endl;
  //cout << v << "+" << w << "=" << q  << endl;
}


