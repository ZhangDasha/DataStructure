// 静态查找表的操作

#include "c1.h"
#include "func8-3.h"
#include "c8-1.h"
#include "c8-2.h"
#include "bo8-1.h"
typedef ElemType TElemType;
#include "c6-1.h"
#include "bo6-1.h"
#define N 100

Status SecondOptimal(BiTree &T, ElemType R[], int sw[], int low, int high)
{
  // 由有序表R[low~high]及其累计权值表sw(其中sw[0] == 0)递归构造次优查找树T。
  /*
    次优二叉树：
      选出一个结点，使得它左右两侧的子数组的权值累加和之差的绝对值最小。
      把这个结点当做根节点，递归地用刚才的左右字数组构造它的左右子树。
  */
  int j, i=low;
  double dw = sw[high] + sw[low-1];
  double min = fabs(sw[high] - sw[low]);   //Pi的最小值，初值设为当low==high时的值
  for(j=low+1; j<=high; j++)      //当low不等于high时，选择最小的Pi值
    if(fabs(dw-sw[j]-sw[j-1]) < min)    //找到小于min的值
    {
      i=j;
      min = fabs(dw - sw[j]-sw[j-1]);
    }
  if(!(T=(BiTree)malloc(sizeof(BiTNode))))
    return ERROR;
  T->data = R[i];
  if(i == low)
    T->lchild = NULL;
  else
    SecondOptimal(T->lchild, R, sw, low, i-1);
  if(i == high)
    T->rchild = NULL;
  else
    SecondOptimal(T->rchild, R, sw, i+1, high);
  return OK;
}


void FindSW(int sw[], SSTable ST)
{
  // 按照有序表ST中各数据元素的Weight域求累计权值数组sw，CreateSOSTree()调用
  int i;
  sw[0] = 0;    //置边界值
  printf("\n sw=0");
  for(i=1; i<=ST.length; i++)
  {
    sw[i] = sw[i-1] + ST.elem[i].weight;
    printf("%5d ", sw[i]);
  }
}

typedef BiTree SOSTree;     //次优查找树采用二叉表的存储结构

void CreateSOSTree(SOSTree &T, SSTable ST)
{
  // 由有序表ST构造一颗次优查找树T。ST的数据元素含有权域weight。
  int sw[N+1];    //累计权值数组
  if(ST.length == 0)    //ST是空表
    T = NULL;   //次优先查找树T为空
  else
  {
    FindSW(sw, ST);   //按照有序表ST中各数据元素的weight域求累计权值表sw
    SecondOptimal(T, ST.elem, sw, 1, ST.length);  //由有序表ST[1~ST.length]及其累计权值表sw
  }
}

Status Search_SOSTree(SOSTree &T, KeyType key)
{
  // 在次优查找树T中查找主关键字等于key的元素.找到则返回OK，T指向该元素
  while(T)
    if(T->data.key == key)
      return OK;
    else if(T->data.key > key)
      T = T->lchild;
    else
      T = T->rchild;
  return FALSE;
}

int main(void)
{
  SSTable st;
  SOSTree t;
  Status i;
  KeyType s;
  Creat_OrdFromFile(st, "f8-3.txt");
  printf("        ");
  Traverse(st, visit);
  CreateSOSTree(t, st);
  printf("\n请输入待查找的字符：");
  InputKey(s);
  i = Search_SOSTree(t, s);
  if(i)
    printf("%c的权值时%d\n", s, t->data.weight);
  else
    printf("表中不存在此字符\n");
  DestroyBiTree(t);
}




























