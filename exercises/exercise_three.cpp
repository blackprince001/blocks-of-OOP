#include <iostream>

long hms_to_secs(int hrs, int mins, int secs) {
  long to_seconds = 0;
  // ensure values from args can be used to compute the seconds
  // since there will not be any inherent error handling for the program
  if ((hrs <= 24 && hrs >= 0) && (mins <= 60 && mins >= 0) &&
      (secs <= 60 && secs >= 0)) {
    to_seconds += hrs * 3600 + mins * 60 + secs;
  } else {
    return -1;  // return -1 when one of the parameters does not fall in the
                // range specified for it
  }
  return to_seconds;
}

void prompt() {
  int hours = 0, minutes = 0, seconds = 0;
  std::cout
      << "What is the time? (Please use hr:min:sec using the 24hr format)\n:";
  std::cin >> hours >> minutes >> seconds;  // accept input separated by spaces

  std::cout << "Time is " << hms_to_secs(hours, minutes, seconds)
            << " seconds\n";
}

int main() {
  while (true) prompt();
}
