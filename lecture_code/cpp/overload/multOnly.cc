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

Vec3D operator*(int scalar, Vec3D v) {
  return v*scalar;
}

int main() {
  Vec3D v;
  v.x = 1; v.y = 2; v.z = 3;
  Vec3D w = v*2;
  cout << w.x << " " << w.y << " " << w.z << endl;

  Vec3D u = 4*v;

  cout << u.x << " " << u.y << " " << u.z << endl;
}
