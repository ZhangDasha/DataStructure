// 在主程序中选择节点的类型，访问树节点的函数
#include "c1.h"
#if CHAR  //CHAR值为非零， 节点类型为字符
  typedef char TElemType;
  TElemType Nil = '#';  //设字符型以#为空
  #define form "%c"   //输入输出的格式为%c
#else   //CHAR值为非零
  typedef int TElemType;
  TElemType Nil = 0;
  #define form "%d"
#endif

void visit(TElemType e)
{
  printf(form" ", e);   //定义CHAR为1时，以字符格式输出，为0时以整型格式输出
}
