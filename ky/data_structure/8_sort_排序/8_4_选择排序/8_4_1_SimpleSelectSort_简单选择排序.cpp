#include <iostream>
using namespace std;

void SimpleSelectSort(int arr[], int n)
{
    for(int cnt = 0; cnt < n-1; cnt++)
    {
        int min = arr[cnt];
        int index = cnt;
        int tmp;
        for(int i = cnt+1; i < n; i++)
        {
            if(arr[i] < min)
            {
                index = i;
                min = arr[i];
            }
        }
        cout << "index:" << index << endl;
        tmp = arr[cnt];
        arr[cnt] = arr[index];
        arr[index] = tmp;
    }
}

int main()
{
    int arr[] = {10,3,6,1,9,2};
    SimpleSelectSort(arr, 6);
    for(int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}