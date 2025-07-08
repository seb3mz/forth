#include <iostream>
using namespace std;

//1. 一般线性表的顺序查找
typedef struct {
    int *elem;  //动态数组基址
    int TableLen;   //表长
} SSTable;

int Binary_Search(SSTable ST, int key)
{
    int low = 0;
    int high = ST.TableLen - 1;

    while(low <= high)
    {
        int mid = (low + high)/2;
        if(ST.elem[mid] == key)
        {
            return mid;
        }
        else if(ST.elem[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    return 0;
}