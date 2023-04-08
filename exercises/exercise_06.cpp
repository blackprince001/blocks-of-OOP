#include <iostream>
#include <valarray>

// implicit parameter `this` and how it maps attributes in all scopes.
// analogous to the `self` keyword in other languages like python.
/*
class A:
    def __init__(self, val: int):
        self._some_param = val

    def change_internal_params(self):
        self._some_param += 1
*/
class mainObj {
  int some_property = 0;

 public:
  void change_said_property() {
    int *pProp = &this->some_property;
    *(pProp) += 1;
  }
  int get_said_property() { return some_property; }
};

int main() {
  mainObj someObj;

  for (int i = 0; i < 10; ++i) {
    someObj.change_said_property();
  }
  std::cout << someObj.get_said_property();
}