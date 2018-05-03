#include <stdio.h>

void Show_Array(int *p, int len) {
  p[0] = -1;  // p[0] === *p  p[2] === *(p+2) === *(a+2) === a[2]
}

int main(void) {
  int a[5] = {1,2,3,4,5};
  Show_Array(a, 5);   //a === &a[0]  &a[0]本身就是int *
  printf(" a[0]=%d\n", a[0]);
  return 0;
}