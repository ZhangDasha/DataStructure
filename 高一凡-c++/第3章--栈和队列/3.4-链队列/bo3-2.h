void InitQueue(LinkQueue &Q)
{
  Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
  if(!Q.front)
    exit(-1);
  Q.front->next = NULL;
}

void DestroyQueue(LinkQueue &Q)
{
  while(Q.front)
  {
    Q.rear = Q.front->next;   //Q.rear指向Q.front的下一个节点
    free(Q.front);
    Q.front = Q.rear;   //Q.front指向Q.front的下一个节点
  }
}

void ClearQueue(LinkQueue &Q)
{
  DestroyQueue(Q);
  InitQueue(Q);
}

Status QueueEmpty(LinkQueue Q)
{
  if(Q.front->next == NULL)
    return TRUE;
  else
    return FALSE;
}

int QueueLength(LinkQueue Q)
{
  int i=0;
  QueuePtr p = Q.front;
  while(p != Q.rear)
  {
    ++i;
    p = p->next;
  }
  return i;
}

Status GetHead(LinkQueue Q, int &e)
{
  // 用e返回对头元素，并返回OK
  QueuePtr p;
  if(Q.front == Q.rear)
    return ERROR;
  p = Q.front->next;
  e = p->data;
  return OK;
}

void EnQueue(LinkQueue &Q, int e)
{
  QueuePtr p;
  p = (QueuePtr)malloc(sizeof(QNode));
  if(!p)
    exit(-1);
  p->data = e;
  p->next = NULL;
  Q.rear->next = p;
  Q.rear = p;   //尾指针指向新节点
}

Status DeQueue(LinkQueue &Q, int &e)
{
   //删除对头元素
  QueuePtr p;
  if(Q.front == Q.rear)
    return ERROR;
  p = Q.front->next;
  e = p->data;
  Q.front->next = p->next;  //头节点后移
  if(Q.rear == p)   //如果删除的是队尾节点
    Q.rear = Q.front;   //修改队尾指针指向头节点（空队列）
  free(p);
  return OK;
}

void QueueTraverse(LinkQueue Q, void(*visit)(int))
{
  QueuePtr p = Q.front->next;
  while(p)
  {
    visit(p->data);
    p = p->next;
  }
  printf("\n");
}






























