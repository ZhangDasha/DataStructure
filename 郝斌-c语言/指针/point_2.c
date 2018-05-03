#include <stdio.h>

void f(int *i) {
  *i = 100;
}

int main(void) {
  int i = 1;
  // 传递i的地址
  f(&i);
  printf(" i = %d\n", i);   // i = 100
  return 0;
}