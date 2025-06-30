#include <iostream>
#include "../61_AdjacencyMatrix_邻接矩阵法.h"
using namespace std;

/*
    功能:输出所有 K 顶点，并返回 K 顶点的个数
    输入:
        MGraph G:
    输出:
        int:
    分析思路:
        遍历邻接矩阵，第 i 行非 0 个数表示第 i 个顶点的出度数
                    第 i 列非 0 个数表示第 i 个顶点的入度数
    实现细节:
        
    注意点:
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

int printVertices(MGraph G)
{
    int inDu = 0;
    int outDu = 0;
    int Knum = 0;
    
    for(int row = 0; row < G.vexnum; row++)
    {
        for(int col = 0; col < G.vexnum; col++)
        {
            outDu += G.Edge[row][col];
            inDu += G.Edge[col][row];
        }
        if(outDu > inDu)
        {
            cout << "row:" << row << endl;
            Knum++;
        }
    }

    return Knum;
}

int main()
{
    return 0;
}