#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/5_tree_树/52_listtree_链式存储二叉树.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:将二叉树的叶结点按照从左到右的顺序连成一个单链表
    输入:
    输出:
        
    分析思路:
    实现细节:
    注意点:
    时间复杂度:
            
    空间复杂度:
            
*/

BiTNode* LeefNodeToList(BiTree root)
{
    BiTNode* head = new BiTNode;
    BiTNode* preNode = head;
    SeqStack<BiTNode*> sq;
    sq.InitStack();
    BiTNode* node = root;
    BiTNode* top;
    sq.Push(node);
    node = node->lchild;
    while(!sq.StackEmpty())
    {
        if(node != nullptr)
        {
            sq.Push(node);
            node = node->lchild;
            continue;
        }
        sq.GetTop(top);
        node = top->rchild;
        if(node != nullptr)
        {
            sq.Push(node);
            node = node->lchild;
            continue;
        }
        else
        {
            BiTNode* tmp_top;
            BiTNode* tmp_root;
            sq.Pop(tmp_top);
            preNode->rchild = tmp_top;
            preNode = tmp_top;
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
        preNode->rchild = nullptr;
    }
    return head;
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

    BiTNode* head = LeefNodeToList(a);
    while(head)
    {
        cout << head->data << " ";
        head = head->rchild;
    }
    cout << endl;
    return 0;
}