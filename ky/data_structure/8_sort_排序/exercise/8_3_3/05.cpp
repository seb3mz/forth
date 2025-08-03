#include <iostream>
using namespace std;

/*
    01.算法思想:排序后找到中间位置，前半段和后半段  
*/

int setPartition(int a[], int n)
{
    int pivotkey, low = 0, low0 = 0, high = n-1, high0 = n-1, flag = 1, k = n/2, i;
    int s1 = 0, s2 = 0;
    while(flag)
    {
        pivotkey = a[low];
        while(low < high)
        {
            while(low < high && a[high] >= pivotkey)
                --high;
            if(low != high)
                a[low] = a[high];
            while(low < high && a[low] <= pivotkey)
                ++low;
            if(low != high)
                a[high] = a[low];
        }
        a[low] = pivotkey;
        if(low == k-1)
            flag = 0;
        else
        {
            if(low < k-1)
            {
                low0 = ++low;
                high = high0;
            }
            else
            {
                high0 = --high;
                low = low0;
            }
        }
    }
    for(i = 0; i < k; i++)
        s1+=a[i];
    for(i = k; i < n; i++)
        s2+=a[i];

    return s2-s1;
}

int main()
{
    int arr[] = {10,3,6,1,9,2};
    return 0;
}