#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode {
  char data;
  struct BTNode * pLchild;  //左孩子指针
  struct BTNode * pRchild;
}BTNode, *PBTNode;

// 函数声明
PBTNode createTree(void);
void PreTraverseTree(PBTNode pT);
void InTraverseTree(PBTNode pT);
void PostTraverseTree(PBTNode pT);

int main(void) {
  PBTNode pT = createTree();

  printf("先序遍历是: ");
  PreTraverseTree(pT);
  printf("\n");
  printf("中序遍历是：");
  InTraverseTree(pT);
  printf("\n");
  printf("后序遍历是：");
  PostTraverseTree(pT);
  printf("\n");

  return 0;
}

void PreTraverseTree(PBTNode pT) {
  /*先访问跟节点；
    再先序访问左子树；
    最后先序访问右子树。
  */
  if (pT != NULL) {

    printf("%c", pT->data);

    if (NULL != pT->pLchild) {
      PreTraverseTree(pT->pLchild);
    }
    if (NULL != pT->pRchild) {
      PreTraverseTree(pT->pRchild);
    }   
  }
}
void InTraverseTree(PBTNode pT) {
  /*
    先中序访问左子树；
    再访问跟节点
    最后中序访问右子树
  */
  if (pT != NULL) {
    if (NULL != pT->pLchild) {
      InTraverseTree(pT->pLchild);
    }
    
    printf("%c", pT->data);

    if (NULL != pT->pRchild) {
      InTraverseTree(pT->pRchild);
    }
  }
}

void PostTraverseTree(PBTNode pT) {
  /*
    先后序访问左子树；
    再后序访问右子树；
    最后访问跟节点
  */
  if (pT != NULL) {
    if (NULL != pT->pLchild) {
      PostTraverseTree(pT->pLchild);
    }
    if (NULL != pT->pRchild) {
      PostTraverseTree(pT->pRchild);
    }
    printf("%c", pT->data);
  }
}

PBTNode createTree(void) {
  PBTNode pA = (PBTNode)malloc(sizeof(BTNode));
  PBTNode pB = (PBTNode)malloc(sizeof(BTNode));
  PBTNode pC = (PBTNode)malloc(sizeof(BTNode));
  PBTNode pD = (PBTNode)malloc(sizeof(BTNode));
  PBTNode pE = (PBTNode)malloc(sizeof(BTNode));
  
  pA->data = 'A';
  pB->data = 'B';
  pC->data = 'C';
  pD->data = 'D';
  pE->data = 'E';

  pA->pLchild = pB;
  pA->pRchild = pC;
  pB->pLchild = NULL;
  pB->pRchild = NULL;
  pC->pLchild = pD;
  pC->pRchild = NULL;
  pD->pLchild = NULL;
  pD->pRchild = pE;
  pE->pLchild = NULL;
  pE->pRchild = NULL;

  return pA;
}