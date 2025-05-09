#ifndef BITREE_H
#define BITREE_H

typedef struct BiTNode{
    int data;
    BiTNode* lchild, *rchild;
}BiTNode, *BiTree;

// 初始化二叉树
bool CreateBiTree(BiTree &T);

//



#endif //BITREE_H