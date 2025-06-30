#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "../6_2_图的存储及基本操作/61_AdjacencyMatrix_邻接矩阵法.h"
using namespace std;

/*
    功能:判断图是否能被二分
    输入:
        MGraph G:
    输出:
        bool:
    分析思路:
        广度搜索图，比对当前结点与邻接结点的颜色值是否相同，若相同则非二分，比对到所有结点都被遍历一次
    实现细节:
        使用邻接矩阵存储图
        被访问结点 bool isVisited[];
        顶点颜色数组 enum Color {RED, BLUE};    Color color[];
    注意点:
    时间复杂度:
        O(n*n)
    空间复杂度:
        O(n)
*/

bool IsBinaryGraph(MGraph G)
{
    enum Color {
        NONE,
        RED,
        BLUE
    };

    bool isVisited[G.vexnum];
    Color color[G.vexnum];
    SqQueue<int> sqv;
    int seq = 0;
    bool result = true;

    for(int i = 0; i < G.vexnum; i++)
    {
        isVisited[i] = false;
        color[i] = NONE;
    }

    sqv.InitQueue();
    isVisited[seq] = true;
    color[seq] = RED;
    sqv.EnQueue(seq);

    while(!sqv.QueueEmpty() && result)
    {
        sqv.DeQueue(seq);
        for(int col = 0; col < G.vexnum; col++)
        {
            if(G.Edge[seq][col] == 1)
            {
                if(color[col] == color[seq])
                {
                    result = false;
                    break;
                }
                else
                {
                    if(!isVisited[col])
                    {
                        isVisited[col] = true;
                        color[col] = (color[seq]==RED?BLUE:RED);
                        sqv.EnQueue(col);
                    }
                }
            }
        }
    }

    return result;
}

int main()
{
    return 0;
}