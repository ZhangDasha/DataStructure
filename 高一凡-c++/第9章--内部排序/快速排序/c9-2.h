// 顺序表类型的类型结构
#define MAX_SIZE 20
struct SqList   //顺序表类型
{
  RedType r[MAX_SIZE + 1];    //r[0]闲置或用作哨兵的单元
  int length;
};