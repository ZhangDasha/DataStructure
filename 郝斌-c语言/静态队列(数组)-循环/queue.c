#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue {
  int * pBase;  //指向一个数组
  int front;
  int rear;
}Queue;

// 函数声明
void init(Queue *);
bool en_queue(Queue *, int);
bool full_Queue(Queue *);
void traverse_queue(Queue *);
bool out_queue(Queue *, int *);

int main(void) {
  int val;
  Queue Q;
  init(&Q);
  en_queue(&Q, 1);
  en_queue(&Q, 2);
  en_queue(&Q, 3);
  en_queue(&Q, 4);
  traverse_queue(&Q);

  out_queue(&Q, &val);
  printf("出对成功，出对元素：%d\n", val);
  traverse_queue(&Q);
  return 0;
}

void init(Queue *pQ) {
  pQ->pBase = (int *)malloc(sizeof(int) * 6);   //6个字节，只能存储5个数据，留一个作标识判断对满
  // 初始化 pQ->front === pQ->rear = 0
  pQ->front = 0;
  pQ->rear = 0;
}

bool full_Queue(Queue *pQ) {
  if ((pQ->rear+1)%6 == pQ->front)
    return true;
  else
    return false;
}

bool en_queue(Queue *pQ, int val) {
  if(full_Queue(pQ)){
    return false;
  } else {
    pQ->pBase[pQ->rear] = val;
    pQ->rear = (pQ->rear+1) % 6;
    return true;
  }
}

void traverse_queue(Queue *pQ) {
  int i = pQ->front;
  while(i != pQ->rear) {
    printf("%d ", pQ->pBase[i]);
    i = (i+1)%6;
  }
  printf("\n");
  return;
}

bool out_queue(Queue *pQ, int *pVal) {
  if(pQ->front == pQ->rear) {
    // printf("空队列\n");
    return false;
  } else {
    *pVal = pQ->pBase[pQ->front];
    pQ->front = (pQ->front + 1) % 6;
    return true;
  }
}








