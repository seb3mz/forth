/* 
    功能:输出递增数组 A[n]、B[n]、C[n] 中同时存在的元素
    输入: A、B、C
    输出:
    时间复杂度: 最少
    空间复杂度:

    设计思想：
        使用三个位置索引 a、b、c 分别指向 A、B、C 的起始位置
        从 a=1 开始，递增 b、c 直到找到第一个大于等于 A[1] 的值
        若均找到，则输出该值后，分别对a、b、c 加一操作，继续上述操作直至 a、b、c 任何一个等于 n
    时间复杂度: O(n)
    空间复杂度: O(1)
*/

void PrintSameElement(int A[], int B[], int C[])
{
    int a = 0, b = 0, c = 0;
    while( a < n && b < n && c < n)
    {
        // 先找到 A=B 的位置，然后再去找 C 的位置
        if(A[a] < B[b])
        {
            a++;
            continue;
        }
        else if(A[a] > B[b])
        {
            b++;
            continue;
        }
        else
        {
            if(A[a] > C[c])
            {
                c++;
                continue;
            }
            else if(A[a] < C[c])
            {
                a++;
                b++;
                continue;
            }
            else
            {
                cout << "A[" << a << "] = B[" << b << "] = C[" << c << "] = " << A[a] << endl;
                a++;
                b++;
                c++;
            }
        }
    }
}