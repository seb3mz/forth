#include <iostream>
#include "/home/seb3mz/work/code/ky/data_structure/2_linear_list_线性表/21_sequence_table_顺序表/211_static_sequence_table_静态顺序表.h"
using namespace std;

/*
    功能:将两个有序顺序表合并成一个新的有序顺序表
    输入:
        SqList& Resql:新表
        const SqList& L1:有序表1
        const SqList& L2:有序表2
    输出:
        void
    分析思路:
        根据有序表的结构，分别遍历并比对 L1、L2 表元素大小，按照从小到大顺序插入新表 Resql 中
    实现细节:
        定义变量 L1_pos 表示正在遍历顺序表 L1 中的当前元素位序，初始值为 1，当该位置的元素大于 L2_pos 位置的元素，则不动;否则更新
        定义变量 L2_pos 表示正在遍历顺序表 L2 中的当前元素位序，初始值为 1，当该位置的元素大于 L1_pos 位置的元素，则不动;否则更新
        遍历完其中一个表后，剩余的表直接赋值到 Resql 的后边
    注意点:
        
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

void MergeList(SqList<int>& Resql, const SqList<int>& L1, const SqList<int>& L2)
{
    //1. 判空
    if(L1.Empty() || L2.Empty())
    {
        cout << "表空" << endl;
        return;
    }
    //2. 判满
    if(L1.Length() + L2.Length() > MaxSize)
    {
        cout << "表长不足" << endl;
        return;
    }
    //3. 比对 L1 和 L2 元素，并插入新表 Resql 中
    int Resql_pos = 1, L1_pos = 1, L2_pos = 1;
    while(L1_pos <= L1.Length() && L2_pos <= L2.Length())
    {
        if(L1.GetElem(L1_pos) >= L2.GetElem(L2_pos))
        {
            Resql.ListInsert(Resql_pos++, L2.GetElem(L2_pos++));
        }
        else
        {
            Resql.ListInsert(Resql_pos++, L1.GetElem(L1_pos++));
        }
    }
    //4. 将剩余元素插入 Resql 中
    while(L1_pos <= L1.Length())
    {
        Resql.ListInsert(Resql_pos++, L1.GetElem(L1_pos++));
    }

    while(L2_pos <= L2.Length())
    {
        Resql.ListInsert(Resql_pos++, L2.GetElem(L2_pos++));
    }

}

int main()
{
    SqList<int> Resql, Sql1, Sql2;
    Sql1.InitList();
    Sql1.ListInsert(1,3);
    Sql1.ListInsert(2,8);
    Sql1.ListInsert(3,35);
    Sql1.ListInsert(4,70);
    Sql1.printSeq();

    Sql2.InitList();
    Sql2.ListInsert(1,1);
    Sql2.ListInsert(2,10);
    Sql2.ListInsert(3,100);
    Sql2.ListInsert(4,111);
    Sql2.printSeq();

    Resql.InitList();
    MergeList(Resql, Sql1, Sql2);
    Resql.printSeq();

    return 0;
}