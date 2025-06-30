//有向图

#define MAXNODE 100

struct Info {
    int weight;
};

//弧结点
struct ArcNode {
    int tailvex; //弧尾结点编号
    int headvex; //弧头结点编号
    ArcNode* hlink; //弧头相同的下一弧结点
    ArcNode* tlink; //弧尾相同的下一弧结点
    Info info;
};

//顶点结点
struct VexNode {
    int data;   //顶点数据域
    ArcNode* firstin;   //指向以该顶点为弧头的第一个弧结点
    ArcNode* firstout;  //指向以该顶点为弧尾的第一个弧结点
};

//图
struct Graph {
    VexNode vnode[MAXNODE];
};