// 包括数据元素类型的定义和对其操作
typedef char KeyType;

struct ElemType
{
  KeyType key;  //关键字
  int weight;   //权值
};

void visit(ElemType c)
{
  printf("(%c, %d) ", c.key, c.weight);
}

void InputFromFile(FILE *f, ElemType &c)
{
  fscanf(f, "%*c %c %d", &c.key, &c.weight);
}

void InputKey(KeyType &k)
{
  scanf("%c", &k);
  // printf("-----\n");
}