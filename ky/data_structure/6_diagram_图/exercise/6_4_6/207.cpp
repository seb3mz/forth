#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/6_diagram_图/6_2_图的存储及基本操作/62_AdjacencyTable_邻接表.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

void DFS(ALGraph G, int i, bool isVisited[], SeqStack<int>& sq)
{
    VNode vn = G.vertices[i];
    ArcNode* arcNode = vn.first;
    for(; arcNode; arcNode = arcNode->next)
    {
        if(!isVisited[arcNode->adjvex])
        {
            DFS(G, arcNode->adjvex, isVisited, sq);
            isVisited[arcNode->adjvex] = true;
            //sq 中存储的是拓扑排序序列
            sq.Push(arcNode->adjvex);
        }
    }
}

bool TopologicalSort(ALGraph G)
{
    bool isVisited[G.vexnum];
    SeqStack<int> sq;

    sq.InitStack();
    for(int i = 0; i < G.vexnum; i++)
    {
        isVisited[i] = false;
    }

    for(int i = 0; i < G.vexnum; i++)
    {
        if(!isVisited[i])
        {
            DFS(G, i, isVisited, sq);
        }
    }
}

int main()
{
    return 0;
}