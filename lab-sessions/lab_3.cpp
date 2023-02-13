#include <cstddef>
#include <iostream>
#include <vector>

template <typename T, size_t Size>
struct array {
    T arr[Size];
};

unsigned int sum_up_to(int nth) {
    unsigned int sum = 0;
    while (nth >= 1) {
        sum += nth;
        nth--;
    }
    return sum;
}

inline float height_to_feet(float height_centimeters) {
    return height_centimeters * 0.0328084;
}

int fib(int nth) {
    if (nth == 0) return 0;
    if (nth == 2 || nth == 1) return 1;
    return fib(nth - 1) + fib(nth - 2);
}

// array<int, 6> &populate_fib(int nth) { array for (int i = 0; i < nth; ++i) }

std::vector<int> populate_fib(int nth) {
    std::vector<int> sum_list;
    for (int i = 0; i <= nth; ++i) {
        sum_list.push_back(fib(i));
    }
    return sum_list;
}

void test_populate_fib() {
    std::vector<int> lists = populate_fib(10);
    for (auto item : lists) {
        std::cout << item;
    }
}

void test_summation() {
    int response = 0;
    std::cout << "Please enter the nth value of your sum: ";
    std::cin >> response;

    std::cout << "The sum up to " << response << " is " << sum_up_to(response)
              << "\n";
}

void test_height_conversion() {
    float height = 0.0;
    std::cout << "\nEnter the value of the height in centimeters: ";
    std::cin >> height;
    std::cout << "Height in feet is " << height_to_feet(height) << " feet\n";
}

void test_fibonacci() {
    int nth_value;

    std::cout << "Fibonacci sequence for which nth value: ";
    std::cin >> nth_value;

    std::cout << "Fibonacci of " << nth_value << " is " << fib(nth_value);
}

int main() {
    test_populate_fib();
    test_height_conversion();
    test_summation();
    test_fibonacci();
}