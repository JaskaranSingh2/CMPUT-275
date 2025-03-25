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

ostream& operator<<(ostream &out, const Vec3D &v) {
  return out << "[" << v.x << " " << v.y << " " << v.z << "]";
}

istream& operator>>(istream &in, Vec3D &v) {
  return in >> v.x >> v.y >> v.z;
}

int main() {
  Vec3D v;
  v.x = 1; v.y = 2; v.z = 3;
  Vec3D w = v*2;
  Vec3D u = w+v;
  cout << w << endl;
  cout << u << endl;
  cin >> w;
  if (!cin) {
    cout << "Failed to read into vector w, do something about it!" << endl;
  }
  cout << w << endl;
  cout << v*w << endl;
}
