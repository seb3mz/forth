#include <iostream>
using namespace std;

//1. 一般线性表的顺序查找
typedef struct {
    int *elem;  //动态数组基址
    int TableLen;   //表长
} SSTable;

int Search_Seq(SSTable ST, int key)
{
    ST.elem[0] = key;   //哨兵
    int i = ST.TableLen-1;
    
    for(; ST.elem[i]!= key; i--);

    return i;
}

//2. 有序表的顺序查找:从小到大排列
int Search_Sorted_Seq(SSTable ST, int key)
{
    for(int i = 0; i < ST.TableLen; i++)
    {
        if(ST.elem[i]== key)
        {
            return i;
        }
        else if(ST.elem[i] > key)
        {
            return -1;
        }
    }
}

int main()
{
    return 0;
}