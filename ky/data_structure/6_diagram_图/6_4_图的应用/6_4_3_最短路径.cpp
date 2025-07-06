#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "../6_2_图的存储及基本操作/62_AdjacencyTable_邻接表.h"
#include "../6_2_图的存储及基本操作/61_AdjacencyMatrix_邻接矩阵法.h"
using namespace std;

/*
    Floyd 算法
    功能:求最短路径
    算法思想:使用动态规划思想，将问题的求解分为多个阶段
        对于 n 个顶点的图 G，求任意一对顶点 Vi -> Vj 之间的最短路径可分为如下几个阶段:
            #初始:不允许在其他顶点中转，最短路径是？
            #0:若允许在 V0 中转，最短路径是?
            #0:若允许在 V0、V1 中转，最短路径是?
            #0:若允许在 V0、V1、V2 中转，最短路径是?
            ...
            #n-1:若允许在 V0、V1、V2...Vn-1 中转，最短路径是?
*/

for(int k = 0; k < n; k++)	//考虑以 Vk 作为中转点
{
    for(int i = 0; i < n; i++)	//遍历矩阵， i 为行，j为列
    {
        for(int j = 0; j < n; j++)
        {
            if(A[i][j] > A[i][k] + A[k][j])	//以 Vk 为中转点的路径更短
            {
                A[i][j] = A[i][k] + A[k][j];	//更新最短路径长度
                path[i][j] = k;	//更新中转点
            }
        }
    }
}

int main()
{   
    return 0;
}