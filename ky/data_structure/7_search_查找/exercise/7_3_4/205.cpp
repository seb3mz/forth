#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:判断二叉树是否为二叉排序树
    输入:
        BSTree T
    输出:
        bool:
    分析思路:
       中序遍历依次比较
    实现细节:
        
    注意点:
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

typedef struct BSTNode {
    int key;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

bool IsBST(BSTree T)
{
    SeqStack<BSTNode*> sb;
    int result = true;
    int prev = -1;
    sb.InitStack();
    
    BSTNode* cur = T;
    while(cur || !sb.StackEmpty())
    {
        if(cur)
        {
            sb.Push(cur);
            cur = cur->lchild;
        }
        else
        {
            sb.Pop(cur);
            if(cur->key < prev)
            {
                result = false;
                break;
            }
            prev = cur->key;
            cur = cur->rchild;
        }
    }

    return result;
}


int predt = -32767;
bool IsBST_(BSTree T)
{
    int b1, b2;
    if(T == nullptr)
    {
        return 1;
    }
    else
    {
        b1 = IsBST_(T->lchild);
        if(b1 == 0 || predt >= T->key)
        {
            return 0;
        }
        predt = T->key;
        b2 = IsBST_(T->rchild);
        return b2;
    }
}

int main() 
{    
    return 0;
}