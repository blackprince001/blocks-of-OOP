#include <iostream>

class Publication {
 protected:
  std::string title;
  float price;

 public:
  virtual void get_data(std::string, float, int) {}
  virtual void get_data(std::string, float, float) {}
  virtual void put_data() {}
};

class Book : protected Publication {
 private:
  int page_count;

 public:
  void put_data() {
    std::cout << "Title: " << title << "\n"
              << "Price: " << price << "\n"
              << "Page Count: " << page_count << "\n";
  }
  void get_data(std::string tt, float p, int pc) {
    title = tt;
    price = p;
    page_count = pc;
  }
};

class Tape : public Publication {
 private:
  float recording_time;

 public:
  void put_data() {
    std::cout << "Title: " << title << "\n"
              << "Price: " << price << "\n"
              << "Record time: " << recording_time << "\n";
  }
  void get_data(std::string tt, float p, float rt) {
    title = tt;
    price = p;
    recording_time = rt;
  }
};

int main() {
  Tape sarkodie;
  sarkodie.get_data("illuminati", 15, 3.59);
  sarkodie.put_data();

  Book shsbook;
  shsbook.get_data("No Sweetness Here", 10, 236);
  shsbook.put_data();
}