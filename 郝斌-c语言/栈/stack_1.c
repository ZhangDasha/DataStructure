#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
  int data;
  struct Node * pNext;
}NODE, *PNODE;

typedef struct Stack{
  PNODE pTop;
  PNODE pBottom;
}STACK, *PSTACK;

// 函数声明
void init(PSTACK);
void push(PSTACK, int);
void traverse(PSTACK);
bool pop(PSTACK, int *);
void clear(PSTACK);

int main(void) {
  int val;
  STACK S;
  init(&S);
  push(&S, 21);
  push(&S, -99);
  push(&S, 1);
  traverse(&S);
  pop(&S, &val);
  printf("出栈的元素是：%d\n", val);
  traverse(&S);
  clear(&S);
  printf("清除栈\n");
  traverse(&S);

  return 0;
}

void init(PSTACK pS) {
  pS->pTop = (PNODE)malloc(sizeof(NODE));
  if(pS->pTop == NULL){
    printf("动态内存分配失败!\n");
    exit(-1);
  } else {
    pS->pBottom = pS->pTop;
    pS->pBottom->pNext = NULL;  //等价于pS->pTop->pNext = NULL; 清空垃圾值指向
  }
  // pBottom与pTop共同指向一个空节点（头节点）
}

// 创建一个新节点，该节点指针域指向头节点，且修改pTop指针域指向此新节点
void push(PSTACK pS, int val) {
  PNODE pNew = (PNODE)malloc(sizeof(NODE));
  pNew->data = val;
  pNew->pNext = pS->pTop;   //只能是pS->pTop；因为每次添加节点都是都过pTop指向实现的
  pS->pTop = pNew;
}

void traverse(PSTACK pS) {
  PNODE p = pS->pTop;
  printf("栈元素是：");
  while(p != pS->pBottom){
    printf("%d ", p->data);
    p = p->pNext;
  }
  printf("\n");
}

// 把pS所指向的栈出栈一次，并把出栈的数据存入pVal
bool pop(PSTACK pS, int * pVal) {
  if(pS->pTop == pS->pBottom){
    return false;
  } else {
    PNODE q = pS->pTop;
    *pVal = q->data;
    pS->pTop = pS->pTop->pNext;
    free(q);
    q = NULL;
    return true;
  }
}

void clear(PSTACK pS) {
  PNODE p = pS->pTop;
  PNODE q = NULL;
  while(p != pS->pBottom) {
    q = p->pNext;
    free(p);
    p = q;
  }
  pS->pTop = pS->pBottom;
}









