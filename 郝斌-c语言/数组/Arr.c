#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  //c 语言中没有bool类型，需要引入

// 结构体是数据类型，该数据类型的名字叫做struct Arr
struct Arr{
  int * nBase;  //数组的第一个元素的地址
  int len;  //数组的长度
  int cnt;  //当前数组有效元素的个数
  // int increment;   //自动增长因子
};

void init_arr(struct Arr * pArr, int length);
bool append_arr(struct Arr * pArr, int val);
bool insert_arr(struct Arr * pArr, int pos, int val);  //pos从1开始
bool delete_arr(struct Arr * pArr, int pos, int *pVal);
bool is_full(struct Arr * pArr);
bool is_empty(struct Arr * pArr);
void sort_arr(struct Arr * pArr);
void show_arr(struct Arr * pArr);
void inversion_arr(struct Arr * pArr);
// int get();

int main(void) {
  struct Arr arr;
  int val;

  init_arr(&arr, 6);
  printf("初始化：");
  show_arr(&arr);

  append_arr(&arr, 1);
  append_arr(&arr, 2);
  append_arr(&arr, 3);
  append_arr(&arr, 4);
  append_arr(&arr, 5);
  printf("添加数据：");
  show_arr(&arr);

  insert_arr(&arr, 2, 99);
  printf("插入数据:");
  show_arr(&arr);

  delete_arr(&arr, 3, &val);
  printf("删除数值：%d\n" ,val);
  show_arr(&arr);

  inversion_arr(&arr);
  printf("倒置：");
  show_arr(&arr);

  sort_arr(&arr);
  printf("排序：");
  show_arr(&arr);

  return 0;
}

void init_arr(struct Arr * pArr, int length){
  // *pArr === arr
  pArr->nBase = (int *)malloc(sizeof(int) * length);
  if(NULL == pArr->nBase) {
    printf("动态内存分配失败\n");
    exit(-1);   //表示终止整个程序
  } else {
    pArr->len = length;
    pArr->cnt = 0;
  }
  return;
}

bool is_empty(struct Arr * pArr){
  if(0 == pArr->cnt)
    return true;
  else
    return false;
}

bool is_full(struct Arr * pArr) {
  if (pArr->cnt == pArr->len)
    return true;
  else
    return false;
}

void show_arr(struct Arr * pArr) {
  int i;
  if(is_empty(pArr)){
    printf("数组为空\n");
  } else {
    for(i=0; i<pArr->cnt; i++){
      printf("%d ", pArr->nBase[i]);
    }
    printf("\n");
  }
}

bool append_arr(struct Arr * pArr, int val) {
  if( is_full(pArr)){
    return false;
  } else {
    pArr->nBase[pArr->cnt] = val;
    (pArr->cnt)++;
    return true;
  }
}

bool insert_arr(struct Arr * pArr, int pos, int val) {
  int i;
  if(is_full(pArr))
    return false;
  if(pos < 1 || pos > pArr->cnt+1)
    return false;
  for(i=pArr->cnt-1; i>=pos-1; --i){
    pArr->nBase[i+1] = pArr->nBase[i];
  }
  pArr->nBase[pos-1] = val;
  (pArr->cnt)++;
  return true;
}

bool delete_arr(struct Arr * pArr, int pos, int *pVal) {
  int i;
  if(is_empty(pArr))
    return false;
  if(pos<1 || pos>pArr->cnt)
    return false;
  *pVal = pArr->nBase[pos-1];
  for(i=pos; i<pArr->cnt; i++)
    pArr->nBase[i-1] = pArr->nBase[i];
  (pArr->cnt)--;
  return true;
}

void inversion_arr(struct Arr * pArr) {
   int i=0;
   int j = pArr->cnt-1;
   int t;
   while(i<j){
    t = pArr->nBase[i];
    pArr->nBase[i] = pArr->nBase[j];
    pArr->nBase[j] = t;
    i++;
    j--;
   }
   return;
}

void sort_arr(struct Arr * pArr) {
  int i, j, t;
  for(i=0; i<pArr->cnt-1; i++){
    for(j=i+1; j<pArr->cnt; j++){
      if(pArr->nBase[i] > pArr->nBase[j]){
        t = pArr->nBase[i];
        pArr->nBase[i] = pArr->nBase[j];
        pArr->nBase[j] = t;
      }
    }
  }
}





