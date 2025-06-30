#define MaxVertexNum 100
//顶点
typedef struct VNode {
    int data;   //顶点信息
    ArcNode* first; //第一条边/弧
}VNode, AdjList[MaxVertexNum];

//边/弧
typedef struct ArcNode {
    int adjvex; //边/弧指向哪个结点
    struct ArcNode* next;   //指向下一条弧的指针
    //InfoType info;    //边权值
}ArcNode;

//邻接表法存储图
typedef struct {
    AdjList vertices;
    int vexnum; //顶点数
    int arcnum; //边数
} ALGraph;