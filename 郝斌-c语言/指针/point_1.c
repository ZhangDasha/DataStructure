#include <stdio.h>

int main (void) {
    int *p; // p是一个变量名，int *表示只能存储一个int类型变量的的地址
    int i = 10;
    int j;
    p = &i; //把i的地址赋值给指针p    *p === i
    j = *p;
    printf("%d\n", j);
    return 0;
}