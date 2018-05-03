// 包括数据元素类型的定义和对它的操作
typedef int KeyType;

struct ElemType
{
  KeyType key;    //关键字
  int others;   //其他数据
};

void visit(ElemType c)
{
  printf("(%d, %d) ", c.key, c.others);
}

void InputFromFile(FILE *f, ElemType &c)
{
  fscanf(f, "%d%d", &c.key, &c.others);
}

void InputKey(KeyType &k)
{
  scanf("%d", &k);
}