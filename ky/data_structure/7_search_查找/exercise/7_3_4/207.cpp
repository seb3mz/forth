#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:判断二叉树是否是平衡二叉树
    输入:
        BSTree T
    输出:
        bool:
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

int Depth(BSTree T)
{
    if(T == nullptr)
    {
        return 0;
    }
    int LDepth = Depth(T->lchild)+1;
    int RDepth = Depth(T->rchild)+1;

    return LDepth>RDepth?LDepth:RDepth;
}

bool IsAVL(BSTree T)
{
    SeqStack<BSTNode*> sb;
    int result = true;
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
            int LDepth = Depth(cur->lchild);
            int RDepth = Depth(cur->rchild);
            if(abs(LDepth-RDepth)>1)
            {
                result = false;
                break;
            }
            cur = cur->rchild;
        }
    }

    return result;
}

void Judge_AVL(BSTree bt, int &balance, int &h)
{
    int bl = 0, br = 0, hl = 0, hr = 0;
    if(bt == nullptr)
    {
        h = 0;
        balance = 1;
    }
    else if(bt->lchild == nullptr && bt->rchild == nullptr)
    {
        h = 1;
        balance = 1;
    }
    else
    {
        Judge_AVL(bt->lchild, bl, hl);
        Judge_AVL(bt->rchild, br, hr);
        h = (hl>hr?hl:hr)+1;
        if(abs(hl-hr)<2)
            balance = bl&&br;
        else
            balance = 0;
    }
}

int main() 
{    
    return 0;
}