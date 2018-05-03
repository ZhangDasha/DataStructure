#include <stdio.h>
#include <string.h>

void hannuota(int, char, char, char);
/*
  思路：
    如果n=1，
      直接将盘子从A移动到C；
    否则
      将A上n-1个盘子借助C移动到B；
      然后将A上第n个盘子直接移动到C；
      最后将B上n-1个盘子借助A移动到C上。
*/

int main(void) {
  int n;
  char ch1 = 'A';
  char ch2 = 'B';
  char ch3 = 'C';

  printf("请输入盘子数\n");
  scanf("%d", &n);
  hannuota(n, ch1, ch2, ch3);
  // hannuota(n, 'A', 'B', 'C');
  return 0;
}

void hannuota(int n, char A, char B, char C) {
  if(n == 1)  //编号1的盘子
    printf("将编号%d的盘子直接从%c移动到%c!\n", n, A, C);
  else {
    hannuota(n-1, A, C, B);
    printf("将编号%d的盘子直接从%c移动到%c\n", n, A, C);
    hannuota(n-1, B, A, C);
  }
}