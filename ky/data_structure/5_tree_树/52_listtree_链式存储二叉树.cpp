#include "52_listtree_链式存储二叉树.h"
#include "../3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include <iostream>
using namespace std;

//初始化空二叉树
bool InitBiTree(BiTree& tree, int value)
{
    BiTNode* root = (BiTNode*)malloc(sizeof(BiTNode));
    if(root == nullptr)
    {
        cout << "创建根结点失败" << endl;
        return false;
    }
    root->lchild = nullptr;
    root->rchild = nullptr;
    root->data = value;
    tree = root;
    cout << "初始化根结点成功" << endl;
    return true;
}

//销毁二叉树
void DestroyBiTree(BiTree& tree);


void VisitNode(BiTNode* node)
{
    cout << node->data << endl;
}

//先序遍历,第一次路过时访问
void PreOrderTraverse(BiTree tree)
{
    if(tree != nullptr)
    {
        VisitNode(tree);
        PreOrderTraverse(tree->lchild);
        PreOrderTraverse(tree->rchild);
    }
}

//中序遍历,第二次路过时访问
void InOrderTraverse(BiTree tree)
{
    if(tree != nullptr)
    {
        InOrderTraverse(tree->lchild);
        VisitNode(tree);
        InOrderTraverse(tree->rchild);
    }
}

//后序遍历,第三次路过时访问
void PostOrderTraverse(BiTree tree)
{
    if(tree != nullptr)
    {
        PostOrderTraverse(tree->lchild);
        PostOrderTraverse(tree->rchild);
        VisitNode(tree);
    }
}

//层序遍历二叉树
void LevelOrderTraverse(BiTree tree)
{
    // SqQueue sq;
    // InitQueue(sq);
    // if(tree != nullptr)
    // {
    //     EnQueue(sq, tree);
    //     BiNode * cur;
    //     while(!QueueEmpty(sq))
    //     {
    //         DeQueue(sq, cur);
    //         Visit(cur);
    //         if(cur->lchild)
    //         {
    //            EnQueue(sq, cur->lchild);
    //         }
    //         if(cur->rchild)
    //         {
    //            EnQueue(sq, cur->rchild);
    //         }
    //         
    //     }
    // }
}

//非递归先序遍历
void NonRecursiveSequentialTraversalBT(BiTree tree)
{
    
}

int main()
{
    BiTree tree;
    InitBiTree(tree, 10);
    return 0;
}
