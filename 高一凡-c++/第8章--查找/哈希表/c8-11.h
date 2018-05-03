// 开放定址哈希表的存储结构

int hashsize[] = {11, 19, 29, 37};    //哈希表容量递增表，一个适合的素数序列
struct HashTable
{
  ElemType *elem;
  int count;      //当前数据元素的个数
  int sizeindex;      //hashsize[sizeindex]为当前容量
};

#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1