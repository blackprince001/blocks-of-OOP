/* Author: @blackprince001 */
#include <iostream>

using std::cin;
using std::cout;

// defining the abstract CPolygon Parent class
class CPolygon {
public:
  void setValues(float w, float h) {
    width = w;
    height = h;
  }
  virtual inline float area() = 0;
  virtual void printArea() = 0;

protected:
  float width{};
  float height{};
};

// defining the abstract CRectangle Derived Class
class CRectangle : public CPolygon {
public:
  inline float area() override {
    return (height * width);
  } // define area function for Rectangle
  void printArea() override {
    cout << "Area of Rectangle is : " << this->area() << " units squared.\n";
  }
};

// defining the abstract CTriangle Derived class
class CTriangle : public CPolygon {
public:
  inline float area() override {
    return 0.5f * (height * width);
  } // define area function for Triangle
  void printArea() override {
    cout << "Area of Triangle is : " << this->area() << "  units squared.\n";
  }
};

class CSquare : public CPolygon {
public:
  float area() {
    // define the area funtion of the Square class
    // Squares must have equal lengths hence function will return -1 if the
    // height and width are not equal
    if (height == width)
      return (height * width);
    else
      return -1;
  }
  virtual void printArea() {
    cout << "Area of Square is : " << this->area() << "  units squared.\n";
  }
};

// test the Rectangle class by creating arbitrary objects
void testRectClass() {
  CRectangle newRect;
  newRect.setValues(10, 12);
  newRect.printArea();
}

// test the Square class by creating arbitrary objects
void testSquareClass() {
  CSquare newSquare;
  newSquare.setValues(10, 10);
  newSquare.printArea();

  CSquare anotherSquare;
  anotherSquare.setValues(11, 10);
  anotherSquare.printArea();
}

// test the Triangle class by creating arbitrary objects
void testTriangleClass() {
  CTriangle newtri;
  newtri.setValues(10, 12);
  newtri.printArea();
}

enum PolygonType {
  Rectangle,
  Triangle,
  Square,
};

int main() {
  // testing the derived classes of `CPolygon` with arbitrary values
  testRectClass();
  testSquareClass();
  testTriangleClass();
  cout << "Functionalities of all Created Objects Tested!\n\n PROGRAM "
          "BEGINS\n\n";

  // initialize the `container_limit` size
  const int container_limit = 100;

  // create CPolygon Array container the memory addresses of added polygons
  CPolygon *PolygonContainer[container_limit];

  // initialize `n` to access the index of the CPolygon Array
  int n = 0;

  // a variable to keep track of all the objects added to the Array to prevent
  // segfaults
  int objects_created = 0;

  do {
    int response = 0;

    // generate a random number for each Polygon object going to be created
    float random = (rand() % 100);

    cout << "Create an object:\n";
    cout << "1. Rectangle\n2. Triangle\n3. Square\n\n->";
    cin >> response;

    if (response == PolygonType::Rectangle + 1) {
      float width = 0, height = 0;
      cout << "Enter the value for width: ";
      cin >> width;

      cout << "\nEnter the value for height: ";
      cin >> height;
      // Create a Rectangle object
      CRectangle rect_ob = *new CRectangle;
      // set the values of `w` and `h` to the random valus generated
      rect_ob.setValues(width, height);
      // add new object to the CPolygon Array by index;
      PolygonContainer[n] = &rect_ob;

    } else if (response == PolygonType::Triangle + 1) {
      float base = 0, height = 0;
      cout << "Enter the value for base: ";
      cin >> base;

      cout << "\nEnter the value for height: ";
      cin >> height;

      // Create a Triangle object
      CTriangle tri_ob = *new CTriangle;
      // set the values of `w` and `h` to the random valus generated
      tri_ob.setValues(base, height);
      // add new object to the CPolygon Array by index;
      PolygonContainer[n] = &tri_ob;

    } else if (response == PolygonType::Square + 1) {
      float length = 0;
      cout << "Enter the value for length: ";
      cin >> length;

      // Create Square object
      CSquare sq_ob = *new CSquare;
      // set the values of `w` and `h` to the random valus generated
      sq_ob.setValues(length, length);
      // add new object to the CPolygon Array by index;
      PolygonContainer[n] = &sq_ob;

    } else {
      cout << "Not a valid input, try again!\n";
    }

    // increase the value of n
    ++n;
    // increase the count of objects created
    ++objects_created;

    // ask the user for feedback on creating another object
    int sequeled_response = 0;
    cout << "Do you want to create another object? 1 for Yes, 0 for No. \n->";
    cin >> sequeled_response;

    if (sequeled_response == 1) {
      continue;
    } else {
      break;
    }
  } while (n < container_limit);

  // log the area of each object added to the CPolygon Array onto the console
  cout << "You created a number of " << objects_created
       << " polygons which were added to the polygon container.\nThe Area of "
          "each polygon is shown below\n\n";

  // initialize a variable to go through the Polygon
  int iter = 0;

  while (iter != objects_created) {
    // print the area of each object using its member function
    PolygonContainer[iter]->printArea();
    ++iter;
  }

  return 0;
}