#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "../6_2_图的存储及基本操作/62_AdjacencyTable_邻接表.h"
#include "../6_2_图的存储及基本操作/61_AdjacencyMatrix_邻接矩阵法.h"
using namespace std;

//适用于无权图
//求所有顶点到顶点 u 的最短路径
void BFS_MIN_Distance(MGraph G, int u)
{
    //用于存放最短路径值
    int d[G.vexnum];
    bool isVisited[G.vexnum];
    SqQueue<int> sqv;

    for(int i = 0; i < G.vexnum; i++)
    {
        isVisited[i] = false;
        d[i] = -1;
    }

    sqv.InitQueue();
    isVisited[u] = true;
    sqv.EnQueue(u);

    while(!sqv.QueueEmpty())
    {
        sqv.DeQueue(u);
        for(int w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w))
        {
            if(!isVisited[w])
            {
                d[w] = d[u] + 1;
                isVisited[w] = true;
                sqv.EnQueue(w);
            }  
        }
    }

}

//适用于有权图
//求所有顶点到顶点 u 的最短路径
void Dijkstra(MGraph G, int u)
{
    bool final[G.vexnum]; // final[i] = true 表示顶点 i 已经确定最短路径
    int dist[G.vexnum]; // dist[i] 表示顶点 u 到顶点 i 的最短路径长度
    int path[G.vexnum]; // path[i] // path[i] 表示顶点 u 到顶点 i 的最短路径上的前驱
    /*
        初始:
            若从 V0 开始，令
            final[0] = true;
            dist[0] = 0;
            path[0] = -1;
            其余顶点
            final[k] = false;
            final[0] = true;
            dist[0] = arcs[0][k];
            path[0] = (arcs[0][k]==∞)?-1:0;

        n-1 轮处理:
            1) 找到未确定最短路径的顶点 i，使得 dist[i] 最小
            2) 将顶点 i 加入到 final 集合中: final[i] = true;
            3) 更新 dist 和 path 数组: 若 final[j]=false 且 dist[i]+arcs[i][j] < dist[j],则更新 dist[j] 和 path[j]:
               dist[j] = dist[i] + arcs[i][j];
               path[j] = i;
            4) 重复步骤1-3，直到所有顶点都被加入到 final 集合中
    */
}

int main()
{

}