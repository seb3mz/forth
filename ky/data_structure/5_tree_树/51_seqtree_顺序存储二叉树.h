#define MAXSIZE 100

struct TreeNode {
    int value;      //结点中的数据元素
    bool isEmpty;   //结点是否为空
};

//二叉树存储结构，默认第一个结点为空
//只适用于完全二叉树/满二叉树
TreeNode t[MAXSIZE];
