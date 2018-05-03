Status BiTreeEmpty(BiTree T)
{
  if(T)
    return FALSE;
  else
    return TRUE;
}

/*
重要思想：
  获取二叉树的深度
    运用递归的思想
*/
int BiTreeDepth(BiTree T)
{
  int i, j;
  if(!T)
    return 0;
  i = BiTreeDepth(T->lchild);
  j = BiTreeDepth(T->rchild);
  return i>j ? i+1 : j+1;   //T的深度为其左右子树的深度最大者加1；
}

TElemType Root(BiTree T)
{
  if(BiTreeEmpty(T))
    return Nil;   //返回"空"
  else
    return T->data;   //返回跟节点的值
}

TElemType Value(BiTree p)
{
  return p->data;
}

void Assign(BiTree p, TElemType value)
{
  // 给p节点赋值value
  p->data = value;
}

//定义队列元素为二叉树的指针类型
typedef BiTree QElemType;
#include "c3-2.h"   //链队列
#include "bo3-2.h"  //链队列的基本操作

/*
重要思想：
  匹配二叉树中某个节点的值
    递归的思想和队列进出对的操作
*/
BiTree Point(BiTree T, TElemType s)
{
  // 返回二叉树T中指向元素值为s的节点的指针。无则新增节点
  LinkQueue q;
  QElemType a;
  if(T)
  {
    InitQueue(q);
    EnQueue(q, T);  //跟指针入队
    while(!QueueEmpty(q))
    {
      DeQueue(q, a);  //出对
      if(a->data == s)  //a所指向的节点值为s
      {
        DestroyQueue(q);
        return a;
      }
      if(a->lchild)
        EnQueue(q, a->lchild);
      if(a->rchild)
        EnQueue(q, a->rchild);
    }
    DestroyQueue(q);
  }
  return NULL;
}

TElemType LeftChild(BiTree T, TElemType e)
{
  //  返回e的左孩子的值，若无，返回“空”
  BiTree a;
  if(T)
  {
    a = Point(T, e);  //a是指向节点e的指针
    if(a && a->lchild)  //T中存在节点e且存在e的左孩子节点
      return a->lchild->data;   //返回e的左孩子节点值
  }
  return Nil;
}

TElemType RightChild(BiTree T, TElemType e)
{
  // 返回e的右孩子，若无返回空
  BiTree a;
  if(T)
  {
    a = Point(T, e);
    if(a && a->rchild)
      return a->rchild->data;
  }
  return Nil;
}

Status DeleteChild(BiTree p, int LR)
{
  // 根据LR为0或1，删除T中p所指节点的左或右子树
  if(p)
  {
    if(LR == 0)
      ClearBiTree(p->lchild); //清空p所指节点的左子树
    else if(LR == 1)
      ClearBiTree(p->rchild);
    return OK;
  }
  return ERROR;
}

void PostOrderTraverse(BiTree T, void(* visit)(TElemType))
{
  // 后序递归遍历T
  if(T)
  {
    PostOrderTraverse(T->lchild, visit);
    PostOrderTraverse(T->rchild, visit);
    visit(T->data);
  }
}

void LevelOrderTraverse(BiTree T, void(* visit)(TElemType))
{
  // 层序遍历
  LinkQueue q;
  QElemType a;
  if(T)
  {
    InitQueue(q);
    EnQueue(q, T);  //跟指针入队
    while(!QueueEmpty(q))
    {
      DeQueue(q, a);  //出对元素，赋值给a
      visit(a->data);
      if(a->lchild != NULL)
        EnQueue(q, a->lchild);
      if(a->rchild)
        EnQueue(q, a->rchild);
    }
    printf("\n");
    DestroyQueue(q);
  }
}

void CreateBiTree(BiTree &T)
{
  // 按先序次序输入二叉树中节点的值，构造二叉链表表示的二叉树T
  TElemType ch;
  scanf(form, &ch);
  if(ch == Nil){
    printf("0\n");
    T = NULL;
  }  
  else
  {
    T = (BiTree)malloc(sizeof(BiTNode));
    printf("1\n");
    if(!T)
      exit(-1);
    T->data = ch;
    CreateBiTree(T->lchild);
    CreateBiTree(T->rchild);
  }
}

