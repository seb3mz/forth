#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:输出二叉排序树中最大最小关键字
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

void FindMaxMinKeyInBST(BSTree T)
{
    if(T == nullptr)
    {
        cout << "空树" << endl;
        return;
    }

    BSTNode* cur_node = T;
    BSTNode* pre_node = cur_node;
    while(cur_node)
    {
        pre_node = cur_node;
        cur_node = cur_node->lchild;
    }
    cout << "最小值:" << pre_node->key << endl;

    cur_node = T;
    pre_node = cur_node;
    while(cur_node)
    {
        pre_node = cur_node;
        cur_node = cur_node->rchild;
    }
    cout << "最大值:" << pre_node->key << endl;
}

int main() 
{    
    return 0;
}