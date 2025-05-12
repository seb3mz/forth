#include <iostream>
#include "../../21_sequence_table_顺序表/211_static_sequence_table_静态顺序表.h"
using namespace std;

/*
    功能:找到数组中未出现的最小正整数
    输入:
        const SqList& A
    输出
        int:最小正整数
    分析思路:
        要找到数组中未出现的最小正整数，必须遍历整个数组
        需要查找数组中的值未出现在 [1,n] 中的第一个即为未出现的最小正整数，如果都有，则最小正整数为 n+1
    实现细节:
        定义一个数组 bool a[n]，遍历A，将 A 中的值如果处于 [1, n] 按照对应关系 [0, n-1] 设置为 true
        然后遍历数组 a，第一个为 false 的值即为未出现的最小正整数
    注意点:
        
    时间复杂度:
        O(n)
    空间复杂度:
        O(n)
*/

int FindNotExistSmallest(const SqList<int>& sql)
{
    //1. 判空
    if(sql.Empty())
    {
        cout << "表空" << endl;
        return -1;
    }
    //2. 遍历 sql 并统计
    bool a[sql.Length()+1] = {0};
    for(int pos = 1; pos <= sql.Length(); pos++)
    {
        if(sql.GetElem(pos) >= 1 && sql.GetElem(pos) <= sql.Length())
        {
            a[sql.GetElem(pos)] = true;
        }
    }
    int smallest = sql.Length()+1;
    for(int pos = 1; pos <= sql.Length(); pos++)
    {
        if(a[pos] == false)
        {
            smallest = pos;
            break;
        }
    }

    return smallest;
}

int main()
{
    SqList<int> Sql1;
    Sql1.InitList();
    Sql1.ListInsert(1,1);
    Sql1.ListInsert(2,2);
    Sql1.ListInsert(3,3);
    Sql1.printSeq();

    cout << FindNotExistSmallest(Sql1) << endl;

    return 0;
}