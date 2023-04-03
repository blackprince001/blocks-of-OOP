#include <iostream>

void ctof(float celsius) {
  float fahrenheit = 0;
  fahrenheit = 1.8 * celsius + 32;
  std::cout << celsius << "C == " << fahrenheit << "F";
}

void ftoc(float fahrenheit) {
  float celsius = 0;
  celsius = 0.5556 * fahrenheit - 32;
  std::cout << fahrenheit << "F == " << celsius << "C";
}

int main() {
  int decision;
  float fahrenheit, celsius;

  std::cout << "For Celsius to Fahrenheit, press 1 "
               "\nFor Fahrenheit to Celsius, press 0 : ";
  std::cin >> decision;

  if (decision) {
    std::cout << "Celsius value: ";
    std::cin >> celsius;
    ctof(celsius);
  } else {
    std::cout << "Fahrenheit value: ";
    std::cin >> fahrenheit;
    ftoc(fahrenheit);
  }

  return 0;
}