int main(void)
{
  int i;
  int d;
  LinkQueue q;
  InitQueue(q);
  printf("成功构造一个空队列\n");
  printf("是否空队列？%d,", QueueEmpty(q));
  printf("队列的长度为%d\n", QueueLength(q));
  EnQueue(q, -1);
  EnQueue(q, 5);
  EnQueue(q, 10);
  printf("插入3个元素后，队列的长度为%d\n", QueueLength(q));
  printf("是否空队列？%d,", QueueEmpty(q));
  printf("队列的元素依次为");
  QueueTraverse(q, print);
  i = GetHead(q, d);  //将对头元素赋值给d
  if(i == OK)
    printf("对头元素是%d", d);
  DeQueue(q, d);
  printf("删除了对头元素是%d", d);
  i = GetHead(q, d);
  if(i == OK)
    printf("新的对头元素是%d\n", d);
  ClearQueue(q);
  printf("清空队列后，q.front =%u, q.rear =%u, q.front->next=%u\n", q.front, q.rear, q.front->next);
  DestroyQueue(q);
  printf("销毁队列后，q.front =%u, q.rear =%u\n", q.front, q.rear);
}