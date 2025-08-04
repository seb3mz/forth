#include <iostream>
using namespace std;

//判断序列是否是小根堆
//需要判断结点数目是奇数还是偶数
bool IsSmallHeap(int arr[], int n)
{
    bool result = true;
    for(int i = 1; i <= n/2; i++)
    {
        if(arr[i] > arr[2*i] || arr[i] > arr[2*i+1])
        {
            result = false;
            break;
        }
    }

    return result;
}

int main()
{
    return 0;
}