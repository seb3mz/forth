#include <iostream>
using namespace std;

void InsertSort(int A[], int n)
{
    int i, j, low, mid, high, tmp;
    for(i = 1; i < n; i++)
    {
        tmp = A[i];
        low = 0;
        high = i-1;
        mid = (low+high)/2;
        while(low <= high)
        {
            if(A[mid] > A[i])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            mid = (low+high)/2;
        }
        for(j = i-1; j >= high + 1; j--)
        {
            A[j+1] = A[j];
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