/*
重要思想：
  获取节点e的双亲
    逆转思想：
      判断节点a是否有孩子节点且孩子节点值为e，若存在，则返回这个节点a。
*/
TElemType Parent(BiTree T, TElemType e)
{
  // 若e是T的非跟节点，则返回它的双亲
  LinkQueue q;
  QElemType a;
  if(T)
  {
    InitQueue(q);
    EnQueue(q, T);
    while(!QueueEmpty(q))
    {
      DeQueue(q, a);
      if((a->lchild && a->lchild->data==e) || (a->rchild && a->rchild->data==e))
        return a->data;
      else  //若未找到e，则入队其左右孩子指针
      {
        if(a->lchild)
          EnQueue(q, a->lchild);
        if(a->rchild)
          EnQueue(q, a->rchild);
      }
    }
  }
  return Nil;
}

TElemType LeftSibling(BiTree T, TElemType e)
{
  // 返回e的左兄弟， 若e是T的左孩子或无左兄弟，返回“空”
  TElemType a;
  BiTree p;
  if(T)
  {
    a = Parent(T, e);   //a为e的双亲
    if(a != Nil)
    {
      p = Point(T, a);  //p为指向a的指针
      if(p->lchild && p->rchild && p->rchild->data == e)  //p存在左右孩子且右孩子值是e
        return p->lchild->data;
    }
  }
  return Nil;
}

TElemType RightSibling(BiTree T, TElemType e)
{
  // 返回e的左兄弟， 若e是T的左孩子或无左兄弟，返回“空”
  TElemType a;
  BiTree p;
  if(T)
  {
    a = Parent(T, e);   //a为e的双亲
    if(a != Nil)
    {
      p = Point(T, a);  //p为指向a的指针
      if(p->lchild && p->rchild && p->lchild->data == e)  //p存在左右孩子且右孩子值是e
        return p->rchild->data;
    }
  }
  return Nil;
}

/*
  二叉树插入节点
    若插入节点为左子树，则二叉树的原左子树成为新插入节点的右子树
*/
Status InsertChild(BiTree p, int LR, BiTree c)
{
  // 根据LR的值为0或1，插入c为T中p所指节点的左或右子树。p所指节点的原有左或右子树则成为c的右子树
  if(p)
  {
    if(LR == 0)   //二叉树c插为p所指节点的左子树
    {
      c->rchild = p->lchild;    //p所指节点的原有左子树成为c的右子树
      p->lchild = c;    //二叉树c成为p的右子树
    }
    else
    {
      c->rchild = p->rchild;  //p所指节点的原右子树成为c的右子树
      p->rchild = c;
    }
    return OK;
  }
  return ERROR;
}

typedef BiTree SElemType;     //定义栈元素为二叉树的指针类型
#include "c3-1.h"
#include "bo3-1.h"

/*
重要思想：
  非递归遍历二叉树
    栈的使用
*/
void InOrderTraverse1(BiTree T, void(* visit)(TElemType))
{
  // 中序遍历二叉树T的非递归算法（利用栈）
  SqStack S;
  InitStack(S);
  while(T || !StackEmpty(S))
  {
    if(T)
    {
      // 跟指针进栈，遍历左子树
      Push(S, T);
      T = T->lchild;
    }
    else  //跟指针退栈，访问跟节点，遍历右子树
    {
      Pop(S, T);  //出栈跟指针
      visit(T->data);
      T = T->rchild;
    }
  }
  printf("\n");
  DestroyStack(S);
}

void InOrderTraverse2(BiTree T, void(* visit)(TElemType))
{
  // 中序遍历二叉树T的非递归算法
  SqStack S;
  BiTree p;
  InitStack(S);
  Push(S, T);   //跟指针进栈
  while(!StackEmpty(S))
  {
    while(GetTop(S, p) && p)
      Push(S, p->lchild);   //向左走到尽头，入栈左孩子指针
    Pop(S, p);
    if(!StackEmpty(S))  //访问节点，向右一步
    {
      Pop(S, p);
      visit(p->data);
      Push(S, p->rchild);   //入栈其右孩子指针
    }
  }
  printf("\n");
  DestroyStack(S);
}





























