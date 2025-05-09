#define MaxVertexNum 100

typedef struct {
    char Vex[MaxVertexNum]; //顶点表
    int Edge[MaxVertexNum][MaxVertexNum]; //邻接矩阵，边表
    int vexnum, arcnum; //图的当前顶点数和边数/弧数
} MGraph;