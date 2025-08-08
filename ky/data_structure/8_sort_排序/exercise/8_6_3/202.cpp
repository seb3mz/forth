#include <iostream>
using namespace std;

/*
    1) 新建一个数组 B[m+n+1],设置两个索引分别指向两个有序序列，比较按从大到小的顺序存放在 B 中

    3) 
        时间复杂度: O(m+n)
        空间复杂度: O(m+n)
*/

void Sort(int A[], int m, int n)
{
    int B[m+n+1];
    int index_m = 1, index_n = m+1;
    int index_b = 1;
    while(index_m <= m && index_n <= m+n)
    {
        if(A[index_m] < A[index_n])
        {
            B[index_b] = A[index_m];
            index_b++;
            index_m++;
        }
        else
        {
            B[index_b] = A[index_n];
            index_b++;
            index_n++;
        }
    }

    while(index_m <= m)
    {
        B[index_b] = A[index_m];
        index_b++;
        index_m++;
    }

    while(index_n <= m+n)
    {
        B[index_b] = A[index_n];
        index_b++;
        index_n++;
    }

    for(index_b = 1; index_b <= m+n; index_b++)
    {
        A[index_b] = B[index_b];
    }
}

int main()
{
    return 0;
}