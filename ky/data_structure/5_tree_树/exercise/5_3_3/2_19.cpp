#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100

typedef struct BiTNode {
    int SqBiTNode[MAX_SIZE];   //数据域
    int EleNum;
}BiTree;

/*
    功能:判断树是否为二叉搜索树
    输入:
        BiTree:
    输出:
        bool:
    分析思路:
        
    实现细节:
    注意点:
    时间复杂度:
            
    空间复杂度:
            
*/
bool IsBST(BiTree &tree)
{
    int height = log2l(tree.EleNum);
    int cnt = exp2(height)-1;
    bool result = true;
    
    for(int arr_seq = cnt-1; arr_seq >= 0; arr_seq--)
    {
        if(tree.SqBiTNode[arr_seq] != -1)
        {
            if(2*arr_seq+1 < tree.EleNum && tree.SqBiTNode[2*arr_seq+1] != -1 && tree.SqBiTNode[arr_seq] <= tree.SqBiTNode[2*arr_seq+1])
            {
                result = false;
                break;
            }
            if(2*arr_seq+2 < tree.EleNum && tree.SqBiTNode[2*arr_seq+2] != -1 && tree.SqBiTNode[arr_seq] >= tree.SqBiTNode[2*arr_seq+2])
            {
                result = false;
                break;
            }
            
            if(tree.SqBiTNode[arr_seq] > tree.SqBiTNode[2*arr_seq+1])
            {
                if(tree.SqBiTNode[arr_seq] < tree.SqBiTNode[2*arr_seq+2])
                {
                    tree.SqBiTNode[arr_seq] = tree.SqBiTNode[2*arr_seq+2];
                }
            }
            else
            {
                if(tree.SqBiTNode[2*arr_seq+1] > tree.SqBiTNode[2*arr_seq+2])
                {
                    tree.SqBiTNode[arr_seq] = tree.SqBiTNode[2*arr_seq+1];
                }
                else
                {
                    tree.SqBiTNode[arr_seq] = tree.SqBiTNode[2*arr_seq+2];
                }
            }
        }
    }

    return result;
}

int main()
{
    BiTree tree1 = {{40, 50, 60, -1, 30, -1, -1, -1, -1, -1, 35}, 11};
    BiTree tree = {{40, 25, 60, -1, 30, -1, 80, -1, -1, 27}, 10};
    for(int i = 0; i < tree.EleNum; i++)
    {
        cout << tree.SqBiTNode[i] << " ";
    }
    cout << endl;
    cout << IsBST(tree) << endl;
    for(int i = 0; i < tree.EleNum; i++)
    {
        cout << tree.SqBiTNode[i] << " ";
    }
    cout << endl;
    return 0;
}