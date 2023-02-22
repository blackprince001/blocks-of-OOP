#include <iostream>

int main() {
  const float gallonToCubicFeet = 7.481;
  float input;

  std::cout << "How many gallons: ";
  std::cin >> input;

  float cubicEquivalent = input / gallonToCubicFeet;
  std::cout << input << " is Equivalent to " << cubicEquivalent
            << " Cubic feet.\n";

  return 0;
}