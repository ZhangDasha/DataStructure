#include <stdio.h>
#include <stdlib.h>

struct Student{
  int id;
  int age;
};

struct Student * CreateStudent(void);
void ShowStudent(struct Student *);

int main(void){
  struct Student * ps;
  ps = CreateStudent();
  ShowStudent(ps);
  return 0;
}

struct Student * CreateStudent(void) {
  struct Student * p = (struct Student *)malloc(sizeof(struct Student));
  p->id = 01;
  (*p).age = 19;
  return p;
}

void ShowStudent(struct Student * pst) {
  printf("%d %d\n", pst->id, pst->age);
}
