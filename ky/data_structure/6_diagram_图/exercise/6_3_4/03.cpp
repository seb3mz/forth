#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "../6_2_图的存储及基本操作/61_AdjacencyMatrix_邻接矩阵法.h"
using namespace std;

/*
    功能:判断无向图是否为一棵树
    输入:
        MGraph G:
    输出:
        bool:
    分析思路:
        使用深度优先搜索，从结点 m 对邻接矩阵的上半三角形或者下半三角形进行遍历，如果找到 m，说明有环，则不是一棵树
    实现细节:
        被访问结点 bool isVisited[];
    注意点:
    时间复杂度:
    空间复杂度:
*/

bool FindM(MGraph G, int i, bool isVisited[])
{
    SqQueue<int> sqv;
    bool result = true;
    int seq;

    sqv.InitQueue();
    isVisited[i] = true;
    sqv.EnQueue(i);

    while(!sqv.QueueEmpty() && result)
    {
        sqv.DeQueue(seq);
        for(int row = seq+1; row < G.vexnum; row++)
        {
            if(isVisited[row] == 1)
            {
                result == false;
                break;
            }

            if(G.Edge[row][seq] == 1)
            {
                isVisited[row] = 1;
                sqv.EnQueue(row);
            }
        }
    }

    return result;
}

bool IsGraphAsTree(MGraph G)
{
    bool isVisited[G.vexnum];
    bool result = true;
    int connectedcomponent = 0;

    for(int i = 0; i < G.vexnum; i++)
    {
        isVisited[i] = false;
    }

    for(int i = 0; i < G.vexnum; i++)
    {
        if(!isVisited[i] && result)
        {
            result = FindM(G, i, isVisited);
        }
        else
        {
            connectedcomponent++;
        }
    }

    if(connectedcomponent > 1 || !result)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    return 0;
}