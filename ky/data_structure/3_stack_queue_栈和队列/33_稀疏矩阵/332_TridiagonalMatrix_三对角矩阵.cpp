#include <iostream>
#include <cmath>
using namespace std;

/*
        Matrix =
                    1 2
                    3 4 5
                      6 7 8
                        ......
                            aa ab
            n 行共有
            2+2+(n-2)*3=3n-2
            第 i 行，第 j 列
            k=2+(i-2)*3+j-i+2-1=2i+j-3
*/ 

void MapMatrixToArr(int matrix[][6], int *arr)
{
    for(int i = 1; i <= 6; i++)
    {
        for(int j = 1; j <= 6; j++)
        {
            if(matrix[i-1][j-1] != 0)
            {
                arr[2*i+j-3] = matrix[i-1][j-1];
            }
        }
    }
}

int main()
{
    int matrix[][6] = {1,2,0,0,0,0,
                       3,4,5,0,0,0,
                       0,6,7,8,0,0,
                       0,0,9,10,11,0,
                       0,0,0,12,13,14,
                       0,0,0,0,15,16};

    int num = sqrt(sizeof(matrix)/sizeof(int))*3-2;
    int arr[num] = {0};
    
    MapMatrixToArr(matrix, arr);

    return 0;
}