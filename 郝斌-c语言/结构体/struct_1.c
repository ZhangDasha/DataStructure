#include <stdio.h>
#include <string.h>

struct Student{
  int sid;
  char name[200];
  int age;
};  //分号不能省

int main(void) {
  struct Student st = {1000, "zhangsan", 24};
  printf("%d %s %d\n", st.sid, st.name, st.age);

  st.sid = 1001;
  strcpy(st.name, "liSi");    //c语言中需要使用strcpy对字符串进行赋值
  st.age = 23;
  printf("%d %s %d\n", st.sid, st.name, st.age);

  return 0;
}