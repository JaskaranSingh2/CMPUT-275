#include <iostream>
using namespace std;

struct Vec3D {
  int x, y, z;
};

Vec3D operator*(Vec3D v, int scalar) {
  Vec3D ret;
  ret.x = v.x*scalar;
  ret.y = v.y*scalar;
  ret.z = v.z*scalar;
  return ret;
}

Vec3D operator+(Vec3D lhs, Vec3D rhs) {
  Vec3D ret;
  ret.x = lhs.x + rhs.x;
  ret.y = lhs.y + rhs.y;
  ret.z = lhs.z + rhs.z;
  return ret;
}

int operator*(Vec3D lhs, Vec3D rhs) {
  return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
}

int main() {
  Vec3D v;
  v.x = 1; v.y = 2; v.z = 3;
  Vec3D w = v*2;
  Vec3D u = w+v;
  cout << w.x << " " << w.y << " " << w.z << endl;
  // cout << w << endl;
  cout << u.x << " " << u.y << " " << u.z << endl;

  cout << v*w << endl;
}
