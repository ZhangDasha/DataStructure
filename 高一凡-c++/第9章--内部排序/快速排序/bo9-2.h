// 快速排序的函数
void QSort(SqList &L, int low, int high)
{
  int pivotloc;
  if(low < high)
  {
    pivotloc = Partition(L, low, high);
    // 将L.r[low~high]按关键字一分为二，pivotloc是曲轴位置
    // printf("%d\n", pivotloc);
    QSort(L, low, pivotloc-1);
    QSort(L, pivotloc+1, high);
  }
}

void QuickSort(SqList &L)
{
  QSort(L, 1, L.length);
}