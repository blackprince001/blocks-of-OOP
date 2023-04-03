// Exercise at the bottom Lecture 5 Slides
#include <iostream>

class TollBooth {
   private:
    unsigned int number_of_cars;
    double amount_collected;

   public:
    TollBooth() : number_of_cars(0), amount_collected(0) {}

    void payingCar() {
        number_of_cars += 1;
        amount_collected += 0.50;
    }

    void nonPayingCar() { number_of_cars += 1; }

    void displayActivity() const {
        std::cout << "Number of Cars Passed: " << number_of_cars
                  << "\nAmount Collect in Cedis: " << amount_collected << "\n";
    }
};

void test_tollbooth(TollBooth &incomingCar) {
    char res;
    std::cout << "Welcome to the KNUST toolbooth. Press P to pay, and N for no "
                 "payments. Press Q to exit booth Service\n\n:";
    std::cin >> res;

    if (res == 'P' || res == 'p') {
        incomingCar.payingCar();
        std::cout << "\nAdding Payment.\n";

    } else if (res == 27) {  // ord for Esc is 27
        incomingCar.displayActivity();
        std::cout << "\nExiting Program..."
                  << "Have a nice day\n";
        exit(1);

    } else if (res == 'N' || res == 'n') {
        incomingCar.nonPayingCar();
        std::cout << "\nNo Payments made. Skipping Process!\n";

    } else {
        std::cout << "Command Entered not Known\n";
    }
}

int main() {
    TollBooth KNUST;
    while (true) test_tollbooth(KNUST);
    return 0;
}