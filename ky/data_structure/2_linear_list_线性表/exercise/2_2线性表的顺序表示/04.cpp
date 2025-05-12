#include <iostream>
#include "../../21_sequence_table_顺序表/211_static_sequence_table_静态顺序表.h"
using namespace std;

/*
    功能:删除顺序表中所有值为 x 的元素
    输入:
        SqList& L:待删除固定值的顺序表
        int x: 待删除的值
    输出:
        void
    分析思路:
        从头开始遍历顺序表，并与 s、t 进行比对，如果比对上，则删除掉该值
    实现细节:
        删除 x 后需要把后续的元素向前移动，假设顺序表元素个数为 n，值处于为 (s,t) 的元素个数为 m，
        则剩下的 n-m 个元素分别放到位序 [1, n-m]的位置，且相对位置不变
            定义变量 after_pos 表示删除所有 x 后移动完成后的位置，当遍历到的值不处于 (s,t) 则进行加1,当遍历到的值处于 (s,t),则不变
            定义变量 before_pos 表示未删除 (s,t)  前的所有元素位置，每次循环都会变化
    注意点:
        
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

void DeleteSpeRV(SqList<int>& L, int s, int t)
{
    //1. 判空
    if(L.Empty())
    {
        cout << "空表" << endl;
        return;
    }
    //2. 判断输入有效性
    if(s >= t)
    {
        cout << "输入范围无效" << endl;
        return;
    }
    //2. 遍历并删除
    int before_pos = 1, after_pos = 1;
    for(; before_pos <= L.Length(); before_pos++)
    {
        //只有当当前元素不是 x 时，将 before_pos 指向的元素移动到 end_pos 位置
        //此处顺序表长度未更改
        if(L.GetElem(before_pos) < s || L.GetElem(before_pos) > t)
        {
            L[after_pos] = L[before_pos];
            after_pos++;
        }
        else
        {
            L.DecreaseLength();
        }
    }

    //3. 表长减去被删除元素的个数
    int cnt = before_pos-after_pos;
    while(cnt)
    {
        L.DecreaseLength();
        cnt--;
    }
}

int main()
{
    SqList<int> Sql;
    Sql.InitList();
    Sql.ListInsert(1,3);
    Sql.ListInsert(2,8);
    Sql.ListInsert(3,90);
    Sql.ListInsert(4,1);
    //Sql.ListInsert(5,35);
    Sql.printSeq();

    DeleteSpeRV(Sql, 5, 10);

    Sql.printSeq();
    return 0;
}