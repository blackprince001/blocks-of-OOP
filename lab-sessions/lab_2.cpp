#include <iostream>

int main() {
  float height = 0, weight = 0;

  std::cout << "What is your weight? ";
  std::cin >> weight;

  std::cout << "What is your height? ";
  std::cin >> height;

  if (height <= 0) std::cout << "Height cannot be negative or zero\n";

  float bmi = weight / ((height / 100.0) * (height / 100.0));
  std::cout << "Your BMI is " << bmi << '\n';

  if (bmi < 18.5) std::cout << "You are underweight\n";
  if (bmi >= 18.5 && bmi <= 24.9) std::cout << "Your weight is normal.\n";
  if (bmi >= 25 && bmi <= 29) std::cout << "YOu are overweight.\n";
  if (bmi >= 30 && bmi <= 39.9) std::cout << "You are obese.\n";
  if (bmi > 40) std::cout << "You are morbidly obese.\n";
}