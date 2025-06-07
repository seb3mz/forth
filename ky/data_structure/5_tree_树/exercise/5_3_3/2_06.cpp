#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/5_tree_树/52_listtree_链式存储二叉树.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:判断二叉树是否是完全二叉树
    输入:
        BiTree:
    输出:
        bool:
    分析思路:
        利用完全二叉树的性质，当某个结点没有孩子，后续的所有结点都不会再有孩子结点
    实现细节:
        使用层序遍历，对每个结点是否存在左右孩子进行判断
    注意点:
    时间复杂度:
            
    空间复杂度:
            
*/

bool IsCompleteBT(BiTree root)
{
    //1. 判空
    if(root == nullptr)
    {
        cout << "空树" << endl;
        return false;
    }
    SqQueue<BiTNode*> sq;
    BiTNode* tmp_node = nullptr;
    bool IsFirstNull = false;
    bool result = true;
    sq.InitQueue();
    sq.EnQueue(root);
    while(!sq.QueueEmpty())
    {
        sq.DeQueue(tmp_node);
        if(tmp_node->lchild)
        {
            if(IsFirstNull)
            {
                result = false;
                break;
            }
            else
            {
                sq.EnQueue(tmp_node->lchild);
            }
            
        }
        else
        {
            IsFirstNull = true;
        }

        if(tmp_node->rchild)
        {
            if(IsFirstNull)
            {
                result = false;
                break;
            }
            else
            {
                sq.EnQueue(tmp_node->rchild);
            }
            
        }
        else
        {
            IsFirstNull = true;
        }
    }

    return result;
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

    // cout << (IsCompleteBT(a)?"是完全二叉树":"不是完全二叉树") << endl;
    cout << IsCompleteBT(a) << endl;

    return 0;
}