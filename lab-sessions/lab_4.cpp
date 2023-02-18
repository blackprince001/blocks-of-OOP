#include <iostream>

class Quadrilateral {
   private:
    int x, y;

   public:
    Quadrilateral() : x(0), y(0) {}

    void set_values(const int &xVal, const int &yVal) {
        x = xVal;
        y = yVal;
    }

    inline int compute_area() { return x * y; }
};

void test_quadrilaterals() {
    Quadrilateral square, Rectangle;
    square.set_values(12, 12);
    Rectangle.set_values(12, 13);

    std::cout << square.compute_area() << "\n";
    std::cout << Rectangle.compute_area() << "\n";
}

int main() { test_quadrilaterals(); }