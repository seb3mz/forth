#include <iostream>
#include "/home/seb3mz/work/code/ky/data_structure/2_linear_list_线性表/21_sequence_table_顺序表/211_static_sequence_table_静态顺序表.h"
using namespace std;

/*
    功能:在有序顺序表中查找给定数值 x
            若找到，将其与后继元素位置互换;
            若找不到，在插入使表中元素仍然有序
    输入:
        SqList& sql; //待置换元素位置的顺序表
        int x;  //待查找元素
    输出:
        void
    分析思路:
        根据有序性质，使用折半查找查找数值
    实现细节:
        定义范围 start、end, 定义待比较的元素位置 cur_pos = (start+end)/2
        将 cur_pos 位置的元素与 x 比较，若大于 x，则从范围 [start, cur_pos] 查找
                                     若小于 x，则从范围 [cur_pos, end] 查找
    注意点:
        
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

void FindXInSql(SqList<int>& sql, int x)
{
    //1. 判空
    if(sql.Empty())
    {
        cout << "空表" << endl;
        return;
    }

    //2. 折半查找
    int start_pos = 1, end_pos = sql.Length();
    int cur_pos = (start_pos+end_pos)/2;
    while(start_pos <= end_pos)
    {
        if(sql.GetElem(cur_pos) == x)
        {
            cout << "found cur_pos:" << cur_pos << endl;
            break;
        }
        else if(sql.GetElem(cur_pos) > x)
        {
            end_pos = cur_pos-1;
            cur_pos = (start_pos+end_pos)/2;
        }
        else
        {
            start_pos = cur_pos+1;
            cur_pos = (start_pos+end_pos)/2;
        }
    }
    //3. 根据 start_pos 和 end_pos 大小判断是否找到
    if(start_pos > end_pos)
    {
        sql.ListInsert(start_pos, x);
    }
    else
    {
        if(cur_pos < sql.Length())
        {
            int tmp = sql[cur_pos];
            sql[cur_pos] = sql[cur_pos+1];
            sql[cur_pos+1] = tmp;
        }
        else
        {
            cout << "被查找元素为最后一个元素,无法与后继元素交换" << endl; 
        }
    }
}

int main()
{
    SqList<int> Sql;
    Sql.InitList();
    Sql.ListInsert(1,1);
    Sql.ListInsert(2,4);
    Sql.ListInsert(3,8);
    Sql.ListInsert(4,41);
    Sql.ListInsert(5,55);

    Sql.printSeq();
    FindXInSql(Sql, 54);
    Sql.printSeq();
    return 0;
}