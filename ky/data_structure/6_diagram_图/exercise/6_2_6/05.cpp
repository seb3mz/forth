#include <iostream>
#include "../61_AdjacencyMatrix_邻接矩阵法.h"
#include "../62_AdjacencyTable_邻接表.h"
using namespace std;

void TransALGraphToMGraph(ALGraph alp, MGraph mgp)
{
    //1. 遍历所有顶点结点
    for(int i = 0; i < alp.vexnum; i++)
    {
        ArcNode* arcNode = alp.vertices[i].first;
        while(arcNode)
        {
            mgp.Edge[i][arcNode->adjvex] = 1;
            arcNode = arcNode->next;
        }    
    }
}

int main()
{
    return 0;
}