/* 
    功能:互换一个数组中两个线性表的位置，原本 A[m+n] 排列为(A1,A2, ... , Am,B1,B2...Bn)，更改后排列为(B1,B2,...Bn,A1,A2...Am)
    输入:数组
    输出:更改排列后的数组
*/

void ReverseSqtInArray(int *arr, int m, int n)
{
    //分析:需要判断两个线性表的长度
    /*
        思路:
            将 A 移动到位序为 [n+1,m+n]
            将 B 移动到为序为 [1, n]
            每个元素都知道自己的位置
            逆序遍历 A，m - 1
            正序遍历 B，m+1 - m+n
    */
    //暴力求解
    int *tmp_arr = (int *)malloc(sizeof(int)*(m+n));
    int startpos = n+1;
    for(int pos = 1; pos <= m; pos++)
    {
        tmp_arr[startpos-1] = arr[pos-1];
        startpos++;
    }
    startpos = 1;
    for(int pos = m+1; pos <= m+n; pos++)
    {
        tmp_arr[startpos-1] = arr[pos-1];
        startpos++;
    }

    for(int pos = 1; pos <= m+n; pos++)
    {
        arr[pos-1] = tmp_arr[pos-1];
    }
}