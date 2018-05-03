/*
  处理冲突的方法：
      由于哈希函数是杂凑函数，它有很大的随意性，有可能在一个哈希地址上分配多个数据，
    这种情况称为冲突。处理冲突，就是把原来分配到一个哈希地址上的多个数据，根据某种
    原则分配到不同的地址上。
*/

// 哈希函数的基本操作

void InitHashTable(HashTable &H)
{
  // 构造一个空的哈希表
  int i;
  H.count = 0;    //当前元素的个数为0
  H.sizeindex = 0;
  m = hashsize[0];    //哈希表表长，全局变量
  H.elem = (ElemType *)malloc(m * sizeof(ElemType));
  if(!H.elem)
    exit(-1);
  for(i=0; i<m; i++)
    H.elem[i].key = NULL_KEY;     //未填记录的标志
}

void DestroyHashTable(HashTable &H)
{
  free(H.elem);
  H.elem = NULL;
  H.count = 0;
  H.sizeindex = 0;
}

unsigned Hash(KeyType K)
{
  // 一个简单的韩系函数,m表长
  return K%m;
}

int d(int i)
{
  //增量序列函数,在以下三行中根据需要选去一行，其余两行作为注释
  return i;     //线形探测再散列
  // return ((i+1)/2) * ((i+1)/2) * (int)pow(-1, i-1);     //二次探测再散列
  // return rand();     //伪随机探测再散列
}


void collision(KeyType K, int &p, int i)
{
  p = (Hash(K) + d(i))%m;     //开放定址处理冲突
}

Status SearchHash(HashTable H, KeyType K, int &p, int &c)
{
  /*在开放定址哈希表H中查找关键字为K的元素，若查找成功，以p指示待查数据
  元素在表中位置，并返回SUCCESS；否则，以p指示插入位置，并返回UNSUCCESS
  c用于计冲突次数，其初值置零，供建表插入时参考
  */
  c = 0;
  p = Hash(K);    //求得哈希地址
  while(H.elem[p].key != NULL_KEY && !EQ(K, H.elem[p].key))
  {
    // 该位置中天➡️记录，并且与待查找的关键字不相等
    c++;
    if(c < m)     //在H中有可能找到插入地址
      collision(K, p, c);
    else
      break;
  }
  if EQ(K, H.elem[p].key)
    return SUCCESS;
  else
    return UNSUCCESS;
}

void RecreateHashTable(HashTable&);     //对函数RecreateHashTable()的声明

Status InsertHash(HashTable &H, ElemType e)
{
  // 查找不成功时插入数据元素e到开放定址哈希表H中，并返回OK；
  // 若冲突次数过大，则重建哈希表
  int p, c = 0;
  if(SearchHash(H, e.key, p, c))
    return DUPLICATE;
  else if(c<hashsize[H.sizeindex]/2)
  {
    H.elem[p] = e;
    ++H.count;
    return OK;
  }
  else
  {
    RecreateHashTable(H);
    return UNSUCCESS;
  }
}

void RecreateHashTable(HashTable &H)
{
  // 重建哈希表H
  int i, count = H.count;
  ElemType *p, *elem = (ElemType *)malloc(count * sizeof(ElemType));
  // 动态生成存放哈希表H原有数据的空间
  p = elem;
  for(i=0; i<m; i++)
    if((H.elem + i)->key != NULL_KEY)   //H在该单元有数据
      *p++ = *(H.elem + i);   //将数据依次存入elem
  H.count = 0;
  H.sizeindex++;
  m = hashsize[H.sizeindex];
  H.elem = (ElemType *)realloc(H.elem, m*sizeof(ElemType));
  // 以新的存储容量重新生成哈希表
  for(i=0; i<m; i++)
    H.elem[i].key = NULL_KEY;
  for(p=elem; p<elem+count; p++)
    InsertHash(H, *p);
  free(elem);
}

void TraverseHash(HashTable H, void(*visit)(int, ElemType))
{
  int i;
  printf("哈希地址0～%d\n", m-1);
  for(i=0; i<m; i++)
    if(H.elem[i].key != NULL_KEY)
      visit(i, H.elem[i]);
}

