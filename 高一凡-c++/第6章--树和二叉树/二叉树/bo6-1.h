#define ClearBiTree DestroyBiTree   //清空二叉树和销毁二叉树的操作一样

void InitBiTree(BiTree &T)
{
  T = NULL;
}

void DestroyBiTree(BiTree &T)
{
  if(T)
  {
    DestroyBiTree(T->lchild);   //递归销毁左子树
    DestroyBiTree(T->rchild);   //递归销毁右子树
    free(T);
    T = NULL;
  }
}

void PreOrderTraverse(BiTree T, void(*visit)(TElemType))
{
  // 先序遍历T，对每个节点调用函数visit
  if(T)
  {
    visit(T->data);
    PreOrderTraverse(T->lchild, visit);
    PreOrderTraverse(T->rchild, visit);
  }
}

void InOrderTraverse(BiTree T, void(*visit)(TElemType))
{
  //  中序遍历T
  if(T)
  {
    InOrderTraverse(T->lchild, visit);
    visit(T->data);
    InOrderTraverse(T->rchild, visit);
  }
}

