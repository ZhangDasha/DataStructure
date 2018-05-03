#include "c1.h"
#include "c8-2.h"
typedef int KeyType;
typedef int InfoType;
#include "c9-1.h"
#include "c9-2.h"
#include "func9-1.h"
typedef SqList HeapType;
#include "bo9-3.h"

int main(void)
{
  FILE *f;
  SqList m1, m2, m3;
  int i;
  f = fopen("f9-1.txt", "r");
  fscanf(f, "%d", &m1.length);
  for(i=1; i<=m1.length; i++)
    InputFromFile(f, m1.r[i]);
  fclose(f);
  m2 = m3 = m1;   //复制顺序表，使m2、m3、m1相同
  printf("排序前：\n");
  Print(m1);
  SelectSort(m1);
  printf("简单排序后：\n");
  Print(m1);
  HeapSort(m2, TRUE);
  printf("大顶堆排序后：\n");
  Print(m2);
  HeapSort(m3, FALSE);
  printf("小顶堆排序后：\n");
  Print(m3);
}