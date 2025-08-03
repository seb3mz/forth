#include <iostream>
using namespace std;

/*
    功能:找出数组 L[1...n]中找出第 k 小的元素
    输入:
        
    输出:
        void:
    分析思路:
       
    实现细节:
    注意点:
    时间复杂度:
            
    空间复杂度:  
*/

int k = 5;

int Partition(int arr[], int left, int right)
{
    int pivot = arr[left]; // 选择最左边的元素作为基准
    while(left < right)
    {
        while(arr[right] >= pivot && left < right)
            right--;
        arr[left] = arr[right];

        while(arr[left] <= pivot && left < right)
            left++;
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    return left;
}

int QuickSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = Partition(arr, left, right);
        if(mid == k)
        {
            return arr[mid];
        }
        else if(mid > k)
        {
            QuickSort(arr, left, mid - 1);
        }
        else
        {
            QuickSort(arr, mid + 1, right);
        }
    }
}

int main()
{
    int arr[] = {10,3,6,1,9,2};
    cout << QuickSort(arr, 0, 5) << endl;
    return 0;
}