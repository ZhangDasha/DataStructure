#include <stdio.h>

void quickSort(int * a, int low, int high);
int findPos(int * a, int low, int high);

int main(void) {
  int a[6] = {2,1,0,5,4,3};
  int i;
  quickSort(a, 0, 5);
  for(i=0; i<6; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}

void quickSort(int * a, int low, int high) {
  int pos;
  if (low < high) {
    pos = findPos(a, low, high);
    quickSort(a, low, pos-1);
    quickSort(a, pos+1, high);
  }
}

int findPos(int * a, int low, int high) {
  int val = a[low];
  while(low < high) {
    while(low < high && a[high] >= val)
      high--;
    a[low] = a[high];
    while(low < high && a[low] <= val) 
      low++;
    a[high] = a[low];
  }//终止while循环时，low与high相等
  a[low] = val;

  return low;
}