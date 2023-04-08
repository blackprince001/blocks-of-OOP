#include <iostream>

class CPolygon {
 protected:
  int height, width;

 public:
  void set_values(int h, int w) {
    height = h;
    width = w;
  }

  virtual int area() { return width * height; }
};

class CRectangle : public CPolygon {};

class CTriangle : public CPolygon {
 public:
  virtual int area() { return (width * height) / 2; }
};

int main() {
  CRectangle rect;
  CTriangle tri;

  rect.set_values(10, 5);
  tri.set_values(10, 5);

  std::cout << "Area of Rectangle: " << rect.area() << "\n";
  std::cout << "Area of Triangle: " << tri.area() << "\n";
}