#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/5_tree_树/52_listtree_链式存储二叉树.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:非递归算法求二叉树高度
    输入:
        BiTree:
    输出:
        int:树高
    分析思路:
        非递归后序遍历过程中，栈中元素最大的状态就是二叉树的树高
    实现细节:
        
    注意点:
    时间复杂度:
            
    空间复杂度:
            
*/

int TreeHeight(BiTree root)
{
    SeqStack<BiTNode*> sq;
    sq.InitStack();
    BiTNode* node = root;
    BiTNode* top;
    int tree_height = 0;
    int max_height = 0;
    sq.Push(node);
    tree_height++;
    max_height++;
    node = node->lchild;
    while(!sq.StackEmpty())
    {
        if(node != nullptr)
        {
            sq.Push(node);
            node = node->lchild;
            tree_height++;
            continue;
        }
        sq.GetTop(top);
        node = top->rchild;
        if(node != nullptr)
        {
            sq.Push(node);
            node = node->lchild;
            tree_height++;
            continue;
        }
        else
        {
            BiTNode* tmp_top;
            BiTNode* tmp_root;
            if(tree_height > max_height)
            {
                max_height = tree_height;
            }
            sq.Pop(tmp_top);
            tree_height--;
            if(sq.GetTop(tmp_root))
            {
                while(tmp_root->rchild == tmp_top && !sq.StackEmpty())
                {
                    sq.Pop(tmp_top);
                    tree_height--;
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
    return max_height;
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

    cout << TreeHeight(a) << endl;
    return 0;
}