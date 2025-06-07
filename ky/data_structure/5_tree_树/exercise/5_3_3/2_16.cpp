#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/5_tree_树/52_listtree_链式存储二叉树.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:判断两棵二叉树是否相似
    输入:
        BiTree:
        BiTree:
    输出:
        bool:
    分析思路:
    实现细节:
    注意点:
    时间复杂度:
            
    空间复杂度:
            
*/

bool IsSimilarBT(BiTree a, BiTree b)
{
    //1. 判空
    if(a == nullptr && b == nullptr)
    {
        return true;
    }
    else if(a == nullptr && b != nullptr)
    {
        return false;
    }
    else if(a != nullptr && b == nullptr)
    {
        return false;
    }

    //2. 正向层次遍历
    bool result = true;
    SqQueue<BiTNode*> sqa;
    SqQueue<BiTNode*> sqb;
    sqa.InitQueue();
    sqb.InitQueue();
    sqa.EnQueue(a);
    sqb.EnQueue(b);

    while(!sqa.QueueEmpty() && !sqb.QueueEmpty())
    {
        BiTNode* node_a = nullptr;
        BiTNode* node_b = nullptr;
        sqa.DeQueue(node_a);
        sqb.DeQueue(node_b);
        if((node_a->lchild && node_b->lchild))
        {
            sqa.EnQueue(node_a->lchild);
            sqb.EnQueue(node_b->lchild);
        }
        else
        {
            if(!(node_a->lchild == nullptr && node_b->lchild == nullptr))
            {
                result = false;
                break;
            }
        }

        if(node_a->rchild && node_b->rchild)
        {
            sqa.EnQueue(node_a->rchild);
            sqb.EnQueue(node_b->rchild);
        }
        else
        {
            if(!(node_a->rchild == nullptr && node_b->rchild == nullptr))
            {
                result = false;
                break;
            } 
        }
    }

    if(!sqa.QueueEmpty() || !sqb.QueueEmpty())
    {
        result = false;
    }
    
    return result;
}

int main()
{
    BiTNode* node_a = new BiTNode();
    node_a->data = 10;
    BiTNode* node_al = new BiTNode();
    node_al->data = 11;
    BiTNode* node_ar = new BiTNode();
    node_ar->data = 12;
    BiTNode* node_al_al = new BiTNode();
    node_al_al->data = 13;
    BiTNode* node_al_ar = new BiTNode();
    node_al_ar->data = 14;

    node_a->lchild = node_al;
    node_a->rchild = node_ar;

    node_al->lchild = node_al_al;
    node_al->rchild = node_al_ar;

    node_ar->lchild = nullptr;
    node_ar->rchild = nullptr;

    node_al_al->lchild = nullptr;
    node_al_al->rchild = nullptr;

    node_al_ar->lchild = nullptr;
    node_al_ar->rchild = nullptr;

    BiTNode* node_b = new BiTNode();
    node_b->data = 100;
    BiTNode* node_bl = new BiTNode();
    node_bl->data = 110;
    BiTNode* node_br = new BiTNode();
    node_br->data = 120;
    BiTNode* node_bl_bl = new BiTNode();
    node_bl_bl->data = 130;
    BiTNode* node_bl_br = new BiTNode();
    node_bl_br->data = 140;

    node_b->lchild = node_bl;
    node_b->rchild = node_br;

    node_bl->lchild = node_bl_bl;
    node_bl->rchild = node_bl_br;

    node_br->lchild = nullptr;
    node_br->rchild = nullptr;

    node_bl_bl->lchild = nullptr;
    node_bl_bl->rchild = nullptr;

    node_bl_br->lchild = nullptr;
    node_bl_br->rchild = nullptr;
    
    cout << IsSimilarBT(node_a, node_bl) << endl;

    return 0;
}