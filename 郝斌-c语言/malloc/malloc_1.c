#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a[5] = {1,2,3,4,5};

  // 模拟数组
  int len;
  int i;
  printf("请输入你需要分配的数组长度：len=");
  scanf("%d", &len);
  // sizeof求int*类型的字节数
  // malloc函数只能返回第一个字节的地址
  int * pArr = (int *)malloc(sizeof(int) * len);  //此处相当于malloc(20)字节的空间
  *pArr = 5; //等价于a[0] = 4
  pArr[1] = 4;
  pArr[2] = 3;
  pArr[3] = 2;
  pArr[4] = 1;
  for(i=0; i<len; i++){
    printf("%d\n", pArr[i]);
  }
  free(pArr);   //将pArr占用的内存释放掉
return 0;
}