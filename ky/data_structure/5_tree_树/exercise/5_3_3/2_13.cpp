#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/5_tree_树/52_listtree_链式存储二叉树.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:求非空二叉树的宽度
    输入:
        BiTree
    输出:
        int:
    分析思路:
        层序遍历，找到每层结点宽度最大值
        用两个队列交替存放子结点
    实现细节:
    注意点:
    时间复杂度:
            
    空间复杂度:
            
*/

int Width_1(BiTree root)
{
    //1. 判空
    if(root == nullptr)
    {
        cout << "空树" << endl;
        return 0;
    }

    //2. 正向层次遍历
    SqQueue<BiTNode*> sq1;
    SqQueue<BiTNode*> sq2;
    int width = 0;
    int max_width = 0;

    sq1.InitQueue();
    sq2.InitQueue();

    sq1.EnQueue(root);

    while(!sq1.QueueEmpty() || !sq2.QueueEmpty())
    {
        if(sq1.QueueEmpty())
        {
            BiTNode* tmp_node = nullptr;
            while(!sq2.QueueEmpty())
            {
                sq2.DeQueue(tmp_node);
                width++;
                if(tmp_node->lchild)
                {
                    sq1.EnQueue(tmp_node->lchild);
                }
                if(tmp_node->rchild)
                {
                    sq1.EnQueue(tmp_node->rchild);
                }
            }
        }
        else if(sq2.QueueEmpty())
        {
            BiTNode* tmp_node = nullptr;
            while(!sq1.QueueEmpty())
            {
                sq1.DeQueue(tmp_node);
                width++;
                if(tmp_node->lchild)
                {
                    sq2.EnQueue(tmp_node->lchild);
                }
                if(tmp_node->rchild)
                {
                    sq2.EnQueue(tmp_node->rchild);
                }
            }
        }

        cout << width << endl;
        if(width > max_width)
        {
            max_width = width;
        }
        width = 0;
    }

    return max_width;
}

int Width(BiTree root)
{
    //1. 判空
    if(root == nullptr)
    {
        cout << "空树" << endl;
        return 0;
    }

    //2. 正向层次遍历
    SqQueue<BiTNode*> sq;
    int max_width = 0;
    int width = 0;
    bool foundFirstNode = false;
    BiTNode* firstNode = nullptr;
    sq.InitQueue();
    sq.EnQueue(root);

    if(root->lchild)
    {
        firstNode = root->lchild;
    }
    else if(root->rchild)
    {
        firstNode = root->rchild;
    }
    else
    {
        cout << "只有根节点" << endl;
        return 1;
    }
    
    //3. 
    while(!sq.QueueEmpty())
    {
        BiTNode* node = nullptr;
        sq.DeQueue(node);
        if(node == firstNode)
        {
            if(width > max_width)
            {
                max_width = width;
            }
            width = 0;
            foundFirstNode = false;
        }

        width++;
        if(node->lchild)
        {
            if(!foundFirstNode)
            {
                firstNode = node->lchild;
                cout << firstNode->data << endl;
                foundFirstNode = true;
            }
            sq.EnQueue(node->lchild);
        }
        if(node->rchild)
        {
            if(!foundFirstNode)
            {
                firstNode = node->rchild;
                cout << firstNode->data << endl;
                foundFirstNode = true;
            }
            sq.EnQueue(node->rchild);
        }
    }

    return max_width;
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

    cout << Width_1(a) << endl;
    return 0;
}