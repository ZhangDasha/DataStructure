// 图的邻接矩阵存储和基本操作

int LocateVex(MGraph G, VertexType u)
{
  // 若G中存在顶点u，则返回该顶点在图中位置；否则返回-1
  int i;
  for(i=0; i<G.vexnum; i++)
    // strcmp函数用于比较两个字符串
    if(strcmp(u.name, G.vexs[i].name) == 0)   //顶点与给定的u的顶点名称相同
      return i;   //返回顶点序号
  return -1;
}

void CreateDG(MGraph &G)
{
  // 采用邻接矩阵表示法，构造有向图
  int i, j, k, IncInfo;   // IncInfo 为0则弧不含相关信息
  VertexType v1, v2;
  printf("请输入有向图G的顶点数， 弧数，弧是否含有相关信息: ");
  scanf("%d, %d, %d", &G.vexnum, &G.arcnum, &IncInfo);
  printf("请输入%d个顶点的值：\n", G.vexnum, MAX_NAME);
  for(i=0; i<G.vexnum; i++)
    Input(G.vexs[i]);
  for(i=0; i<G.vexnum; i++)   //初始化二维邻接矩阵弧信息
    for(j=0; j<G.vexnum; j++)
    {
      G.arcs[i][j].adj = 0;   //图， 不相邻
      G.arcs[i][j].info = NULL;     //无相关信息
    }
  printf("请输入%d条弧的弧尾 弧头： \n", G.arcnum);
  for(k=0; k<G.arcnum; k++)
  {
    scanf("%s%s% *c", v1.name, v2.name);
    i = LocateVex(G, v1);   //弧尾的序号
    j = LocateVex(G, v2);   //弧头的序号
    G.arcs[i][j].adj = 1;   //有向图
    if(IncInfo)
      InputArc(G.arcs[i][j].info);    //动态生成存储空间，输入弧的相关信息，在func7-2.h
  }
  G.kind = DG;
}

void CreateDN(MGraph &G)
{
  // 采用邻接矩阵，构造有向网
  int i, j, k, IncInfo;
  VRType w;   //顶点关系类型
  VertexType v1, v2;
  printf("请输入有向网G的顶点数， 弧数，弧是否含有相关信息:");
  scanf("%d, %d, %d", &G.vexnum, &G.arcnum, &IncInfo);
  printf("请输入%d个顶点的值：\n", G.vexnum, MAX_NAME);
  for(i=0; i<G.vexnum; i++)
    Input(G.vexs[i]);
  for(i=0; i<G.vexnum; i++)   //初始化二维邻接矩阵弧信息
    for(j=0; j<G.vexnum; j++)
    {
      G.arcs[i][j].adj = INFINITY;   //网， 不相邻
      G.arcs[i][j].info = NULL;     //无相关信息
    }
  printf("请输入%d条弧的弧尾 弧头 权值： \n", G.arcnum);
  for(k=0; k<G.arcnum; k++)
  {
    scanf("%s %s %d % *c", v1.name, v2.name, &w);
    i = LocateVex(G, v1);   //弧尾的序号
    j = LocateVex(G, v2);   //弧头的序号
    G.arcs[i][j].adj = w;   //有向图
    if(IncInfo)
      InputArc(G.arcs[i][j].info);    //动态生成存储空间，输入弧的相关信息，在func7-2.h
  }
  G.kind = DN;
}

