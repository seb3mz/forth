#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:递归算法查找二叉排序树上的第 k 小的元素，并返回指向该结点的指针
    输入:
        BSTree T
        int k
    输出:
        BSTNode*:
    分析思路:
    实现细节:
        
    注意点:
    时间复杂度:
    空间复杂度:
*/

typedef struct BSTNode {
    int data;
    int count;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

BSTNode* FindNumberK(BSTree T, int k)
{
    if(T->lchild == nullptr)
    {
        if(k == 1)
        {
            return T;
        }
        else
        {
            FindNumberK(T->rchild, k-1);
        }
    }
    else
    {
        if(T->lchild->count + 2 == k)
        {
            return T;
        }
        else if(T->lchild->count + 2 > k)
        {
            FindNumberK(T->lchild, k);
        }
        else
        {
            FindNumberK(T->rchild, k - T->lchild->count - 2);
        }
    }
}

int main() 
{    
    return 0;
}