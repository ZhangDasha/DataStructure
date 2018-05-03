/*
  存储弧信息的类型是 AdjMatrix 类型，它是一个二维数组。
  数组的元素类型是结构体 ArcCell 类型，其中包括 VRType 和 InfoType *类型。
  VRType是数字型的，一般是整型，存储0，1，无穷或权值，InfoType 一般是结构体类型，存储弧的相关信息
*/

#define MAX_INFO 20   //弧的相关信息字符串的最大长度+1
typedef char InfoType;  //弧的相关信息类型

// 输入弧的相关信息的函数
void InputArc(InfoType * &arc)
{
  char s[MAX_INFO];   //临时存储空间
  int m;
  printf("请输入该弧的相关信息%d：", MAX_INFO);
  gets(s);   //输入字符串（包括空格）
  m = strlen(s);  //字符串长度
  if(m)
  {
    arc = (char *)malloc((m+1)*sizeof(char));
    strcpy(arc, s);   //复制s到arc
  }
}

// 由文件输入弧的相关信息
void InputArcFromFile(FILE *f, InfoType * &arc)
{
  char s[MAX_INFO];
  fgets(s, MAX_INFO, f);    //由文件输入字符串包括空格
  arc = (char *)malloc((strlen(s)+1)*sizeof(char));
  strcpy(arc, s);
}

//输出弧的相关信息函数
void OutputArc(InfoType * arc)
{
  printf("%s\n", arc);
}