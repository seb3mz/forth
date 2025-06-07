#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/5_tree_树/52_listtree_链式存储二叉树.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:计算二叉树中所有双分支的结点个树
    输入:
        BiTree:
    输出:
        int:
    分析思路:
        遍历二叉树，统计左右子树都存在的结点个树
    实现细节:
        使用层序遍历，挨个结点统计
    注意点:
    时间复杂度:
            
    空间复杂度:
            
*/

int NumberOfDoubleBranchNodesInBT(BiTree root)
{
    //1. 判空
    if(root == nullptr)
    {
        cout << "空树" << endl;
        return 0;
    }
    SqQueue<BiTNode*> sq;
    BiTNode* tmp_node = nullptr;
    int number = 0;
    sq.InitQueue();
    sq.EnQueue(root);
    while(!sq.QueueEmpty())
    {
        sq.DeQueue(tmp_node);
        if(tmp_node->lchild)
        {
            sq.EnQueue(tmp_node->lchild);
        }

        if(tmp_node->rchild)
        {
            sq.EnQueue(tmp_node->rchild);
        }

        if(tmp_node->lchild && tmp_node->rchild)
        {
            number++;
        }
    }

    return number;
}

int main()
{
    BiTNode* a = new BiTNode();
    a->data = 10;

    BiTNode* b = new BiTNode();
    b->data = 11;
    BiTNode* c = new BiTNode();
    c->data = 12;

    BiTNode* c_left = new BiTNode();
    c_left->lchild = nullptr;
    c_left->rchild = nullptr;
    c->lchild = c_left;

    a->lchild = b;
    a->rchild = c;

    BiTNode* d = new BiTNode();
    d->data = 13;
    
    BiTNode* e = new BiTNode();
    e->data = 14;
    e->lchild = nullptr;
    e->rchild = nullptr;

    b->lchild = d;
    b->rchild = e;

    BiTNode* f = new BiTNode();
    f->data = 15;
    
    c->rchild = f;

    BiTNode* g = new BiTNode();
    g->data = 16;
    f->lchild = nullptr;
    g->lchild = nullptr;
    g->rchild = nullptr;

    BiTNode* h = new BiTNode();
    h->data = 17;
    f->rchild = nullptr;
    h->lchild = nullptr;
    h->rchild = nullptr;

    d->lchild = g;
    d->rchild = f;

    cout << NumberOfDoubleBranchNodesInBT(a) << endl;
    return 0;
}