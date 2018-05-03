int Partition(SqList &L, int low, int high)
{
  // 交换顺序表L中子表L.r[low~high]的记录，使曲轴记录到位,并返回其所在位置，此时在它之前的记录均不大于它
  RedType t;
  KeyType pivotkey;   //曲轴关键字
  pivotkey = L.r[low].key;
  while(low < high)
  {
    // 从表的两端交替的向中间扫描
    while(low<high && L.r[high].key >= pivotkey)    //高端记录的关键字大于曲轴关键字
      high--;
    t=L.r[low];
    L.r[low] = L.r[high];
    L.r[high] = t;
    while(low<high && L.r[low].key <= pivotkey)
      low++;
    t=L.r[low];
    L.r[low] = L.r[high];
    L.r[high] = t;
  }
  // 测试
  // int i;
  // printf("--------------------\n");
  // for(i=1; i<=L.length; i++)
  //   printf("%d ", L.r[i].key);
  // printf("--------------------\n");
  return low;
}