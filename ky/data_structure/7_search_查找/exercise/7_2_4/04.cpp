#include <iostream>
using namespace std;

/*
    功能:
        递归折半查找
    输入:
    输出:
        bool:
    分析思路:
    实现细节:
    注意点:
    时间复杂度:
    空间复杂度:
*/


bool RecursiveHalfSearch(int elem[], int key, int low, int high)
{
    if(low > high)
        return false;
    int mid = (low+high)/2;
    if(elem[mid] == key)
    {
        return true;
    }
    else if(elem[mid] > key)
    {
        return RecursiveHalfSearch(elem, key, low, mid-1);
    }
    else if(elem[mid] < key)
    {
        return RecursiveHalfSearch(elem, key, mid+1, high);
    }
}

int main()
{
    return 0;
}