#include "pointers.h"

void swapPointers(int *ptr1, int *ptr2) {
  int temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;

  // ? Without temp variable
  //*ptr1 = *ptr1 + *ptr2;
  //*ptr2 = *ptr1 - *ptr2;
  //*ptr1 = *ptr1 - *ptr2;
}
