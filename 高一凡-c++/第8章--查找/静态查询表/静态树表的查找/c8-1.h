// 静态查询表的顺序存储结构
struct SSTable
{
  ElemType *elem;   //数据元素存储空间基址，建表时按实际长度分配，0号单元留空
  int length;
};