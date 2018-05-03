#include <stdio.h>

// typedef起别名
// 例： typedef int HH  --> HH === int
typedef struct Student {
  int id;
  char name[100];
  char sex;
} ST;
int main(void) {

  ST st;
  st.id = 19;
  printf("%d\n", st.id);
  return 0;
}