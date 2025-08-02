#include <iostream>
using namespace std;

void InsertSort(int A[], int n)
{
    for(int i = 1; i < n; i++)
    {
        //找到第一个小于 A[i] 的位置 j
        int tmp = A[i];
        int j = i-1;
        for(; j >= 0 && A[j] > A[i]; j--)
        {

        }
        //将[j+1,i-1]位置的元素向后移动一位
        for(int k = i-1; k > j; k--)
        {
            A[k+1] = A[k]; 
        }
        A[j+1] = tmp;
    }
}

int main()
{
    int arr[] = {10,3,6,1,9,2};
    InsertSort(arr, 6);
    for(int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}