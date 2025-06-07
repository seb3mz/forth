#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/5_tree_树/52_listtree_链式存储二叉树.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:把二叉树中所有结点的左右子树交换
    输入:
        BiTree:
    输出:
        void:
    分析思路:
        遍历二叉树，将每个结点的左右子树进行交换
    实现细节:
        
    注意点:
    时间复杂度:
            
    空间复杂度:
            
*/

void ExchangeLeftAndRightSubtrees(BiTree root)
{
    //1. 判空
    if(root == nullptr)
    {
        cout << "空树" << endl;
        return ;
    }
    SqQueue<BiTNode*> sq;
    BiTNode* tmp_node = nullptr;
    int number = 0;
    sq.InitQueue();
    sq.EnQueue(root);
    while(!sq.QueueEmpty())
    {
        sq.DeQueue(tmp_node);
        cout << tmp_node->data << " ";

        BiTNode* change_node = tmp_node->lchild;
        tmp_node->lchild = tmp_node->rchild;
        tmp_node->rchild = change_node;

        if(tmp_node->lchild)
        {
            sq.EnQueue(tmp_node->lchild);
        }

        if(tmp_node->rchild)
        {
            sq.EnQueue(tmp_node->rchild);
        }
    }
    cout << endl;
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

    ExchangeLeftAndRightSubtrees(a);

    cout << endl;
    return 0;
}