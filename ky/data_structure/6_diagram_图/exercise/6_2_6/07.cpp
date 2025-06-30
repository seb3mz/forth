#include <iostream>
#include "../61_AdjacencyMatrix_邻接矩阵法.h"
using namespace std;

int IsExistEL(MGraph G)
{
    //1. 判断顶点的度为奇数的顶点个数为0或2
    int oddNum = 0;
    int result = 0;
    for(int row = 0; row < G.vexnum; row++)
    {
        int du = 0;
        for(int col = 0; col < G.vexnum; col++)
        {
            du += G.Edge[row][col];
        }

        if(du % 2 == 1)
        {
            oddNum++;
        }
    }

    if(oddNum != 0 && oddNum != 2)
    {
        cout << "不存在 EL 路径" << endl;
        result = 0;
        return result;
    }

    //2. 查找长度为 |E| 的路径是否存在
    int Edge[G.vexnum][G.vexnum] = {0};
    for(int num = 0; num < G.arcnum; num++)
    {
        for(int row = 0; row < G.vexnum; row++)
        {
            int sum = 0;
            for(int col = 0; col < G.vexnum; col++)
            {
                for(int num = 0; num < G.vexnum; num++)
                {
                    sum += G.Edge[row][num]*G.Edge[num][col];
                }
                Edge[row][col] = sum;
            }
        }
    }

    for(int row = 0; row < G.arcnum; row++)
    {
        for(int col = 0; col < G.vexnum; col++)
        {
            if(Edge[row][col] > 0)
            {
                result = true;
                break;
            }
        }
    }
    
    return result;
}

int main()
{
    return 0;
}