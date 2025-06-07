#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/5_tree_树/52_listtree_链式存储二叉树.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:求二叉树的带权路径长度
    输入:
        BiTree:
    输出:
        int:
    分析思路:
        1) 找出每个叶结点的权值 weight，并找出每个叶结点到根节点的路径长度 l，计算该结点的带权路径长度 weight*l
            将所有叶结点的带权路径长度累加得到 WPL
            
    实现细节:
    注意点:
    时间复杂度:
            
    空间复杂度:
            
*/

int WPL(BiTree root)
{
    if(root == nullptr)
    {
        cout << "空树" << endl;
        return -1;
    }

    SeqStack<BiTNode*> sq;
    sq.InitStack();
    BiTNode* node = root;
    BiTNode* top;
    int tree_height = 0;
    int WPL = 0;
    sq.Push(node);
    tree_height++;
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
            sq.Pop(tmp_top);
            tree_height--;
            WPL += tree_height*tmp_top->data;
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
    return WPL;
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

    cout << WPL(node_a) << endl;
    return 0;
}