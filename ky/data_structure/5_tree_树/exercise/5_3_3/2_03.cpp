#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/5_tree_树/52_listtree_链式存储二叉树.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;
/*
    功能:后序遍历的非递归算法
    输入:
        BiTree:
    输出:
        void:
    分析思路:
       后序遍历:左右根
                1. 先找到最左边结点 m，
                    1.1 若 m 无右结点，此时可以输出 m
                    1.2 若 m 有右结点，此时需要对 m->rchild 进行后序遍历，继续 1
    实现细节:
        根据遍历结果的特征，先遍历的结点最后访问，所以采用栈结构
            定义栈 Sq，从根结点 root 的左子树开始，找到最左边的结点，即找到 node->lchild = nullptr 的结点
                      此时该结点还需要对 node 的右子树继续遍历，重复上述对 node->rchild 的后序遍历，直到找
                      到第一个叶结点，即可以输出,若输出的结点为右结点，继续向该结点的根结点遍历
    注意点:
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

void NonRecursiveBT(BiTree root)
{
    SeqStack<BiTNode*> sq;
    sq.InitStack();
    BiTNode* node = root;
    BiTNode* top;
    sq.Push(node);
    cout << "入栈:" << node->data << endl;
    node = node->lchild;
    while(!sq.StackEmpty())
    {
        //找到最左边的结点
        if(node != nullptr)
        {
            sq.Push(node);
            cout << "入栈:" << node->data << endl; 
            node = node->lchild;
            continue;
        }
        //此时栈顶结点为最左边结点
        sq.GetTop(top);
        //最左边结点是否有右结点
        node = top->rchild;
        if(node != nullptr)
        {
            //若有右结点，则继续重复上述流程
            sq.Push(node);
            cout << "入栈:" << node->data << endl;
            node = node->lchild;
            continue;
        }
        else
        {
            //若没有右结点，则输出该结点
            BiTNode* tmp_top;
            BiTNode* tmp_root;
            sq.Pop(tmp_top);
            cout << "出栈:" << tmp_top->data << endl << endl;
            if(sq.GetTop(tmp_root))
            {
                while(tmp_root->rchild == tmp_top && !sq.StackEmpty())
                {
                    sq.Pop(tmp_top);
                    cout << "出栈:" << tmp_top->data << endl << endl; 
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

    NonRecursiveBT(a);
    return 0;
}