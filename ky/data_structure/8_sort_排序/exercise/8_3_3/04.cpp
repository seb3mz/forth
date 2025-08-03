#include <iostream>
using namespace std;

/*
    功能:按照红白蓝序列排列
    输入:
        
    输出:
        void:
    分析思路:
       
    实现细节:
    注意点:
    时间复杂度:
            
    空间复杂度:  
*/
typedef enum {RED, WHITE, BLUE} color;  //设置枚举数组
void Flag_Arrange(color a[], int n)
{
    int i = 0, j = 0, k = n-1;
    color tmp;

    while(j <= k)
    {
        switch (a[j])
        {
        case RED:
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            ++i;
            ++j;
            break;
        case WHITE:
            ++j;
            break;
        case BLUE:
            tmp = a[i];
            a[i] = a[k];
            a[k] = tmp;
            --k;
            break;
        }
    }
}


int main()
{
    int arr[] = {10,3,6,1,9,2};
    return 0;
}