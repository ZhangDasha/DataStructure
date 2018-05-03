// 顺序表排序的函数、所以最终排列好后的顺序表都是递增的

void InsertSort(SqList &L)
{
  int i, j;
  // 假设第一个记录有序，因此从第二个记录开始
  for(i=2; i<=L.length; i++)
    if LT(L.r[i].key, L.r[i-1].key)   //当前值小于前面已排好序的最大值（末值）
    {
      // 将当前L.r[i]插入到，前面已经就绪的[1~i-1]的有序子表中
      L.r[0] = L.r[i];   //将当前记录赋值为哨兵
      // 在[1~i-1]的有序表中查找大于哨兵的位置
      for(j=i-1; LT(L.r[0].key, L.r[j].key); j--)
       {
        //若哨兵小于记录，记录后移一个单元，否则退出循环
        L.r[j+1] = L.r[j];
       }
       // 将哨兵插入当前位置
      L.r[j+1] = L.r[0];
    }
}

void BInsertSort(SqList &L)
{
  // 对顺序表L作折半插入排序
  int i, j, m, low, high;
  for(i=2; i<=L.length; i++)  //从第二个记录开始
    if LT(L.r[i].key, L.r[i-1].key)
    {
      L.r[0] = L.r[i];
      // low为已排序好子记录的第一个，high为最后一个
      low = 1;
      high = i-1;

      // 此处为折半查找
      while(low <= high)
      {
        m = (low + high)/2;
        if LT(L.r[0].key, L.r[m].key)
          high = m-1;   //插入点在高半区
        else
          low = m+1;    //插入点在低半区
      }//low>high，退出while循环，high+1是插入位置

      for(j=i-1; j>=high+1; j--)
        L.r[j+1] = L.r[j];
      L.r[high+1] = L.r[0];     //将哨兵值插入到high+1位置
    }
}

// 循环顺序表
void P2_InsertSort(SqList &L, int flag)
{
  // 2-路插入排序(flag = 0)和改进的2-路插入排序
  // （flag = 1， 当L.r[1]是待排序记录中关键字最小和最大的记录时，仍有优越性）
  int i, j, first, final, mid=0;
  RedType *d;
  d = (RedType *)malloc(L.length * sizeof(RedType));
  d[0] = L.r[1];    //设L的第一个记录为d中排好序的记录
  first = final = 0;
  for(i=2; i<=L.length; i++)
  {
    if(flag)  //针对改进后的2-路插入排序
    {
      if(first > final)
        j = L.length;
      else
        j=0;
      mid = (first + final + j)/2 % L.length;   //d的中间记录的位置
    }

    if(L.r[i].key < d[mid].key)
    {
      j=first;
      first = (first-1 + L.length)%L.length;    //first前移
      while(L.r[i].key > d[j].key)  //待插记录大于j所指记录
      {
        d[(j-1 + L.length)%L.length] = d[j];
        j = (j+1)%L.length;
      }
      d[(j-1 + L.length)%L.length] = L.r[i];
    }
    else
    {
      j = final++;
      while(L.r[i].key < d[j].key)
      {
        d[(j+1)%L.length] = d[j];
        j = (j-1 + L.length)%L.length;
      }
      d[(j+1)%L.length] = L.r[i];
    }
  }
  for(i=1; i<=L.length; i++)
    L.r[i] = d[(first+i-1)%L.length];   //线性关系
  free(d);
}
