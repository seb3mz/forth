#include <iostream>
using namespace std;

/*
    功能:
        1. 搜索矩阵是否存在某个值
    输入:
    输出:

    分析思路:
    实现细节:
    注意点:
    时间复杂度: O(log2n)
    空间复杂度: O(1)
*/

bool IsExistInMatrix(int arr[][10], int key)
{
    if(key < arr[0][0] || key > arr[9][9])
    {
        return false;
    }

    int low_column = 0;
    int high_column = 9;

    while(low_column <= high_column)
    {
        int mid_column = (low_column+high_column)/2;
        if(arr[mid_column][0] == key)
        {
            return true;
        }
        else if(arr[mid_column][0] > key)
        {
            high_column = mid_column-1;
        }
        else
        {
            low_column = mid_column+1;
        }
    }

    int low_row = 0;
    int hight_row = 9;

    while(low_row <= hight_row)
    {
        int mid_row = (low_row+hight_row)/2;
        if(arr[high_column][mid_row] == key)
        {
            return true;
        }
        else if(arr[high_column][0] > key)
        {
            hight_row = mid_row-1;
        }
        else
        {
            low_row = mid_row+1;
        }
    }

    return false;
}

int main()
{
    return 0;
}