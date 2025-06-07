#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/5_tree_树/52_listtree_链式存储二叉树.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;
/*
    功能:自下而上，自右而左的层次遍历
    输入:
        BiTree:
    输出:
        void:
    分析思路:
        自下而上，自右向左的层次遍历相当于正向层次遍历的逆序，可以将正向层次遍历结果保存在栈中，逆序输出
    实现细节:
        定义一个队列用于正向层次遍历
        定义一个栈用于存放正向层次遍历输出的结果，用于逆向遍历
    注意点:
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

void ReverseHierarchicalTraversalOfBT(BiTree root)
{
    SqQueue<BiTNode*> sq;
    SeqStack<int> ss;

    //1. 判空
    if(root == nullptr)
    {
        cout << "空树" << endl;
        return;
    }

    //2. 正向层次遍历
    sq.InitQueue();
    ss.InitStack();
    sq.EnQueue(root);
    while(!sq.QueueEmpty())
    {
        BiTNode* node = nullptr;
        sq.DeQueue(node);
        ss.Push(node->data);
        if(node->lchild)
        {
            sq.EnQueue(node->lchild);
        }
        if(node->rchild)
        {
            sq.EnQueue(node->rchild);
        }
    }

    ss.PrintSeq();
}

int main()
{
    BiTNode* a = new BiTNode();
    a->data = 10;

    BiTNode* b = new BiTNode();
    b->data = 11;
    BiTNode* c = new BiTNode();
    c->data = 12;
    c->lchild = nullptr;

    a->lchild = b;
    a->rchild = c;

    BiTNode* d = new BiTNode();
    d->data = 13;
    d->lchild = nullptr;
    d->rchild = nullptr;
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
    f->lchild = g;
    g->lchild = nullptr;
    g->rchild = nullptr;

    BiTNode* h = new BiTNode();
    h->data = 17;
    f->rchild = h;
    h->lchild = nullptr;
    h->rchild = nullptr;
    
    ReverseHierarchicalTraversalOfBT(a);

    return 0;
}