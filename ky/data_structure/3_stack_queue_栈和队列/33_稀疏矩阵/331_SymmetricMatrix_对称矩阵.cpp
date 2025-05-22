#include <iostream>
#include <cmath>
using namespace std;

/*
    Matrix = 
                1 2 4 7
                2 3 5 8
                4 5 6 9
                7 8 9 10

                1+2+3+4
                1+2+3+...+n = (1+n)*n/2
*/

void MapMatrixToArr(int matrix[][4], int *arr)
{
    for(int i_m = 1; i_m <= 4; i_m++)
    {
        for(int j_m = 1; j_m <= 4; j_m++)
        {
            if(i_m >= j_m)
            {
                /*  
                    i_m 行, j_m 列
                    1+2+..i_m-1+j_m-1
                    (1+i_m-1)(i_m-1)/2+j_m-1
                    
                */
                arr[i_m*(i_m-1)/2+j_m-1] = matrix[i_m-1][j_m-1];
            }
        }
    }
}

int ArrToV(int *arr, int i, int j)
{
    //第 i 行，第 j 列
    if(i >= j)
    {
        return arr[i*(i-1)/2+j-1];
    }
    else
    {
        return arr[j*(j-1)/2+i-1];
    }
}

int main()
{
    int i = 3, j = 4;
    int matrix[][4] = {1, 2, 4, 7, 2, 3, 5, 8, 4, 5, 6, 9, 7, 8, 9, 10};
    int num = sqrt(sizeof(matrix)/sizeof(int))*(sqrt(sizeof(matrix)/sizeof(int))+1)/2;
    
    int arr[num] = {0};

    MapMatrixToArr(matrix, arr);
    
    cout << "第 " << i << " 行," << "第 " << j << " 列值:" << ArrToV(arr, i, j) <<endl;
    return 0;
}