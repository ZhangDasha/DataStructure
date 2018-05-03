typedef struct QNode
{
  QElemType data;
  QNode * next;
}*QueuePtr;

// LinkQueue类型
struct LinkQueue
{
  QueuePtr front;   //对头指针，出对
  QueuePtr rear;    //队尾指针，入队
};