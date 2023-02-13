#include <iostream>
#include <array>

typedef char capped_at_10_chars[10]; 

int main() {
    int val = 17785;

    std::string greetings = "Welcome to this class";
    // char* greeting_char_buf = "Welcome to this class";
    char greeting_char_array[] = "Welcome to this class";

    double d_val = -56.1427;
    float f_val = -56.1427;

    std::string abrt = "5262778y";

    int a=5, b=5, c=5;

    bool flag = true;

    std::string names[2] = {"prince", "appiah"};

    // compute the year a person was born program
    int age, current_year = 2023;
    age = std::cin.get();
    std::cout << current_year - age;

    // string array capped at a limit of 10
    std::array<capped_at_10_chars, 5> string_with_limited_chars = {"prince", "kevin"};

    std::cout << "Hello, World!" << std::endl;
}