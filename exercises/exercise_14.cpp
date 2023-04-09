#include <iostream>

int main() {
  int len;
  float num;

  std::cout << "How many numbers do you want to enter? ";
  std::cin >> len;

  float numbers[len];
  for (int i = 0; i < len; ++i) {
    std::cin >> num;
    numbers[i] = num;
  }

  float *start = numbers;      // set a pointer to the beginning of the array
  float *end = numbers + len;  // set another pointer to the end of the array
  float sum = 0, avg;          // initialize sum and avg variables
  for (; start != end; ++start) {  // increase start pointer if not equal to end
    sum += *(start);  // dereference the start pointer and add it to the sum
  }
  avg = sum / len;                                   // compute the average
  std::cout << "Average of the numbers is " << avg;  // print the average
}