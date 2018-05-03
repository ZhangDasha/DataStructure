// 选择排序算法
int SelectMinKey(SqList L, int i)
{
  // 返回在L.r[i~L.length]中最小的记录序号
  int j, k=i;
  KeyType min = L.r[i].key;   //[i]的关键字存在于min
  for(j=i+1; j<=L.length; j++)
    if(L.r[j].key < min)
    {
      k=j;
      min=L.r[j].key;
    }
    return k;
}

void SelectSort(SqList &L)
{
  int i, j;
  RedType t;
  for(i=1; i<=L.length; i++)  //选择第i小的记录，并交互到位
  {
    j = SelectMinKey(L, i);   //每次返回最小值
    if(i!=j)
    {
      t=L.r[i];
      L.r[i] = L.r[j];
      L.r[j] = t;
    }
  }
}

/*
  堆排序将顺序表存储的数据看作为一个完全二叉树上的节点。其根节点存于[1]中。
*/
void HeapAdjust(HeapType &H, int s, int m, Boolean flag)
{
  // 已知H.r[s~m]中记录的关键字除H.r[s].key之外均满足堆的定义，调整H.r[s]的关键字，使H.r[s~m]中记录的关键字均满足堆的定义
  int j;
  H.r[0] = H.r[s];    //利用H的空闲结点存储调整记录，修改
  for(j=2*s; j<=m; j=j*2)  //--------j指向待调整记录[s]的左孩子-------，沿key较大的孩子结点向下筛选
  {
    if(flag)  //大顶堆(升序)
    {
      if(j<m && LT(H.r[j].key, H.r[j+1].key))  //左孩子的关键字小于右孩子的关键字
          j++;    //j指向[s]的右孩子
      if(!LT(H.r[0].key, H.r[j].key))
          break;   //假，执行
    }
    else  //小顶堆
    {
      if(j<m && GT(H.r[j].key, H.r[j+1].key))
        j++;
      if(!GT(H.r[0].key, H.r[j].key))
        break;
    }
    H.r[s] = H.r[j];    //否则，[j]为顶，插入[s]
    s = j;    //[s]的位置向下移到[j]
  }
  H.r[s] = H.r[0];
}

void HeapSort(HeapType &H, Boolean flag)
{
  // 对顺序表H进行堆排序，
  // 当flag为TRUE时，按升序排序，当flag为FALSE，按降序排序
  int i;
  for(i=H.length/2; i>0; i--)   //--------从最后一个非叶子结点到第一个结点----------
    HeapAdjust(H, i, H.length, flag);   //调整H.r[i],使H.r[i~H.length]成为大或小顶堆
  for(i=H.length; i>1; i--)
  {
    H.r[0] = H.r[1];    //将堆顶记录[1]和未完全排序的H.r[1~i]中的最后一个记录[i]交换
    H.r[1] = H.r[i];
    H.r[i] = H.r[0];
    HeapAdjust(H, 1, i-1, flag);
  }
}