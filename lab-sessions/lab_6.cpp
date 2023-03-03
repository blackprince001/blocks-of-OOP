#include <iostream>
#include <tuple>

std::tuple<int, int> findMinMax(int arr[], int size) {
  int *maxValPtr = arr;
  int *minValPtr = arr;
  for (int i = 1; i < size; ++i) {
    if (arr[i] >= *maxValPtr) maxValPtr = &arr[i];
    if (arr[i] <= *minValPtr) minValPtr = &arr[i];
  }
  return std::tuple<int, int>{*minValPtr, *maxValPtr};
}

int main() {
  const int Size = 5;
  int arr[Size] = {-1, 2, 3, 5, 4};

  const auto caught = findMinMax(arr, Size);
  std::cout << "Minimum Value from Array" << std::get<0>(caught) << "\n";
  std::cout << "Maximum Value from Array" << std::get<1>(caught) << "\n";
}