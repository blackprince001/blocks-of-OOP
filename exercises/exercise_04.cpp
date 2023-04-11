#include <iostream>
// type members of a class
// both classes are pratically the same.
// but with the class, you have the luxury to change the type of Coordinate
// whenever you please. eg from Float to std::Complex easily compared to how
// it would be done in the first class.

class NormalPoint {
 public:
  float x;
  float y;
};

class TypedPoint {
 public:
  typedef float Coordinate;
  Coordinate x;
  Coordinate y;
};

void accessing_type_members() {
  TypedPoint orthoPoint;
  // we can reuse a type member defined in a class by using the scope
  // resolution when the access specifier for that type member is public or
  // protected.

  // Note type member can be anything, from a struct to a generic data type
  TypedPoint::Coordinate someX = orthoPoint.x;
  TypedPoint::Coordinate someY = orthoPoint.y;
}

int main() {}