#define LIST_INIT_SIZE 10 //线性表存储空间初始分配量
#define LIST_INCREMENT 2 //分配增量
struct SqList
{
  ElemType * elem;  //第一个元素的存储地址
  int length;
  int listsize;
};