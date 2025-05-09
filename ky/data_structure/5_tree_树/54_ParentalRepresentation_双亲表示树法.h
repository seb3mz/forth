//可以存储树、森林

#define MAX_TREE_SIZE 100   //树中最多结点数

typedef struct {    //结点定义
    int data;       //数据域
    int parent;     //双亲位置域
} PTNode;

typedef struct {
    PTNode nodes[MAX_TREE_SIZE];
    int n;  //结点数
} PTree;