void CreateUDG(MGraph &G)
{
  // 采用邻接矩阵，构造无向图
  int i, j, k, IncInfo;   // IncInfo 为0则弧不含相关信息
  VertexType v1, v2;
  printf("请输入无向图G的顶点数， 边数，边是否含有相关信息: ");
  scanf("%d, %d, %d", &G.vexnum, &G.arcnum, &IncInfo);
  printf("请输入%d个顶点的值：\n", G.vexnum, MAX_NAME);
  for(i=0; i<G.vexnum; i++)
    Input(G.vexs[i]);
  for(i=0; i<G.vexnum; i++)   //初始化二维邻接矩阵弧信息
    for(j=0; j<G.vexnum; j++)
    {
      G.arcs[i][j].adj = 0;   //图， 不相邻
      G.arcs[i][j].info = NULL;     //无相关信息
    }
  printf("请输入%d条边的顶点1顶点2: \n", G.arcnum);
  for(k=0; k<G.arcnum; k++)
  {
    scanf("%s %s % *c", v1.name, v2.name);
    i = LocateVex(G, v1);   //弧尾的序号
    j = LocateVex(G, v2);   //弧头的序号
    G.arcs[i][j].adj = 1;   //有向图
    if(IncInfo)
      InputArc(G.arcs[i][j].info);    //动态生成存储空间，输入弧的相关信息，在func7-2.h
    G.arcs[j][i] = G.arcs[i][j];  //无向， 两个单元的信息相同
  }
  G.kind = UDG;
}

void CreateUDN(MGraph &G)
{
  // 采用数组表示法，构造无相网G
  int i, j, k, IncInfo;
  VRType w;   //顶点关系类型
  VertexType v1, v2;
  printf("请输入无向网G的顶点数， 边数，边是否含有相关信息:");
  scanf("%d, %d, %d", &G.vexnum, &G.arcnum, &IncInfo);
  printf("请输入%d个顶点的值：\n", G.vexnum, MAX_NAME);
  for(i=0; i<G.vexnum; i++)
    Input(G.vexs[i]);
  for(i=0; i<G.vexnum; i++)   //初始化二维邻接矩阵弧信息
    for(j=0; j<G.vexnum; j++)
    {
      G.arcs[i][j].adj = INFINITY;   //网， 不相邻
      G.arcs[i][j].info = NULL;     //无相关信息
    }
  printf("请输入%d条边的顶点1顶点2权值: \n", G.arcnum);
  for(k=0; k<G.arcnum; k++)
  {
    scanf("%s %s %d % *c", v1.name, v2.name, &w);
    i = LocateVex(G, v1);   //弧尾的序号
    j = LocateVex(G, v2);   //弧头的序号
    G.arcs[i][j].adj = w;   //有向图
    if(IncInfo)
      InputArc(G.arcs[i][j].info);    //动态生成存储空间，输入弧的相关信息，在func7-2.h
    G.arcs[j][i] = G.arcs[i][j];  //无向， 两个单元的信息相同
  }
  G.kind = UDN;
}

void CreateGraph(MGraph &G)
{
  // 采用邻接矩阵法，构造图G
  printf("请输入图G的类型（有向图：0， 有向网：1，无向图：2 无相网：3）：");
  scanf("%d", &G.kind);
  switch(G.kind)    //根据图G的类型，调用不同的构造图的函数
  {
    case DG: CreateDG(G);
             break;
    case DN: CreateDN(G);
             break;
    case UDG: CreateUDG(G);
              break;
    case UDN: CreateUDN(G);
              break;
  }
}

VertexType GetVex(MGraph G, int v)
{
  if(v >= G.vexnum || v<0)    //图G中不存在序号为v的顶点
    exit(-1);
  return G.vexs[v];
}

Status PutVex(MGraph &G, VertexType v, VertexType value)
{
  // 对v赋新值
  int k = LocateVex(G, v);  //k为顶点v在图G中的序号
  if(k<0)
    return ERROR;
  G.vexs[k] = value;  //将新值赋给顶点v
  return OK;
}

int FirstAdjVex(MGraph G, int v)
{
  // 返回v的第一个邻接顶点的序号，若没有返回-1
  int i;
  VRType j=0; //顶点关系类型，图
  if(G.kind % 2)  //网
    j = INFINITY;
  for(i=0; i<G.vexnum; i++)
    if(G.arcs[v][i].adj != j)   //是第一个邻接顶点
      return i;
  return -1;
}

