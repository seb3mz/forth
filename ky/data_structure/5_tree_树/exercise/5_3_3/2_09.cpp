#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/5_tree_树/52_listtree_链式存储二叉树.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:求先序遍历序列中第 k 个结点的值
    输入:
        BiTree:
    输出:
        int
    分析思路:
        先序遍历二叉树，找到第 k 个结点返回其值
    实现细节:
        使用栈结构，将所有访问过的结点入栈，
    注意点:
    时间复杂度:
            
    空间复杂度:
            
*/

int RetNumberKNode(BiTree root, int k)
{
    if(k <= 0)
    {
        cout << "序号应该大于0" << endl;
        return -1;
    }
    SeqStack<BiTNode*> sq;
    sq.InitStack();
    int cnt = 0;
    BiTNode* node = root;
    BiTNode* top;
    sq.Push(node);
    cnt++;
    if(cnt == k)
    {
        return node->data;
    }
    cout << "入栈:" << node->data << endl;
    node = node->lchild;
    while(!sq.StackEmpty())
    {
        //找到最左边的结点
        if(node != nullptr)
        {
            cnt++;
            sq.Push(node);
            if(cnt == k)
            {
                return node->data;
            }
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
            cnt++;
            //若有右结点，则继续重复上述流程
            sq.Push(node);
            if(cnt == k)
            {
                return node->data;
            }
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
    if(cnt < k)
    {
        cout << "结点数小于" << k << endl;
        return -1;
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

    cout << RetNumberKNode(a, 9) << endl;

    return 0;
}