#include "c1.h"
#include "c3-1.h"
#include "bo3-1.h"
#include "func2-2.h"
int main(void)
{
  int j;
  SqStack s;
  int e;
  InitStack(s);
  for(j=1; j<=12; j++)
    Push(s, j);
  printf("栈中元素依次为");
  StackTraverse(s, print);
  Pop(s, e);
  printf("弹出栈顶元素e=%d\n",e);
  printf("栈空否？%d，", StackEmpty(s));
  GetTop(s, e);
  printf("栈顶元素e=%d，栈的长度为%d\n", e, StackLength(s));
  ClearStack(s);
  printf("清空栈后！\n");
  DestroyStack(s);
  printf("销毁栈后，s.top = %u, s.base = %u, s.stacksize = %d\n", s.top, s.base, s.stacksize);
}