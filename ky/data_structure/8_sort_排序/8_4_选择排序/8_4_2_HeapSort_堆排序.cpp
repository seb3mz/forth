#include <iostream>
using namespace std;

void HeadAdjust(int arr[], int i, int len)
{
    while(i <= len/2)
    {
        if(2*i+1 <= len)
        {   
            int max_index;
            if(arr[2*i] > arr[2*i+1])
            {
                max_index = 2*i;
            }
            else
            {
                max_index = 2*i+1;
            }

            if(arr[i] < arr[max_index])
            {
                arr[0] = arr[max_index];
                arr[max_index] = arr[i];
                arr[i] = arr[0];
                i = max_index;
            }
            else
            {
                break;
            }
        }
        else
        {
            if(arr[i] < arr[2*i])
            {
                arr[0] = arr[2*i];
                arr[2*i] = arr[i];
                arr[i] = arr[0];
                i = 2*i;
            }
            else
            {
                break;
            }
        }
    }
}

void BuildMaxHeap(int arr[], int len)
{
    for(int i = len/2; i > 0; i--)
    {
        HeadAdjust(arr, i, len);
    }
}

void HeapSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        cout << arr[1] << " ";
        arr[1] = arr[n-i];
        BuildMaxHeap(arr, n-i-1);
    }
    cout << endl;
}


int main()
{
    int arr[] = {-1,10,3,6,1,9,2};
    BuildMaxHeap(arr, 6);
    for(int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    HeapSort(arr, 7);
    return 0;
}