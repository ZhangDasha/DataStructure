#include "c1.h"
#include "c8-2.h"
typedef int KeyType;
typedef int InfoType;
#include "c9-1.h"
#include "c9-2.h"
#include "func9-1.h"

void Print1(SqList L)
{
  int i;
  for(i=1; i<=L.length; i++)
    printf("%d ", L.r[i].key);
  printf("\n");
}

void ShellInsert(SqList &L, int dk)
{
  // 对顺序表L作一趟希尔插入排序。
  /*
    本算法和一趟直接插入排序相比，做了一下修改：
      1.前面记录位置的增量dk，而不是1；
      2.r[0]只是暂存单元，不是哨兵。当j<=0时，插入位置已找到。
  */
  int i, j;
  for(i=dk+1; i<=L.length; i++)
    if LT(L.r[i].key, L.r[i-dk].key)
    {
      L.r[0] = L.r[i];  //当前记录暂存L.r[0]
      for(j=i-dk; j>0 && LT(L.r[0].key, L.r[j].key); j=j-dk)
        L.r[j+dk] = L.r[j];   //记录后移，查找插入位置
      L.r[j+dk] = L.r[0];
    }
}

void ShellSort(SqList &L, int dlta[], int t)
{
  // 按增量序列dlta[0~t-1]对顺序表L作希尔排序
  int k;
  for(k=0; k<t; k++)
  {
    ShellInsert(L, dlta[k]);    //一趟增量为dlta[k]的希尔插入排序
    printf("dlta[%d] = %d, 第%d趟排序结果：", k, dlta[k], k+1);
    Print1(L);
  }
}

#define N 10    //记录数组长度
#define T 3     //增量序列数组长度

int main(void)
{
  RedType d[N] = {{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8},{55,9},{4,10}};
  SqList m;
  int i, dt[T]={5,3,1};   //增量序列数组
  for(i=0; i<N; i++)  //将数组d赋给顺序表m
    m.r[i+1] = d[i];
  m.length = N;
  printf("希尔排序前：\n");
  Print(m);
  ShellSort(m, dt, T);
  printf("希尔排序后：\n");
  Print(m);
}