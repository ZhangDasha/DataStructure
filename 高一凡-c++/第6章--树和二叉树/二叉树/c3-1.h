#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2
struct SqStack
{
  SElemType *base;  //栈底。在栈构造之前和销毁之后，base为null
  SElemType *top;   //栈顶指针
  int stacksize;  //当前已分配的存储空间
};