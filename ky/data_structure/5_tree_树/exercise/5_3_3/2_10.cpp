#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/5_tree_树/52_listtree_链式存储二叉树.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:删除树中每个元素值为 x 结点，以及以它为根的子树
    输入:
        BiTree:
        x:
    输出:
        int:删除了多少个结点
    分析思路:
        层序遍历，找到元素值为 x 的结点，对该结点进行后序遍历并删除每一个结点
    实现细节:
    注意点:
    时间复杂度:
            
    空间复杂度:
            
*/

int DeleteTree(BiTree root)
{
    //后序遍历删除树
    int number = 0;
    SeqStack<BiTNode*> sq;
    sq.InitStack();
    BiTNode* node = root;
    BiTNode* top;
    sq.Push(node);
    cout << "入栈:" << node->data << endl;
    node = node->lchild;
    while(!sq.StackEmpty())
    {
        if(node != nullptr)
        {
            sq.Push(node);
            cout << "入栈:" << node->data << endl; 
            node = node->lchild;
            continue;
        }

        sq.GetTop(top);
        node = top->rchild;

        if(node != nullptr)
        {
            sq.Push(node);
            cout << "入栈:" << node->data << endl;
            node = node->lchild;
            continue;
        }
        else
        {
            BiTNode* tmp_top;
            BiTNode* tmp_root;
            sq.Pop(tmp_top);
            cout << "出栈:" << tmp_top->data << endl << endl;
            delete(tmp_top);
            number++;

            if(sq.GetTop(tmp_root))
            {
                while(tmp_root->rchild == tmp_top && !sq.StackEmpty())
                {
                    sq.Pop(tmp_top);
                    number++;
                    cout << "出栈:" << tmp_top->data << endl << endl; 
                    delete(tmp_top);
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

    return number;
}

int DeleteRootValueX(BiTree root, int x)
{
    //1. 判空
    if(root == nullptr)
    {
        cout << "空树" << endl;
        return 0;
    }

    //2. 层序遍历
    SqQueue<BiTNode*> sq;
    int numberX = 0;
    sq.InitQueue();
    if(root->data == x)
    {
        //删除树
        numberX = DeleteTree(root);
        return numberX;
    }

    sq.EnQueue(root);
    cout << "入队" << root->data << endl;
    while(!sq.QueueEmpty())
    {
        BiTNode* node = nullptr;
        sq.DeQueue(node);
        if(node->lchild)
        {
            if(node->lchild->data == x)
            {
                numberX += DeleteTree(node->lchild);
            }
            else
            {
                cout << "入队" << node->lchild->data << endl;
                sq.EnQueue(node->lchild);
            }
        }
        if(node->rchild)
        {
            if(node->rchild->data == x)
            {
                numberX += DeleteTree(node->rchild);
            }
            else
            {
                cout << "入队" << node->rchild->data << endl;
                sq.EnQueue(node->rchild);
            }   
        }
    }

    return numberX;
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

    cout << DeleteRootValueX(a, 13) << endl;

    return 0;
}