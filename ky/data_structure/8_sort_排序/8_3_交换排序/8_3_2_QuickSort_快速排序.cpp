#include <iostream>
using namespace std;

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

void QuickSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = Partition(arr, left, right);
        QuickSort(arr, left, mid - 1);
        QuickSort(arr, mid + 1, right);
    }
}

int main()
{
    int arr[] = {10,3,6,1,9,2};
    QuickSort(arr, 0, 5);
    for(int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}