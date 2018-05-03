int Partition(SqList &L, int low, int high)  //改进版
{
  KeyType pivotkey;
  pivotkey = L.r[low].key;
  L.r[0] = L.r[low];
  while(low < high)
  {
    while(low<high && L.r[high].key>=pivotkey)
      high--;
    L.r[low] = L.r[high];   //将比关键字小的记录移到低端，曲轴在[0]不动.
    while(low<high && L.r[low].key<=pivotkey)
      low++;
    L.r[high] = L.r[low];
  }
  L.r[low] = L.r[0];  //曲轴记录到位
  // int i;
  // printf("--------------------\n");
  // for(i=1; i<=L.length; i++)
  //   printf("%d ", L.r[i].key);
  // printf("--------------------\n");
  return low;
}