// Exercise from Pointers chapter

// Let’s say that you need to store 100 integers so that they’re easily
// accessible. However, let’s further assume that there’s a problem: The memory
// in your computer is so frag- mented that the largest array that you can use
// holds only 10 integers. (Such problems actually arise, although usually with
// larger memory objects.) You can solve this problem by defining 10 separate
// int arrays of 10 integers each, and an array of 10 pointers to these arrays.
// The int arrays can have names like a0, a1, a2, and so on. The address of each
// of these arrays can be stored in the pointer array of type int*, which can
// have a name like ap (for array of pointers). You can then access individual
// integers using expressions like ap[j][k], where j steps through the pointers
// in ap and k steps through individual integers in each array. This looks as if
// you’re accessing a two-dimensional array, but it’s really a group of
// one-dimensional arrays. Fill such a group of arrays with test data (say the
// numbers 0, 10, 20, and so on up to 990). Then display the data to make sure
// it’s correct.
#include <iostream>

const int lim = 10;

void fill_array(int arr[], int init_val) {
  for (int i = 0; i < lim; ++i) arr[i] = init_val;
}

int main() {
  int *pArrayContainer[10];

  int a0[lim];
  fill_array(a0, 2);

  int a1[lim];
  fill_array(a1, 4);

  int a2[lim];
  fill_array(a2, 6);

  int a3[lim];
  fill_array(a3, 8);

  int a4[lim];
  fill_array(a4, 10);

  int a5[lim];
  fill_array(a5, 12);

  int a6[lim];
  fill_array(a6, 14);

  int a7[lim];
  fill_array(a7, 16);

  int a8[lim];
  fill_array(a8, 18);

  int a9[lim];
  fill_array(a9, 20);

  pArrayContainer[0] = a0;
  pArrayContainer[1] = a1;
  pArrayContainer[2] = a2;
  pArrayContainer[3] = a3;
  pArrayContainer[4] = a4;
  pArrayContainer[5] = a5;
  pArrayContainer[6] = a6;
  pArrayContainer[7] = a7;
  pArrayContainer[8] = a8;
  pArrayContainer[9] = a9;

  // iterate through the container
  // the containers is an array of pointers
  // so if we are to print the values of the items in the container
  // we should have something like the output below:
  // 0x7ffe43e70030
  // 0x7ffe43e70038
  // 0x7ffe43e70040
  // 0x7ffe43e70048
  // 0x7ffe43e70050
  // 0x7ffe43e70058
  // 0x7ffe43e70060
  // 0x7ffe43e70068
  // 0x7ffe43e70070
  // 0x7ffe43e70078
  // each address represents one of the array blocks a0 ... a9

  for (int y = 0; y < lim; ++y) {
    std::cout << "Array " << y << " Content:\n";
    for (int *x = pArrayContainer[y]; x < (pArrayContainer[y] + 10); ++x) {
      std::cout << *x << "\n";
    }
    std::cout << "\n\n";
  }
  return 0;
}