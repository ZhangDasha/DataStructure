// 顺序栈的基本操作
void InitStack(SqStack &S)
{
  S.base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
  if(!S.base)
    exit(-1);
  S.top = S.base;
  S.stacksize = STACK_INIT_SIZE;
}

void DestroyStack(SqStack &S)
{
  free(S.base);
  S.top = S.base = NULL;
  S.stacksize = 0;
}

void ClearStack(SqStack &S)
{
  S.top = S.base;   //栈顶指针指向栈底
}

Status StackEmpty(SqStack &S)
{
  if(S.top == S.base)
    return TRUE;
  else
    return FALSE;
}

int StackLength(SqStack &S)
{
  // 返回栈中元素的个数，即栈的长度
  return S.top - S.base;
}

Status GetTop(SqStack &S, int &e)
{
  // 若栈S不空，则用e返回S栈顶的元素，并返回OK，否则返回ERROR
  if(S.top > S.base)
  {
    e = *(S.top-1);
    return OK;
  } else {
    return FALSE;
  }
}

void Push(SqStack &S, int e)
{
  if(S.top - S.base == S.stacksize)
  {
    S.base = (int *)realloc(S.base, (S.stacksize+STACK_INCREMENT)*sizeof(int));
    if(!S.base)
      exit(-1);
    S.top = S.base + S.stacksize;   //修改栈顶指针
    S.stacksize += STACK_INCREMENT;   //更新已分配存续空间
  }
  *(S.top)++ = e; //e入栈，成为新的栈顶元素
}

Status Pop(SqStack &S, int &e)
{
  // 出栈
  if(S.top == S.base)
    return FALSE;
  e = * --S.top;  //将栈顶元素赋给e，栈顶指针下移一个存储单位
  return OK;
}

void StackTraverse(SqStack &S, void(*visit)(int))
{
  int * p = S.base;
  while(S.top > p)
    visit(*p++);  //对该栈元素调用visit()，p指针上移一个存续单元
  printf("\n");
}





































