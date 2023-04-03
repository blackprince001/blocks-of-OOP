#include <iostream>

// A friend of a class is function or class that has access the private members
// of that class.

class Great {
   private:
    float tip;
    float sink;
    friend void set_values();

   public:
};

void Great::set_values() { sink += 2; }