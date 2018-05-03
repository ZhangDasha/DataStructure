// 包括顶点信息类型的定义及对它的操作
#define MAX_NAME 9   //顶点名称字符串的最大长度+1

/*
  存储顶点信息的类型是 VertexType 类型，用来存储有关顶点的一切信息，如顶点名称、顶点坐标等。
*/
struct VertexType
{
  char name[MAX_NAME];
};

void visit(VertexType ver)  //与之配套的访问顶点的函数
{
  printf("%s", ver.name);
}

void Input(VertexType &ver) //与之配套的输入顶点信息的函数
{
  scanf("%s", ver.name);
}

void InputFromFile(FILE *f, VertexType &ver)  //与之配套的文件输入顶点信息函数
{
  fscanf(f, "%s", ver.name);
}
