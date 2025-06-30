#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/6_diagram_图/6_2_图的存储及基本操作/62_AdjacencyTable_邻接表.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
using namespace std;

/*
    功能:
        1. 输出顶点 i 到顶点 j 所有简单路径
    输入:
        ALGraph G:
        int i:
        int j:
    输出:
        void:
    分析思路:
        使用深度优先搜索，找到后输出沿途结点
    实现细节:
    注意点:
    时间复杂度:
    空间复杂度:
*/

void DeepFind(ALGraph alg, int i, int j, SeqStack<int> sq, bool isVisited[])
{
    int seq;
    if(isVisited[i])
    {
        return;
    }
    isVisited[i] = true;

    if(i == j)
    {
        sq.PrintSeq();
        return ;
    }

    sq.Push(i);

    ArcNode* arcNode = alg.vertices[i].first;
    for(; arcNode != nullptr; arcNode = arcNode->next)
    {
        DeepFind(alg, arcNode->adjvex, j, sq, isVisited);
        sq.Pop(seq);
    }
}

void FindPathBetweenNodes(ALGraph alg, int i, int j)
{
    SeqStack<int> sq;
    bool isVisited[alg.vexnum];
    bool result;
    
    sq.InitStack();
    for(int vexcnt = 0; vexcnt < alg.vexnum; vexcnt++)
    {
        isVisited[vexcnt] = false;
    }

    isVisited[i] = true;
    
    for(int vexcnt = 0; vexcnt < alg.vexnum; vexcnt++)
    {
        if(!isVisited[vexcnt])
        {
            DeepFind(alg, i, j, sq, isVisited);
        }
    }
    
}

int main()
{
    return 0;
}