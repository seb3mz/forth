#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
    bool swapped = false;
    for(int i = 0; i < n-1; i++)
    {
        swapped = false; // 每次外循环开始时重置交换标志
        for(int j = n - 1; j > i; j--)
        {
            if(arr[j-1] > arr[j])
            {
                swapped = true;
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
        if(!swapped)
        {
            break; // 如果没有交换，说明数组已经有序
        }
    }
}



int main()
{
    int arr[] = {10,3,6,1,9,2};
    BubbleSort(arr, 6);
    for(int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}