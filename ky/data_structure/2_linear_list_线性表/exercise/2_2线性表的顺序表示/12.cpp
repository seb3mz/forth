#include <iostream>
#include "../../21_sequence_table_顺序表/211_static_sequence_table_静态顺序表.h"
using namespace std;

/*
    功能:找到数组 A 中的主元素，找不到输出 -1
    输入:
        const SqList& sql
    输出
        int:主元素 or -1
    分析思路:
        //方案 A
        要找出主元素，实质是统计顺序表中各元素的个数，找出元素个数大于 n/2 的元素
        如果前 n/2+1 个值中没有相同元素，则不存在主元素
        如果前 n/2+1 个值中只有1个元素出现两次以上，则在后 n/2-1 个值中统计这个元素出现的个数
        //方案 B
        考虑到每个元素范围在 [0,n)之间，可以使用一个数组 a[n], a[i] 代表值为 i 的元素出现的次数
        遍历依次整数序列 A，统计各个元素出现的次数到 a[n]，判断第一个大于 n/2 的元素，即为主元素

    实现细节:
        //方案 B
        定义一个数组 a[n] 存放各个元素出现的次数，找到第一个

    注意点:
        
    时间复杂度:
        O(n)
    空间复杂度:
        O(n)
*/

int FindMain(const SqList<int>& sql)
{
    //1. 判空
    if(sql.Empty())
    {
        cout << "表空" << endl;
        return -1;
    }
    //2. 统计个元素出现次数
    int mainvalue = -1;
    int a[sql.Length()]={0};
    for(int pos = 1; pos <= sql.Length(); pos++)
    {
        a[sql.GetElem(pos)]++;
        if(a[sql.GetElem(pos)] > sql.Length()/2)
        {
            mainvalue = sql.GetElem(pos);
            break;
        }
    }
    return mainvalue;
}

int main()
{
    SqList<int> Sql1;
    Sql1.InitList();
    Sql1.ListInsert(1,6);
    Sql1.ListInsert(2,1);
    Sql1.ListInsert(3,0);
    Sql1.ListInsert(4,2);
    Sql1.ListInsert(5,2);
    Sql1.ListInsert(6,6);
    Sql1.ListInsert(7,6);
    Sql1.ListInsert(8,6);
    Sql1.ListInsert(9,6);
    Sql1.ListInsert(10,6);
    Sql1.printSeq();
    cout << FindMain(Sql1) << endl;
    return 0;
}