#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/5_tree_树/52_listtree_链式存储二叉树.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:根据满二叉树的先序序列 pre，求后序序列 post
    输入:
        string:
        low:操作下界
        top:操作上界
    输出:
        void:
    分析思路:
        每次递归输出一个根结点
    实现细节:
    注意点:
    时间复杂度:
            
    空间复杂度:
            
*/

void PreToPost(string &pre, int low, int top)
{
    //cout << "low:" << low <<", top:" << top << endl;
    if(top-low < 2)
        return;
    string pre_tmp = pre.substr(low+1, top-low);
    pre_tmp+=pre[low];
    pre.replace(low, top-low+1, pre_tmp);
    PreToPost(pre, low, low+(top-low)/2-1);
    PreToPost(pre, low+(top-low)/2, top-1);
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

    string pre = "abcdefghijklmno";
    cout << pre << endl;
    PreToPost(pre, 0, pre.length()-1);
    cout << pre << endl;
    return 0;
}