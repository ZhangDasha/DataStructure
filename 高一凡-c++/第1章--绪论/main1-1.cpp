#include "c1.h"
typedef int ElemType;
#include "c1-1.h"
#include "bo1-1.h"
#include "func1-1.h"

int main(){
  Triplet T;
  ElemType m;
  Status i;
  i = InitTriplet(T, 5, 7, 9);  //初始化三元组T
  printf("调用初始化函数后， i = %d(1:成功)。 T的3个值为", i);
  PrintT(T);  //输出T的3个值
  i = Get(T, 2, m);  //将三元组T的第二个值赋给m
  if(i == OK){
    printf("T的第2个值为");
    PrintE(m);  //输出m（=T[1]）
  }
  i = Put(T, 2, 6);
  if(i == OK){
    printf("将T的第2个值改为6后， T的3个值为");
    PrintT(T);
  }
  i = IsAscending(T);  //测试升序
  printf("调用测试升序的函数后，i = %d（0:否， 1:是）\n", i);
  i = IsDescending(T);
  printf("调用测试降序的函数后，i = %d（0:否， 1:是）\n", i);
  if((i = Max(T,m) == OK)){
    printf("T中的最大值为");
    PrintE(m);  //输出最大值m
  }
  if((i = Min(T, m)) == OK){
    printf("T中的最小值为");
    PrintE(m);  //输出最小值m
  }
  DestroyTriplet(T);  //函数也可以不带返回值
  printf("销毁T后， T= %u\n", T[0]);
}