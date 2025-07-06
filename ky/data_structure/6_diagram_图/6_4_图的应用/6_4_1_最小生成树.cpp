#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/6_diagram_图/6_2_图的存储及基本操作/61_AdjacencyMatrix_邻接矩阵法.h"
using namespace std;

/*
    1. Prim 算法
    功能:求最小生成树
    算法思想:
        1) 从图中任意选取一个顶点作为起始点
        2) 将该顶点加入到最小生成树中
        3) 在剩余的顶点中，找到与最小生成树中顶点相连的边中权值最小的边，将其对应的顶点加入到最小生成树中
        4) 重复步骤3，直到所有顶点都被加入到最小生成树中
    前置条件:
        1) 连通图 G = {V, E}，其中 V 为顶点集合，E 为边集合
        2) 最小生成树 T = {U, Et}，其中 U 为顶点集合，Et 为边集合
    伪代码: 
        void Prim(G, T)
        {
            T = NULL;   // 初始化最小生成树 T
            U = {w};    // 选择一个顶点 w 加入 T;
            while((U-V) != NULL)
            {
                设 (u,v) 是使 u ∈ U 与 v ∈ (V-U)，且权值最小的边;
                T = T ∪ {(u,v)};  // 将边 (u,v) 加入到最小生成树 T 中
                U = U ∪ {v};      //顶点归入树
            }
        }

*/

void Prim(MGraph mgp, Tree &T)
{
    bool isJoined[mgp.vexnum] = {false}; // 标记顶点是否已加入最小生成树
    int lowCost[mgp.vexnum]; // 存储每个顶点到最小生成树的最小边权值
    /*
        初始化:
            从顶点 0 出发，isJoined[0] = true;
            lowCost[0] = 0; // 顶点 0 到自身的边权为 0
            更新其他顶点到顶点 0 的 lowCost 值
        循环:
            1) 找到未加入最小生成树的顶点中，lowCost 值最小的顶点 v
            2) 将顶点 v 加入最小生成树
            3) 更新其他未加入最小生成树的顶点到最小生成树中结点的最小值，直到所有顶点都加入 isJoined
    */

}

/*
    2. Kruskal 算法
    功能:求最小生成树
    算法思想:
        1) 将图中的所有边按权值从小到大排序
        2) 从小到大依次取出边，判断是否会形成回路
        3) 如果不会形成回路，则将该边加入到最小生成树中
        4) 重复步骤2和3，直到最小生成树中的边数等于顶点数减一
    前置条件:
        1) 连通图 G = {V, E}，其中 V 为顶点集合，E 为边集合
        2) 最小生成树 T = {U, Et}，其中 U 为顶点集合，Et 为边集合
    伪代码: 
        void Kruskal(V, T)
        {
            T = V;      // 初始化树 T，仅含顶点
            numS = n;   //连通分量数
            while(numS > 1)
            {
                (u,v) = min(E); // 取出权值最小的边 (u,v)
                if(!isCycle(T, u, v)) // 判断是否形成回路
                {
                    T = T ∪ {(u,v)}; // 将边 (u,v) 加入到最小生成树 T 中
                    numS--; // 连通分量数减一
                }
            }
        }
*/

void Kruskal()
{
    //使用堆排序+并查集
}

int main()
{
    return 0;
}