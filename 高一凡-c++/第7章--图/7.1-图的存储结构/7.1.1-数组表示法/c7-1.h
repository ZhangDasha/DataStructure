// 图的数组（邻接矩阵）存储结构
#define INFINITY INT_MAX  //用整型最大值代替
typedef int VRType;   //定义顶点关系类型为整型，与INFINIT的类型一致
#define MAX_VERTEX_NUM 26   //最大顶点个数
enum GraphKind{DG, DN, UDG, UDN};   //{有向图，有向网，无向图，无向网}
// 弧信息结构
typedef struct
{
  VRType adj;   //顶点关系类型。对无权图，用1是，0否，表示相邻否；对带权图，则为权值
  InfoType * info;  //该弧相关信息的指针
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //二维数组

// 图的结构
struct MGraph
{
  VertexType vexs[MAX_VERTEX_NUM];  //顶点向量
  AdjMatrix arcs;   //邻接矩阵（二维数据）
  int vexnum, arcnum;   //图的当前顶点树和弧树
  GraphKind kind;   //图的种类标志
};