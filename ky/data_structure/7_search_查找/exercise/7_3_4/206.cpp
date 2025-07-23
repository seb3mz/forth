#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:求指定结点在二叉排序树中的层次
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

int Level(BSTree T, int key)
{
    int level = 0;
    bool found = false;
    BSTNode* cur_node = T;

    while(cur_node)
    {
        level++;
        if(cur_node->key == key)
        {
            found = true;
            break;
        }
        else if(cur_node->key > key)
        {  
            cur_node = cur_node->lchild;
        }
        else
        {
            cur_node = cur_node->rchild;
        }
    }

    if(found)
    {
        return level;
    }
    else
    {
        return 0;
    }
}

int main() 
{    
    return 0;
}