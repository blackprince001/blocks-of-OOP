// Constructors, Destructors, propagating values; Copying and Moving
// Copying copies the values of an existing source object to a destination
// object of the same type without compromise to the source object Moving on the
// other hand copies the values from the source to the destination but does not
// guarantee the source wont be changed after the move.

// Classes with Unspecified Copy Constructors are automatically assigned one
// same goes for Destructors if there are no builtin type member functions

// Illustations below;
#include <iostream>

class Vector {
 private:
  double x_;
  double y_;

 public:
  Vector() : x_(0), y_(0){};  // our default constructor
  Vector(double x, double y) : x_(x), y_(y){};
  Vector(const Vector &other) {  // Copy constructor
    x_ = other.x_;
    y_ = other.y_;
  };
  Vector(Vector &&other) {  // Move constructor
    x_ = other.x_;
    y_ = other.y_;
  }
};

class TextWidget {
 private:
  char *buf_size_ptr;

 public:
  TextWidget(int size) { buf_size_ptr = new char[size]; }
  ~TextWidget() {
    delete[] buf_size_ptr;
  }  // Destructor deletes allocated memory for buffer string
};

Vector move_from_local() {
  Vector a(12, 12);
  return a;  // since we cannot return the local scope value of this variable at
             // runtime, we utilize a move constructor to copy the content of
             // this a object to its destination.
};

int main() {
  Vector vOrigin;
  Vector a1(10, 10);
  Vector aOrigin(vOrigin);   // Copies the values of vOrigin to aOrigin
  Vector bOrigin = vOrigin;  // Also invokes the copy constructor not to be
                             // confused with the assignment operator
  // the assignment operator expected a prexisting object to which an assignment
  // operation would be done on which is very different from the one above.

  Vector cOrigin = move_from_local();  // calls the move constructor.

  TextWidget name_box(121234123);
  // our namebox should hold 121234123 characters max
  // this means the allocated memory size for 14 characters will be deleted when
  // the program ends the lifetime of the object ends then too

  std::cin.get();
}