#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/5_tree_树/52_listtree_链式存储二叉树.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:打印值为 x 的结点的所有祖先
    输入:
        BiTree:
        x:
    输出:
        void
    分析思路:
        进行后序遍历时，栈中所有的结点都是当前结点的祖先
    实现细节:
    注意点:
    时间复杂度:
            
    空间复杂度:
            
*/

void PrintXAncestor(BiTree root, int x)
{
    SeqStack<BiTNode*> sq;
    sq.InitStack();
    BiTNode* node = root;
    BiTNode* top;
    if(node->data == x)
    {
        cout << "根结点没有祖先结点" << endl;
        sq.PrintSeq();
        return;
    }
    sq.Push(node);

    node = node->lchild;
    while(!sq.StackEmpty())
    {
        //找到最左边的结点
        if(node != nullptr)
        {
            if(node->data == x)
            {
                sq.PrintSeq();
                return;
            }
            sq.Push(node);
            node = node->lchild;
            continue;
        }
        //此时栈顶结点为最左边结点
        sq.GetTop(top);
        //最左边结点是否有右结点
        node = top->rchild;
        if(node != nullptr)
        {
            if(node->data == x)
            {
                sq.PrintSeq();
                return;
            }
            //若有右结点，则继续重复上述流程
            sq.Push(node);
            node = node->lchild;
            continue;
        }
        else
        {
            //若没有右结点，则输出该结点
            BiTNode* tmp_top;
            BiTNode* tmp_root;
            sq.Pop(tmp_top);
            if(sq.GetTop(tmp_root))
            {
                while(tmp_root->rchild == tmp_top && !sq.StackEmpty())
                {
                    sq.Pop(tmp_top);
                    sq.GetTop(tmp_root);
                }
                node = tmp_root->rchild;
            }
            else
            {
                break;
            }
        }
    }
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

    PrintXAncestor(a, 17);

    return 0;
}