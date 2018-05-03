void InitList(SqList &L)
{
  L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
  if(!L.elem)
    exit(-1);
  L.length = 0;
  L.listsize = LIST_INIT_SIZE;
}

void DestroyList(SqList &L)
{
  free(L.elem);
  L.elem = NULL;  //L.elem不再指向任何存续空间
  L.length = 0;
  L.listsize = 0;
}

void ClearList(SqList &L)
{
  // 将L重置为空表
  L.length = 0;
}

Status ListEmpty(SqList L)
{
  if(L.length == 0)
    return TRUE;
  else
    return FALSE;
}

int ListLength(SqList &L)
{
  return L.length;
}

Status GetElem(SqList L, int i, ElemType &e)
{
  // 用e返回L中第i个数据元素的值
  if(i<1 || i>L.length)
    return ERROR;
  e = *(L.elem + i - 1); //将表L的第i个元素的值赋值给e
  return OK;
}

int LocateElem(SqList L, ElemType e, Status(* compare)(ElemType, ElemType))
{
  // 返回L中第一个与e满足关系compare（）的数据元素的位序
  // compare()是数据元素判定函数满足为1，
  int i = 1;
  ElemType * p = L.elem;
  while(i <= L.length && !compare(*p++, e))
    i++;
  if(i <= L.length)
    return i;
  else
    return 0;
}

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
  // 若cur_E是L的数据元素，且不是第一个，则用pre_e返回它的前驱
  int i = 2;
  ElemType *p = L.elem + 1;
  while(i <= L.length && *p != cur_e)
  {
    p++;  //指向下一个元素
    i++;  //计数加1
  }
  if(i > L.length)
    return ERROR;
  else
  {
    pre_e = *--p;   //p指向前一个元素，将所指向元素的值赋值给pre_e
    return OK;
  }
}

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e)
{
  // 返回后继
  int i = 1;
  ElemType * p = L.elem;
  while(i < L.length && *p != cur_e)
  {
    p++;
    i++;
  }
  if(i == L.length)
    return ERROR;
  else
  {
    next_e = *++p;
    return OK;
  }
}

Status ListInsert(SqList &L, int i, ElemType e)
{
  ElemType *newbase, *q, *p;
  if(i < 1 || i>L.length+1)
    return ERROR;
  if(L.length == L.listsize)
  {
    // 追加内存
    newbase = (ElemType *)realloc(L.elem, (L.listsize + LIST_INCREMENT)*sizeof(ElemType));
    if(!newbase)  //存储分配失败
      exit(-1);
    L.elem = newbase;
    L.listsize += LIST_INCREMENT;
  }
  q = L.elem + i-1;   //q为插入位置
  for(p = L.elem + L.length-1; p >= q; --p)   //插入位置及后面的元素右移
    *(p+1) = *p;  //其后元素后移
  *q = e; //插入e
  L.length++;
  return OK;
}

Status ListDelete(SqList &L, int i, ElemType &e)
{
  // 删除L的第i个元素，并用e返回，
  ElemType *p, *q;
  if(i<1 || i>L.length)
    return ERROR;
  p = L.elem+i-1;
  e= *p;
  q = L.elem + L.length-1;
  for(p++; p <= q; p++)
    *(p-1) = *p;
  L.length--;
  return OK;
}

void ListTraverse(SqList L, void(*visit)(ElemType &))
{
  // 依次对L对每个数据元素调用函数visit（）表示对数据结构中结点的访问,visit()的形参加&,表明可通过调用visit（）改变元素的值
  ElemType *p = L.elem;
  int i;
  for(i=1; i<=L.length; i++)
    visit(*p++);
  printf("\n");
}































