#include <stdio.h>

void f(int ** t);

int main(void) {
  int i = 9;
  int *p = &i; //int *类型的变量p； p = &i 
  printf("指针值=%p\n", p);
  f(&p);    //修改指针的值，使用指针的指针
  printf("修改后的指针值=%p\n", p);
}

void f(int **t){
  *t = (int *)0xFFFFFFFF;
}