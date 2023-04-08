#include <iostream>

class Counter {
 private:
  int count;

 public:
  void set_count(int new_val) { count = new_val; }
  int get_count() const { return count; }
  int get_count_doubled() { return 2 * count; }
  void increment_count() { ++count; }
};

int main() {
  Counter ctr1;
  ctr1.set_count(0);

  for (int i = 0; i < 20; ++i) ctr1.increment_count();

  int count = ctr1.get_count();
  std::cout << "Current count value: " << count;

  const Counter &ctr2 = ctr1;
  count = ctr2.get_count();   // this should work without error
  count.get_count_doubled();  // this throws an error
                              // WHY?
  // Because since you have promised to not change ctr2 by making it const
  // all const member functions from ctr1 will only work, that's why
  // get_count() works and get_count_doubled() doesn't because it is not
  // marked const.
}