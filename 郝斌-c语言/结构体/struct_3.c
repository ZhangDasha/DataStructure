#include <stdio.h>
#include <string.h>

struct Student{
  int sid;
  char name[200];
  int age;
};

void f(struct Student * pst);
void g(struct Student st2);
void g2(struct Student * pst);

int main(void) {
  struct Student st = {1000, "zhangsan", 24};
  printf("%d %s %d\n", st.sid, st.name, st.age);

  f(&st);
  // printf("%d %s %d\n", st.sid, st.name, st.age);
  // 这种方法不推荐，直接传递结构体消耗内存
  g(st);
  g2(&st);

  return 0;
}

void f(struct Student * pst) {
  (*pst).sid = 1003;
  strcpy((*pst).name, "daSha");
  (*pst).age = 22;
}

void g(struct Student st2) {
  printf("%d %s %d\n", st2.sid, st2.name, st2.age);
}

void g2(struct Student * pst) {
  printf("%d %s %d\n", pst->sid, pst->name, pst->age);
}