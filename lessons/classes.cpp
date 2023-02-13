#include <iostream>

class Namedsmallobject {
    // a normal class
   private:
    std::string name;
    int item = 0;

   public:
    void set_item_value(int new_item) { item = new_item; }
    void set_item_name(std::string new_name) { name = new_name; }
    void show_item_value() {
        std::cout << "name: " << name + ", "
                  << "item: " << item << std::endl;
    }
};

class Counter {
   private:
    u_int count;
    u_int endwith;

   public:
    Counter(u_int start_from, u_int endwith)
        : count(start_from), endwith(endwith) {}

    Counter() : count(0), endwith(100) {}  // Constructor overloading
    void increment() { count++; }
    u_int show_current_value() { return count; }
};

class Human {
   public:
    std::string name = "";
    unsigned int age;

    Human(std::string name, unsigned int age) : name(name), age(age) {}
    Human() : name("CPP-1234"), age(0) {}

    void howOldAmI() { std::cout << age; }
    void whatIsMyName() { std::cout << name; }
};

// class Ethiopian : public Human {
//     Human operator--() { return Human(--age); }
// };

class HiddenStones {
   private:
    std::string stone_name;

   public:
    HiddenStones(std::string name) : stone_name(name) {}
    // HiddenStones(char* default_name='sand') : stone_name(default_name) {}
    // Cannot attempt to use default parameters to overload constructors

    void get_stone_name() { std::cout << stone_name << std::endl; }

    bool equal_stone(const HiddenStones &other)
        const {  // const makes sure equal_stone does not modify any value in
        // both objects
        if (this->stone_name == other.stone_name)
            return true;
        else
            return false;
    }

    ~HiddenStones() {}  // to destroy something i have not figured out yet!
};

class MyRectangle {
   public:
    int x, y;
    MyRectangle(const int xVal, const int yVal) : x(xVal), y(yVal) {}
};

class Semaphore {
    bool *sem;

   public:
    Semaphore() { sem = new bool; }
    ~Semaphore() { delete sem; }
};

template <typename T>
class StudentEmail {
   public:
    StudentEmail(T stdName, T stdNumber) {}
};

// Move, Copy and Default Constructors

void test_Namedsmallobject() {
    Namedsmallobject obj_1, obj_2;
    obj_1.set_item_value(12);
    obj_2.set_item_value(15);

    obj_1.set_item_name("object 1");
    obj_2.set_item_name("object 2");

    obj_1.show_item_value();
    obj_2.show_item_value();
}

void test_counterClass() {
    Counter iterations(0, 5);
    iterations.increment();
    std::cout << iterations.show_current_value();
}

void test_hiddenStonesClass() {
    HiddenStones stone("obsidian");
    HiddenStones anotherStone("obsidian");
    std::cout << "Are they equal? " << stone.equal_stone(anotherStone);
}

int main() {
    test_Namedsmallobject();
    test_counterClass();
    test_hiddenStonesClass();

    return 0;
}