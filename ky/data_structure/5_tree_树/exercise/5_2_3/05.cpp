#include <iostream>
using namespace std;

/*
    功能:求结点 i 和 j 的最近祖先结点
    输入:
        SqTree T:顺序存储的树
        int i
        int j
    输出:
        int: 共同祖先结点的序号
    分析思路:
        根据 i 和 j 的大小，递归向上查找
    实现细节:
        
    注意点:
        
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

int Comm_Ancestor(int arr[], int i, int j)
{
    while(i != j)
    {
        if(i > j)
            i = i/2;
        else
            j = j/2;
    }
    return arr[i];
}

int main()
{
    int a[20] = {0};
    return 0;
}