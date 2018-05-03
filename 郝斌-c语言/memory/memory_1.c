#include <stdio.h>

int f();

int main(void) {
  int i = 10;
  i = f();
  printf("%d\n", i);
  return 0;
}

int f(){
  int j = 11;
  return j;
}