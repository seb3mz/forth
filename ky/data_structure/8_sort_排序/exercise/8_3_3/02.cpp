#include <iostream>
using namespace std;

/*
    功能:将所有奇数移动到所有偶数前面
    输入:
        
    输出:
        void:
    分析思路:
       
    实现细节:
    注意点:
    时间复杂度:
            
    空间复杂度:  
*/

void MoveOddBeforeEven(int arr[], int n)
{
    int low = 0, high = n-1;
    int tmp = arr[low];
    while(low < high)
    {
        while(arr[high]%2 == 0 && low <= high)
            high--;
        arr[low] = arr[high];

        while(arr[low]%2 == 1 && low <= high)
            low++;
         arr[high] = arr[low];
    }
    arr[low] = tmp;
}

int main()
{
    int arr[] = {10,3,6,1,9,2};
    MoveOddBeforeEven(arr, 6);
    for(int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}