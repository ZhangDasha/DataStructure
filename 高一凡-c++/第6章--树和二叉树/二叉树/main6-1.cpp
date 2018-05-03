#define CHAR 1
// #define CHAR 0
#include "func6-1.h"
#include "c6-1.h"
#include "bo6-1.h"
#include "bo6-2.h"
int main(void)
{
  int i;
  BiTree T, p, c;
  TElemType e1, e2;
  InitBiTree(T);
  printf("构造空二叉树后，树空否？%d。树的深度=%d。\n", BiTreeEmpty(T), BiTreeDepth(T));
  e1 = Root(T);   //e1为树的根节点
  // printf("%c\n", Nil);
  if(e1 != Nil)
    printf("二叉树的根为"form"。\n", e1);
  else
    printf("树空， 无根。\n");
#if CHAR
  printf("请按先序输入二叉树：(如： a b # # # a为根节点， b为左子树的二叉树)\n");
#else
  printf("请按先序输入二叉树（如：1 2 0 0 0 表示1为根节点， 2为左子树的二叉树）：\n");
#endif
  CreateBiTree(T);
  printf("建立二叉树后， 树空否？%d。 树的深度=%d。\n", BiTreeEmpty(T), BiTreeDepth(T));
  e1 = Root(T);
  if(e1 != Nil)
    printf("二叉树的根为"form".\n", e1);
  else
    printf("树空， 无根.\n");
  printf("中序递归遍历二叉树：\n");
  InOrderTraverse(T, visit);
  printf("\n后序递归遍历二叉树：\n");
  PostOrderTraverse(T, visit);
  printf("\n请输入一个节点的值：");
  scanf("% *c"form, &e1);
  p = Point(T, e1);
  printf("节点的值为"form, Value(p));
  printf(" \n欲改变此节点的值，请输入新值：");
  scanf("% *c"form, &e2);   //后一个%*c吃掉回车符，为调用CreateBiTree()做准备
  Assign(p, e2);  //将e2的值赋给p所指节点，代替e1
  printf("层序遍历二叉树：\n");
  LevelOrderTraverse(T, visit);
  e1 = Parent(T, e2);
  if(e1 != Nil)
    printf(form"的双亲是"form",", e2, e1);
  else
    printf(form"没有双亲，", e2);
  e1 = LeftChild(T, e2);
  if(e1 != Nil)
    printf("左孩子是"form",", e1);
  else
    printf("没有右孩子,");
  e1 = RightChild(T, e2);
  if(e1 != Nil)
    printf("右孩子是"form",", e1);
  else
    printf("没有右孩子，");
  e1 = LeftSibling(T, e2);
  if(e1 != Nil)
    printf("左兄弟是"form",", e1);
  else
    printf("没有左兄弟,");
  e1 = RightSibling(T, e2);
  if(e1 != Nil)
    printf("右兄弟是"form"。\n", e1);
  else
    printf("没有右兄弟。\n");

  printf("\n");
  InitBiTree(c);   //初始化二叉树c
  printf("请构造一个右子树为空的二叉树c。\n");
#if CHAR
  printf("请按先序输入二叉树(如： a b # # # a为根节点， b为左子树的二叉树): \n");
#else
  printf("请按先序输入二叉树（如：1 2 0 0 0 表示1为根节点， 2为左子树的二叉树）：\n");
#endif
  // 构建节点不正确啊！！
  CreateBiTree(c);
  printf("中序递归遍历二叉树c: \n");
  InOrderTraverse(c, visit);
  printf("树c插到树T中，请输入树T中树c的双亲节点c为左或右子树: ");
  scanf("% *c" form "%d", &e1, &i);
  p = Point(T, e1);
  InsertChild(p, i, c);
  printf("先序递归遍历二叉树：\n");
  PreOrderTraverse(T, visit);
  printf("\n删除子树， 请输入待删除子树的双亲节点 左0或右子树：");
  scanf("% *c" form "%d", &e1, &i);
  p = Point(T, e1);
  DeleteChild(p ,i);
  printf("先序递归遍历二叉树：\n");
  PreOrderTraverse(T, visit);
  printf("\n中序非递归遍历二叉树：\n");
  InOrderTraverse1(T, visit);
  printf("中序非递归遍历二叉树，方法二：\n");
  InOrderTraverse2(T, visit);
  DestroyBiTree(T);
}


























