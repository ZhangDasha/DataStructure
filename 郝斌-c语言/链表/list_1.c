#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
  int data;   //数据域
  struct Node * pNext;  //指针域
}NODE, *PNODE;
// NODE === struct Node
// PNODE === struct Node *

// 函数声明
PNODE create_list();
void traverse_list(PNODE pHead);
bool is_empty(PNODE);
int length_list(PNODE);
bool insert_list(PNODE, int, int);
bool delete_list(PNODE, int, int *);
void sort_list(PNODE);

int main(void){
  int val;
  PNODE pHead = NULL;
  pHead = create_list();  //创建一个非循环的单链表，并将这个单链表的头节点地址赋值给pHead
  traverse_list(pHead);
  int len = length_list(pHead);
  printf("链表的长度是：%d\n", len);

  sort_list(pHead);
  printf("排序后：");
  traverse_list(pHead);

  insert_list(pHead, 3, 33);
  printf("插入节点后：");
  traverse_list(pHead);

  delete_list(pHead, 4, &val);
  printf("删除了值：%d\n", val);
  traverse_list(pHead);

  return 0;
}

PNODE create_list() {
  int len;
  int i;
  int val;  //临时存放用户输入节点值
  PNODE pHead = (PNODE)malloc(sizeof(NODE));  //创建头节点
  if(NULL == pHead){
    printf("分配失败，程序终止!\n");
    exit(-1);
  }
  PNODE pTail = pHead;
  pTail->pNext = NULL;

  printf("请输入你想要创建的链表节点的个数：len = ");
  scanf("%d", &len);
  for(i=0; i<len; i++){
    printf("请输入第%d个节点的值: ", i+1);
    scanf("%d", &val);
    PNODE pNew = (PNODE)malloc(sizeof(NODE));  //创建新节点
    if(NULL == pNew) {
      printf("分配失败，程序终止!\n");
      exit(-1);
    }
    //  思路：创建的每一个新节点都是为节点
    pNew->data = val;
    pTail->pNext = pNew;
    pNew->pNext = NULL;
    pTail = pNew;
  }
  return pHead;
}

void traverse_list(PNODE pHead){
  PNODE p = pHead->pNext;
  while(NULL != p) {
    printf("%d ", p->data);
    p = p->pNext;
  }
  printf("\n");
}

bool is_empty(PNODE pHead) {
  if(NULL == pHead->pNext)
    return true;
  else
    return false;
}

int length_list(PNODE pHead) {
  PNODE p = pHead->pNext;
  int len = 0;
  while(NULL != p){
    len++;
    p = p->pNext;
  }
  return len;
}

void sort_list(PNODE pHead) {
  int i, j, t;
  PNODE p, q;
  int len = length_list(pHead);
  // 参考数组的排序
  for(i=0,p=pHead->pNext; i<len-1; i++,p=p->pNext){
    for(j=i+1,q=p->pNext; j<len; j++,q=q->pNext){
      if(p->data > q->data){
        t = p->data;
        p->data = q->data;
        q->data = t;
      }
    }
  }
  return;
}

// 在pHead所指向的链表的第pos个节点的前面插入一个新节点，该节点的值是val，并且pos的值是从1开始
bool insert_list(PNODE pHead, int pos, int val) {
  int i=0;
  PNODE p = pHead;
  while(NULL != p && i<pos-1){
    // 找到要插入的位置
    p = p->pNext;
    i++;
  }
  if(NULL == p || i<pos-1){
    return false;
  }
  PNODE pNew = (PNODE)malloc(sizeof(NODE));
  if(NULL == pNew){
    printf("动态内存分配失败！\n");
    exit(-1);
  }
  pNew->data = val;
  PNODE q = p->pNext;
  p->pNext = pNew;
  pNew->pNext = q;
  return true;
}

bool delete_list(PNODE pHead, int pos, int * pVal){
  int i=0;
  PNODE p = pHead;
  while(NULL != p->pNext && i<pos-1){
    p = p->pNext;
    i++;
  }
  if(NULL == p->pNext || i<pos-1){
    return false;
  }
  PNODE q = p->pNext;
  *pVal = q->data;
  p->pNext = p->pNext->pNext;
  free(q);
  q = NULL;
  return true;
}










