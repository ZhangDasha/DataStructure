#include <stdio.h>

typedef struct Student {
  int id;
  char name[100];
  char sex;
}* PST;  //PST 等价于 struct Student *
int main(void) {

  struct Student st;
  PST ps = &st;
  ps->id = 20;
  printf("%d\n", ps->id);
  return 0;
}