int NextAdjVex(MGraph G, int v, int w)
{
  // 返回v的下一个邻接顶点序号, 若w是v的最后一个邻接顶点，则返回-1
  int i;
  VRType j =0;
  if(G.kind % 2)
    j = INFINITY;
  for(i=w+1; i<G.vexnum; i++)
    if(G.arcs[v][i].adj != j)
      return i;
  return -1;
}

void InsertVex(MGraph &G, VertexType v)
{
  // 在图G中添加新顶点
  int i;
  VRType j =0;
  if(G.kind % 2)
    j = INFINITY;
  G.vexs[G.vexnum] = v; //将值v赋给新顶点
  for(i=0; i<G.vexnum; i++)
  {
    G.arcs[G.vexnum][i].adj = G.arcs[i][G.vexnum].adj = j;  //初始化新增行，新增列邻接矩阵的值（无限大，无弧）
    G.arcs[G.vexnum][i].info = G.arcs[i][G.vexnum].info = NULL;   //初始化相关信息指针
  }
  G.vexnum++;
}

Status InsertArc(MGraph &G, VertexType v, VertexType w)
{
  // 在G中添加弧<v, w>，若G是无向的，则还添加对称弧<w, v>
  int i, v1, w1;
  v1 = LocateVex(G, v);   //弧尾顶点
  w1 = LocateVex(G, w);   //弧头顶点
  if(v1<0 || w1<0)
    return ERROR;
  G.arcnum++;
  if(G.kind % 2)  //网
  {
    printf("请输入此弧的权值：");
    scanf("%d", &G.arcs[v1][w1].adj);
  }
  else
    G.arcs[v1][w1].adj = 1;
  printf("是否有该弧的相关信息：");
  scanf("%d% *c", &i);
  if(i)
    InputArc(G.arcs[v1][w1].info);   //动态生成存储空间，输入弧的相关信息
  if(G.kind > 1)  //无向
    G.arcs[w1][v1] = G.arcs[v1][w1];
  return OK;
}

Status DeleteArc(MGraph &G, VertexType v, VertexType w)
{
  // 在G中删除弧<v, w>，若G是无向的，则还删除对称弧<w, v>
  int v1, w1;
  VRType j=0;
  if(G.kind % 2)
    j = INFINITY;
  v1 = LocateVex(G, v);
  w1 = LocateVex(G, w);
  if(v1<0 || w1<0)
    return ERROR;
  if(G.arcs[v1][w1].adj != j)   //有弧<v, w>
  {
    G.arcs[v1][w1].adj = j;   //删除弧<v,w>
    if(G.arcs[v1][w1].info)   //有相关信息
    {
      free(G.arcs[v1][w1].info);
      G.arcs[v1][w1].info = NULL;
    }
    // 无向
    if(G.kind >= 2)
      G.arcs[w1][v1] = G.arcs[v1][w1];
    G.arcnum--;
  }
  return OK;
}

Status DeleteVex(MGraph &G, VertexType v)
{
  // 删除G中顶点v及其相关的弧
  int i, j, k;
  k = LocateVex(G, v);
  if(k<0)
    return ERROR;
  for(i=0; i<G.vexnum; i++)
    DeleteArc(G, v, G.vexs[i]);   //删除由顶点v发出的所有弧
  // 有向时
  if(G.kind < 2)
  {
    for(i=0; i<G.vexnum; i++)
      DeleteArc(G, G.vexs[i], v);    //删除发向顶点v的所有弧
  }
  for(j=k+1; j<G.vexnum; j++)
    G.vexs[j-1] = G.vexs[j];    //序号k后面的顶点向量依次前移
  
  for(i=0; i<G.vexnum; i++)
    for(j=k+1; j<G.vexnum; j++)
      G.arcs[i][j-1] = G.arcs[i][j];    //移动待删除顶点之右的矩阵元素
  for(i=0; i<G.vexnum; i++)
    for(j=k+1; j<G.vexnum; j++)
      G.arcs[j-1][i] = G.arcs[j][i];    //移动待删除顶点之下的矩阵元素
  G.vexnum--;
  return OK;
}


