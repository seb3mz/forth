#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/6_diagram_图/6_2_图的存储及基本操作/62_AdjacencyTable_邻接表.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
using namespace std;

/*
    功能:
        1. 深度优先遍历判断有向图是否有顶点 i 到顶点 j 的路径
        2. 广度优先遍历判断有向图是否有顶点 i 到顶点 j 的路径
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

const ALGraph alg;

bool Width(int i, int j, bool isVisited[])
{
    SqQueue<int> sqv;
    int seq;

    sqv.InitQueue();
    isVisited[i] = true;
    sqv.EnQueue(i);

    while(!sqv.QueueEmpty())
    {
        sqv.DeQueue(seq);
        ArcNode* arcNode = alg.vertices[seq].first;
        while(arcNode)
        {
            if(arcNode->adjvex == j)
            {
                return true;
            }
            if(!isVisited[arcNode->adjvex])
            {
                isVisited[arcNode->adjvex] = 1;
                sqv.EnQueue(arcNode->adjvex);
                arcNode = arcNode->next;
            }
        }
    }

    return false;
}

bool Depth(int i, int j, bool isVisited[])
{
    isVisited[i] = true;
    VNode node_i = alg.vertices[i];
    ArcNode * arcNode = node_i.first;
    for(;arcNode != nullptr; arcNode = arcNode->next)
    {
        if(arcNode->adjvex == j)
        {
            return true;
        }

        if(Depth(arcNode->adjvex, j, isVisited) == true)
        {
            return true;
        }
    }
    return false;
}

bool PathExist(int i, int j)
{
    bool isVisited[alg.vexnum];
    for(int i = 0; i < alg.vexnum; i++)
    {
        isVisited[i] = false;
    }

    for(int i = 0; i < alg.vexnum; i++)
    {
        if(!isVisited[i])
        {
            return Depth(i, j, isVisited);
        }
    }
}

int main()
{
    return 0;
}