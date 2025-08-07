#include <iostream>
using namespace std;

void Merge(int arr[], int low, int mid, int high)
{
    int arr_bak[high - low + 1];
    for(int i = low; i <= high; i++)
    {
        arr_bak[i] = arr[i];
    }
    int low_index = low;
    int high_index = mid+1;
    int arr_bak_index = low;

    while(low_index <= mid && high_index <= high)
    {
        if(arr[low_index] < arr[high_index])
        {
            arr[arr_bak_index] = arr_bak[low_index];
            arr_bak_index++;
            low_index++;
        }
        else
        {
            arr[arr_bak_index] = arr_bak[high_index];
            arr_bak_index++;
            high_index++;
        }
    }

    while(low_index <= mid)
    {
        arr[arr_bak_index] = arr_bak[low_index];
        arr_bak_index++;
        low_index++;
    }

    while(high_index <= high)
    {
        arr[arr_bak_index] = arr_bak[high_index];
        arr_bak_index++;
        high_index++;
    }
}

void MergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        Merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {10,3,6,1,9,2};
    MergeSort(arr, 1, 5);
    for(int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}