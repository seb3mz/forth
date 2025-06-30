#define MaxVertexNum 100

typedef struct {
    char Vex[MaxVertexNum]; //顶点表
    int Edge[MaxVertexNum][MaxVertexNum]; //邻接矩阵，边表
    int vexnum, arcnum; //图的当前顶点数和边数/弧数
} MGraph;

//判断图 G 是否存在边 <x,y> 或 (x,y)
bool Adjacent(MGraph G, int x, int y);

//列出图 G 中与结点 x 邻接的边
void Neighbors(MGraph G, int x);

//在图 G 中插入顶点 x
bool InsertVertex(MGraph G, int x);

//从图 G 中删除顶点 x
bool DeleteVertex(MGraph G, int x);

//若边 <x,y> 或 (x,y) 不存在，则向图 G 中添加该边
bool AddEdge(MGraph G, int x, int y);

//若边 <x,y> 或 (x,y) 存在，则从图 G 中删除该边
bool RemoveEdge(MGraph G, int x, int y);

//求图 G 中顶点 x 的第一个邻接点，若有则返回顶点号。若 x 没有邻接点或图中不存在 x，则返回 -1
int FirstNeighbor(MGraph G, int x);

//假设图 G 中顶点 y 是顶点 x 的一个邻接点，返回除 y 外顶点 x 的下一个邻接点的顶点号，若 y 是 x 的最后一个邻接点，则返回 -1
int NextNeighbor(MGraph G, int x, int y);

//获取图 G 中边 <x,y> 或 (x,y) 对应的权值
int Get_edge_value(MGraph G, int x, int y);

//设置图 G 中边 <x,y> 或 (x,y) 对应的权值为 v
bool Set_edge_value(MGraph G, int x, int y, int v);