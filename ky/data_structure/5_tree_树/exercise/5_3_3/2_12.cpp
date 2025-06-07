#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/5_tree_树/52_listtree_链式存储二叉树.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:找到 p 和 q 的最近公共祖先结点
    输入:
        BiTree:
        BiTNode*:
        BiTNode*:
        BiTNode*:
    输出:
        bool:
    分析思路:
        先找到 p 的所有祖先，在对每个祖先结点进行遍历，如果找到 q 结点，则该结点为公共祖先结点
    实现细节:
    注意点:
    时间复杂度:
            
    空间复杂度:
            
*/

//判断 q 是否是 root 的后代结点
bool IsRoot(BiTree root, BiTNode* q)
{
    //层序遍历
    SqQueue<BiTNode*> sq;
    sq.InitQueue();
    sq.EnQueue(root);
    while(!sq.QueueEmpty())
    {
        BiTNode* tmp_node = nullptr;
        sq.DeQueue(tmp_node);

        if(tmp_node == q)
        {
            return true;
        }

        if(tmp_node && tmp_node->lchild)
        {
            sq.EnQueue(tmp_node->lchild);
        }

        if(tmp_node && tmp_node->rchild)
        {
            sq.EnQueue(tmp_node->rchild);
        }
    }
    return false;
}

BiTNode* FindSpecNode(SeqStack<BiTNode*> sq, BiTNode* q)
{
    while(!sq.StackEmpty())
    {
        BiTNode* tmp_node = nullptr;
        sq.Pop(tmp_node);
        if(IsRoot(tmp_node, q))
        {
            return tmp_node;
        }
    }
    return nullptr;
}

void FindAncestor(BiTree root, BiTNode* p, BiTNode* q, BiTNode* r)
{
    //1. 先找到 p 的所有祖先结点
    SeqStack<BiTNode*> sq;
    sq.InitStack();
    BiTNode* node = root;
    BiTNode* top;
    sq.Push(node);
    if(node == p)
    {
        //2. 根据祖先结点找结点 q
        r = FindSpecNode(sq, q);
        return;
    }

    node = node->lchild;

    while(!sq.StackEmpty())
    {
        //找到最左边的结点
        if(node != nullptr)
        {
            sq.Push(node);
            if(node == p)
            {
                break;
            }
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
            if(node == p)
            {
                break;
            }
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

    r = FindSpecNode(sq, q);
    cout << r->data << endl;
    return;
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

    BiTNode* commonNode = nullptr;
    FindAncestor(a, c, f, commonNode);

    //cout << commonNode->data << endl;

    return 0;
}