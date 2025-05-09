#include <iostream>
#include "/home/seb3mz/work/code/ky/data_structure/2_linear_list_线性表/21_sequence_table_顺序表/211_static_sequence_table_静态顺序表.h"
using namespace std;

/*
    功能:删除有序顺序表中所有重复的元素
    输入:
        SqList& L:待去重的顺序表
    输出:
        void
    分析思路:
        根据有序顺序表的特点，相同元素相邻存储，遍历元素紧邻的元素如果相同则删除
    实现细节:
        定义一个变量 unique 保存第一次出现的元素
        定义 before_pos 用来遍历顺序表，每次循环更新位置
        定义 after_pos 用来保存不重复元素移动到的位置，在每次遇到不重复元素 unique，将 unique 值移动到该位置，并更新位置
    注意点:
        
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

void UniqueSeq(SqList<int>& L)
{
    //1. 判空
    if(L.Empty())
    {
        cout << "表空" << endl;
        return;
    }

    //2. 遍历并赋值
    int before_pos = 1;
    int after_pos = 1;
    int unique = L[before_pos];
    for(before_pos+=1, after_pos+=1; before_pos <= L.Length(); before_pos++)
    {
        //此处未更改顺序表长度
        if(L.GetElem(before_pos) != unique)
        {
            unique = L.GetElem(before_pos);
            L[after_pos] = unique;
            after_pos++;
        }
    }
    //3. 表长减去 x 的个数
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
    Sql.ListInsert(3,8);
    Sql.ListInsert(4,8);
    Sql.ListInsert(5,35);
    Sql.ListInsert(6,35);
    Sql.ListInsert(7,35);
    Sql.ListInsert(8,70);
    Sql.printSeq();

    UniqueSeq(Sql);

    Sql.printSeq();
}