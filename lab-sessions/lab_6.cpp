#include <iostream>
#include <tuple>

// return the pair of minimum and maximum values from an array
// using iterative pointers
std::pair<int, int> findMinMax_p(int arr[], int size) {
  int *maxValPtr = arr;
  int *minValPtr = arr;
  for (int i = 1; i < size; ++i) {
    if (arr[i] >= *maxValPtr) maxValPtr = &arr[i];
    if (arr[i] <= *minValPtr) minValPtr = &arr[i];
  }
  return std::pair<int, int>{*minValPtr, *maxValPtr};
}

// return the pair of minimum and maximum values from an array
std::pair<int, int> findMinMax(int arr[], int size) {
  int max = arr[0];
  int min = arr[0];
  for (int i = 1; i < size; ++i) {
    if (arr[i] >= max) max = arr[i];
    if (arr[i] <= min) min = arr[i];
  }
  return std::pair<int, int>{min, max};
}

int main() {
  const int Size = 5;
  int arr[Size] = {-1, 2, 3, 5, 4};

  const auto caught = findMinMax(arr, Size);
  std::cout << "Minimum Value from Array " << std::get<0>(caught) << "\n";
  std::cout << "Maximum Value from Array " << std::get<1>(caught) << "\n";

  const auto caught_p = findMinMax_p(arr, Size);
  std::cout << "p: Minimum Value from Array " << std::get<0>(caught_p) << "\n";
  std::cout << "p: Maximum Value from Array " << std::get<1>(caught_p) << "\n";
}