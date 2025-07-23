#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:从大到小输出二叉排序树中所有值不小于 k 的关键字
    输入:
        BSTree T
    输出:
        void:
    分析思路:
    实现细节:
        
    注意点:
    时间复杂度:
    空间复杂度:
*/

typedef struct BSTNode {
    int key;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

void FindValueGreater(BSTree T, int key)
{
    SeqStack<BSTNode*> sq;
    sq.InitStack();
    BSTNode* cur_node = T;

    while(cur_node || !sq.StackEmpty())
    {
        if(cur_node)
        {
            sq.Push(cur_node);
            cur_node = cur_node->rchild;
        }
        else
        {
            sq.Pop(cur_node);
            if(cur_node->key > key)
            {
                cout << cur_node->key << " ";
            }
            else
            {
                break;
            }
            cur_node = cur_node->lchild;
        }
    }
}

void OutPut(BSTNode *bt, int k)
{
    if(bt == nullptr)
        return;
    if(bt->rchild != nullptr)
        OutPut(bt->rchild, k);
    if(bt->key >= k)
        cout << bt->key;
    if(bt->lchild != nullptr)
        OutPut(bt->lchild, k);
}

int main() 
{    
    return 0;
}