void DestroyGraph(MGraph &G)
{
  int i=0;
  for(i=G.vexnum-1; i>=0; i--)
    DeleteVex(G, G.vexs[i]);
}

void Display(MGraph G)
{
  int i, j;
  char s[12] = "无向图",  s1[4]="边";
  switch(G.kind)
  {
    case DG:  strcpy(s, "有向图");
              strcpy(s1, "弧");
              break;
    case DN:  strcpy(s, "有向网");
              strcpy(s1, "弧");
              break;
    case UDG:  strcpy(s, "无向图");
    case UDN: ;
  }
  printf("%d个顶点%d条%s的%s。顶点依次是：", G.vexnum, G.arcnum, s1, s);
  for(i=0; i<G.vexnum; i++)
    visit(GetVex(G, i));  //根据顶点信息的类型，访问第i个顶点
  printf("\nG.arcs.adj:\n");
  for(i=0; i<G.vexnum; i++)   //输出二维数组G.arcs.adj
  {
    for(j=0; j<G.vexnum; j++)
      if(G.arcs[i][j].adj == INFINITY)
        printf("∞");
      else
        printf(" %4d", G.arcs[i][j].adj);
      printf("\n");
  }
  printf("G.arcs.info: \n");
  if(G.kind < 2)
    printf("弧尾 弧头 该%s的信息：\n", s1);
  else
    printf("顶点1顶点2该%s的信息：\n", s1);
  for(i=0; i<G.vexnum; i++)
    if(G.kind < 2)
    {
      for(j=0; j<G.vexnum; j++)
        if(G.arcs[i][j].info)
        {
          printf(" %5s%5s", G.vexs[i].name, G.vexs[j].name);
          OutputArc(G.arcs[i][j].info);   //输出弧的相关信息
        }
    }
    else
    {
      for(j=i+1; j<G.vexnum; j++)
        if(G.arcs[i][j].info)
        {
          printf("%5s %5s", G.vexs[i].name, G.vexs[j].name);
          OutputArc(G.arcs[i][j].info);
        }
    }
}

void CreateFromFile(MGraph &G, char *filename, int IncInfo)
{
  // 采用邻接矩阵，由文件构造图或网G，IncInfo=0或1，表示弧无或相关信息
  int i, j, k;
  VRType w = 0;
  VertexType v1, v2;
  FILE *f;    //文件指针类型
  f = fopen(filename, "r");
  fscanf(f, "%d", &G.kind);   //输入G的类型
  if(G.kind % 2)
    w = INFINITY;
  fscanf(f, "%d", &G.vexnum);   //输入G的顶点树
  for(i=0; i<G.vexnum; i++)
    InputFromFile(f, G.vexs[i]);
  fscanf(f,"%d", &G.arcnum);    //输入G的弧数
  for(i=0; i<G.vexnum; i++)     //初始化二维邻接矩阵
    for(j=0; j<G.vexnum; j++)
    {
      G.arcs[i][j].adj = w;     //不相邻
      G.arcs[i][j].info = NULL;   //没有相关信息
    }
  if(!(G.kind%2))
    w=1;
  for(k=0; k<G.arcnum; k++)
  {
    fscanf(f, "%s %s", v1.name, v2.name);   //输入弧尾，弧头名称
    if(G.kind %2)
      fscanf(f, "%d", &w);
    i = LocateVex(G, v1);
    j = LocateVex(G, v2);
    G.arcs[i][j].adj = w;   //权值
    if(IncInfo)
      InputArcFromFile(f, G.arcs[i][j].info);
    if(G.kind > 1)  //无向
      G.arcs[j][i] = G.arcs[i][j];
  }
  fclose(f);
}