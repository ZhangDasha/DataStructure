// 二叉排序树的基本操作

Status SearchBST(BiTree &T, KeyType key, BiTree f, BiTree &p)
{
  /*
    在根指针T所指二叉排序树中递归地查找其关键字等于key的数据元素，若查找成功
    则指针p指向该数据元素的结点， 并返回TRUE，否则指针p指向查找路径上访问的最后一个结点
    并返回FALSE，指针f指向T的双亲，其初始调用值为NULL
  */
  if(!T)    //查找不成功
  {
    p = f;    //p指向查找路径上访问的最后一个结点
    return FALSE;
  }
  else if EQ(key, T->data.key)  //查找成功
  {
    p = T;  //p指向该数据元素结点
    return TRUE;
  }
  else if LT(key, T->data.key)    //key 小于T所指结点的关键字
    return SearchBST(T->lchild, key, T, p);     //在左子树继续递归查找
  else
    return SearchBST(T->rchild, key, T, p);   //在右子树中继续递归查找
}

Status InsertBST(BiTree &T, ElemType e)
{
  //若二叉排序树T中没有关键字等于e.key的元素，插入e并返回TRUE；否则返回FALSE
  BiTree p, s;
  if(!SearchBST(T, e.key, NULL, p))   //查找不成功，p指向查找路径上访问的最后一个叶子结点
  {
    s = (BiTree)malloc(sizeof(BiTNode));
    s->data = e;
    s->lchild = s->rchild = NULL;
    if(!p)
      T = s;
    else if LT(e.key, p->data.key)
      p->lchild = s;
    else
      p->rchild = s;
    return TRUE;
  }
  else
    return FALSE;
}

void Delete(BiTree &p)
{
  // 从二叉排序树中删除p所指结点，并重接它的左或右子树
  BiTree s, q = p;
  if(!p->rchild)  //若p的右子树为空，则只需重接它的左子树
  {
    p = p->lchild;
    free(q);
  }
  else if(!p->lchild)   ////若p的左子树为空，则只需重接它的右子树
  {
    p = p->rchild;
    free(q);
  }
  /*
    若p的左右子树都不为空
      情况1:  待删除结点的左右子树均不空，且左孩子有右子树，则左子树的最右子结点为(小于待删除结点)的次最大值
      情况2:  待删除结点的左右子树均不空，且左孩子没有右子树，则次大值为待删除结点的左结点。
  */
  else
  {
    s = p->lchild;
    while(s->rchild)
    {
      q = s;
      s = s->rchild;
    }
    p->data = s->data;
    if(q!=p)
      q->rchild = s->lchild;
    else
      q->lchild = s->lchild;
    free(s);
  }
}

Status DeleteBST(BiTree &T, KeyType key)
{
  // 若二叉排序树T中存在关键字等于key的数据元素时，则删除
  // 该数据元素结点，并返回TRUE；
  if(!T)
    return FALSE;
  else
  {
    if EQ(key, T->data.key)
      return DeleteBST(T->lchild, key);
    else
      return DeleteBST(T->rchild, key);
  }
}