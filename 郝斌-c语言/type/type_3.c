#include <stdio.h>

typedef struct Student {
  int id;
  char name[100];
  char sex;
}* PSTU, STU;  //STU代表了struct Student，PSTU代表了struct Student * 
int main(void) {

  STU st;   //struct Student st
  PSTU pst = &st;   //struct Student * pst = $st
  pst->id = 20;
  printf("%d\n", pst->id);
  return 0;
}