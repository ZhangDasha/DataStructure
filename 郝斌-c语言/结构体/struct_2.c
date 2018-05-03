#include <stdio.h>
#include <string.h>

struct Student{
  int sid;
  char name[200];
  int age;
};

int main(void) {
  struct Student st = {1000, "zhangsan", 24};
  printf("%d %s %d\n", st.sid, st.name, st.age);

  struct Student *pst;
  pst = &st;
  pst->sid = 1002;  //pst->sid 等价于 (*pst).sid 等价于 st.sid
  strcpy(pst->name, "wangWu");
  (*pst).age = 20;
  printf("%d %s %d\n", st.sid, st.name, st.age);

  return 0;
}