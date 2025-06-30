//无向图
#define MAXNODE 100

struct Info {
    int weight;
};

//边结点
struct EdgeNode {
    int ivex;   //依附该边的一个结点
    EdgeNode* ilink;    //指向下一条依附于顶点 ivex 的边
    int jvex;   //依附该边的另一个结点
    EdgeNode* jlink;    //指向下一条依附于顶点 jvex 的边
    Info info;  //边信息
};

//顶点结点
struct VexNode {
    int data;   //顶点相关信息
    EdgeNode edge;  //第一条依附于该顶点的边
};

//图
struct Graph {
    VexNode vnode[MAXNODE];
};

