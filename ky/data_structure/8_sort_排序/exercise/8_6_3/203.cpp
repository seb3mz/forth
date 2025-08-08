#include <iostream>
using namespace std;

int FindK(int arr[], int k)
{
    int count = 0;
    for(int i = 0; i < k; i++)
    {
        if(arr[i] < arr[k-1])
            count++;
    }

    return count;
}



int main()
{
    return 0;
}