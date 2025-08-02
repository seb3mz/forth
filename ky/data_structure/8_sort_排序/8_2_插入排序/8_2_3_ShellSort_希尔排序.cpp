#include <iostream>
using namespace std;

void InsertSort(int A[], int n)
{
    int dk, i, j;
    for(dk = n/2; dk >= 1; dk = dk/2)
    {
        for(i = dk; i < n; i++)
        {
            int tmp = A[i];
            for(j = i-dk; j >= 0 && A[j] > tmp; j-= dk)
            {
                A[j+dk] = A[j];
            }
            A[j+dk] = tmp;
        }
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