#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "../6_2_图的存储及基本操作/62_AdjacencyTable_邻接表.h"
#include "../6_2_图的存储及基本操作/61_AdjacencyMatrix_邻接矩阵法.h"
using namespace std;
typedef MGraph Graph;

//通用深度优先搜索
void DFS(Graph alg, int i, bool isVisited[])
{
    for(int w = FirstNeighbor(alg, i); w >= 0; w = NextNeighbor(alg, i, w))
    {
        if(!isVisited[w])
        {
            isVisited[w] = true;
            DFS(alg, w, isVisited);
        }
    }
}

//邻接表深度优先搜索
void DFS_AdjacencyTable(ALGraph alg, int i, bool isVisited[])
{
    //结点找 firstArc
    //Visit
    isVisited[i] = true;
    for(ArcNode* p = alg.vertices[i].first; p; p = p->next)
    {
        if(!isVisited[p->adjvex])
        {
            DFS_AdjacencyTable(alg, p->adjvex, isVisited);
        }
    }
}

//邻接矩阵深度优先搜索
void DFS_AdjacencyMatrix(MGraph alg, int i, bool isVisited[])
{
    isVisited[i] = true;
    for(int col = 0; col < alg.vexnum; col++)
    {
        if(alg.Edge[i][col] && !isVisited[col])
        {
            DFS_AdjacencyMatrix(alg, col, isVisited);
        }
    }
}

void DFSTraverse(Graph alg)
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
            DFS(alg, i, isVisited);
        }
    }
}

int main()
{
    return 0;
}