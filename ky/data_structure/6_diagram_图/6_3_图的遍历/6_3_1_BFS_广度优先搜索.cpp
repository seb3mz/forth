#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "../6_2_图的存储及基本操作/62_AdjacencyTable_邻接表.h"
#include "../6_2_图的存储及基本操作/61_AdjacencyMatrix_邻接矩阵法.h"
using namespace std;

void Visit(VNode vn)
{
    cout << vn.data << endl;
}

//用邻接表存储结构遍历
void BFS_AdjacencyTable(ALGraph alg, int i, bool isVisited[])
{
    SqQueue<VNode> sqv;
    VNode vn;

    sqv.InitQueue();
    Visit(alg.vertices[i]);
    isVisited[i] = true;
    sqv.EnQueue(alg.vertices[i]);
    

    while(!sqv.QueueEmpty())
    {
        sqv.DeQueue(vn);
        for(ArcNode* arcNode = vn.first; arcNode; arcNode = arcNode->next)
        {
            if(!isVisited[arcNode->adjvex])
            {
                Visit(alg.vertices[arcNode->adjvex]);
                isVisited[arcNode->adjvex] = true;
                sqv.EnQueue(alg.vertices[arcNode->adjvex]);
            }
        }
    }        
    
}

//邻接矩阵存储结构
void BFS_AdjacencyMatrix(MGraph alg, int i, bool isVisited[])
{
    SqQueue<int> sqv;
    int number = 0;

    sqv.InitQueue();
    isVisited[i] = true;
    sqv.EnQueue(i);

    while(!sqv.QueueEmpty())
    {
        sqv.DeQueue(number);
        
        for(int col = 0; col < alg.vexnum; col++)
        {
            if(!isVisited[col] && alg.Edge[number][col])
            {
                //访问
                isVisited[col] = true;
                sqv.EnQueue(col);
            }
        }
    }
    
}

void BFSTraverse(ALGraph alg)
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
            BFS_AdjacencyTable(alg, i, isVisited);
        }
    }
}

int main()
{
    return 0;
}