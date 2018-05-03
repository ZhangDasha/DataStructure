void InitList(LinkList &L)
{
  L = (LinkList)malloc(sizeof(LNode));
  if(!L)
    exit(-1);
  L->next = NULL;
}

void DestroyList(LinkList &L)
{
  LinkList q;
  while(L)
  {
    q = L->next;
    free(L);
    L = q;
  }
}

void ClearList(LinkList L)
{
  LinkList p = L->next;
  L->next = NULL;
  DestroyList(p);
}

Status ListEmpty(LinkList L)
{
  if(L->next)
    return FALSE;
  else
    return TRUE;
}

int ListLength(LinkList L)
{
  int i = 0;
  LinkList p = L->next;
  while(p)
  {
    i++;
    p = p->next;
  }
  return i;
}

Status GetElem(LinkList L, int i, int &e)
{
  int j = 1;
  LinkList p= L->next;
  while(p && j<i)
  {
    j++;
    p = p->next;
  }
  if(!p || j>i)
    return ERROR;
  e = p->data;
  return OK;
}

int LocateElem(LinkList L, int e, Status(*compare)(int, int))  //compare为参数名
{
  int i =0;
  LinkList p = L->next;
  while(p)
  {
    i++;
    if(compare(p->data, e))
      return i;
    p=p->next;
  }
  return 0;
}

Status PriorElem(LinkList L, int cur_e, int &pre_e)
{
  LinkList q, p = L->next;
  while(p && p->next)
  {
    q = p->next;
    if(q->data == cur_e)
    {
      pre_e = p->data;
      return OK;
    }
    p=q;
  }
  return ERROR;
}

Status NextElem(LinkList L, int cur_e, int &next_e)
{
  LinkList p = L->next;
  while(p && p->next)
  {
    if(p->data == cur_e)
    {
      next_e = p->next->data;
      return OK;
    }
    p=p->next;
  }
  return ERROR;
}

Status ListInsert(LinkList L, int i, int e)
{
  int j =0;
  LinkList s, p =L;
  while(p && j<i-1)
  {
    j++;
    p=p->next;
  }
  if(!p || j>i-1)
    return ERROR;
  s = (LinkList)malloc(sizeof(LNode));
  s->data = e;
  s->next = p->next;
  p->next = s;
  return OK;
}

Status ListDelete(LinkList L, int i, int &e)
{
  int j=0;
  LinkList q, p =L;
  while(p->next && j<i-1)
  {
    j++;
    p=p->next;
  }
  if(!p->next || j>i-1)
    return ERROR;
  q = p->next;
  p->next = q->next;
  e = q->data;
  free(q);
  return OK;
}

void ListTraverse(LinkList L, void(*visit)(int))
{
  LinkList p = L->next;
  while(p)
  {
    visit(p->data);
    p=p->next;
  }
  printf("\n");
}














