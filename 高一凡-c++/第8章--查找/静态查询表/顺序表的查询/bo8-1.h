// 静态查询表的基本操作
void Creat_SeqFromFile(SSTable &ST, char *filename)
{
  // 由数据文件构造静态顺序查询表ST
  int i;
  FILE *f;
  f = fopen(filename, "r");
  fscanf(f, "%d", &ST.length);    //由文件输入数据元素个数
  ST.elem = (ElemType *)calloc(ST.length+1, sizeof(ElemType));
  if(!ST.elem)
    exit(-1);
  for(i=1; i<=ST.length; i++)
    InputFromFile(f, ST.elem[i]);
  fclose(f);
}

void Ascend(SSTable &ST)
{
  // 重建静态查询表为按关键字非降序排序
  int i, j, k;
  for(i=1; i<ST.length; i++)
  {
    k=i;  //k存当前关键字最小值的序号
    ST.elem[0] = ST.elem[i];  //待比较值存【0】单元
    for(j=i+1; j<=ST.length; j++)
      if LT(ST.elem[j].key, ST.elem[0].key)
      {
        k=j;
        ST.elem[0] = ST.elem[j];    //将当前元素的值存【0】单元
      }
    if(k != i)    //有比【i】更小的值则交换
    {
      ST.elem[k] = ST.elem[i];
      ST.elem[i] = ST.elem[0];
    }
  }
}

void Creat_OrdFromFile(SSTable &ST, char *filename)
{
  // 由含n个数据元素的数组r构建按关键字非降序查找表st
  Creat_SeqFromFile(ST, filename);
  Ascend(ST);
}

Status Destroy(SSTable &ST)
{
  // 销毁表ST
  free(ST.elem);
  ST.elem  = NULL;
  ST.length = 0;
  return OK;
}

int Search_Seq(SSTable ST, KeyType key)
{
  // 在顺序表st中顺序查找其主关键字等于key的数据元素
  int i=ST.length;
  ST.elem[0].key = key;   //哨兵，关键字存【0】单元
  while( i >= 0)
  {
    if (ST.elem[i].key != key)
     {
       i--;
       continue;
     }
    else
      return i;
  }
}

int Search_Bin(SSTable ST, KeyType key)
{
  // 在有序表ST中折半查找关键字等于key的数据元素
  int mid, low=1, high=ST.length;
  while(low <= high)
  {
    mid = (low + high)/2;
    if EQ(key, ST.elem[mid].key)
      return mid;
    else if LT(key, ST.elem[mid].key)
      high = mid-1;
    else
      low = mid + 1;
  }
  return 0;
}

void Traverse(SSTable ST, void(* visit)(ElemType))
{
  int i;
  ElemType *p = ++ST.elem;
  for(i=1; i<=ST.length; i++)
    visit(* p++);
}