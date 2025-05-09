#include <iostream>
#include "/home/seb3mz/work/code/ky/data_structure/2_linear_list_线性表/21_sequence_table_顺序表/211_static_sequence_table_静态顺序表.h"
using namespace std;

/*
    功能:从顺序表中删除最小元素，并由函数返回该值
    输入:
        SqList& L:待删除最小值的静态顺序表
        int& val: 最小值
    输出:
        void
    分析思路:
       遍历顺序表，把最小值与所有元素比对，找到最小值
    实现细节:
        定义变量 smallest = L.data[0], pos = 1;
        依次比对所有元素，记录下最小值 smallest 和其位序 pos
    注意点:
        a. 顺序表为空时，显示错误信息并退出
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

void DeleteSmallest(SqList<int>& L, int& value)
{
    //1. 判断顺序表是否为空
    if(L.Empty())
    {
        cout << "顺序表为空" << endl;
        return;
    }

    //2. 定义临时变量 smallest 存储最小值, smallpos 存储最小值位序
    int smallest = L.GetElem(1);
    int smallpos = 1;

    //3. 遍历顺序表元素并与 smallest 比较，若比 smallest 小则记录下值并记录下位序
    for(int pos = 2; pos <= L.Length(); pos++)
    {
        if(smallest > L.GetElem(pos))
        {
            smallest = L.GetElem(pos);
            smallpos = pos;
        }
    }

    //4. 返回最小值，并用最后一个元素替换成被删除的元素
    value = smallest;
    //此处未对顺序表长度减去1操作
    L[smallpos] = L.GetElem(L.Length());
    L.DecreaseLength();
    //L.length--
}

int main()
{
    SqList<int> Sql;
    Sql.InitList();
    Sql.ListInsert(1,3);
    Sql.ListInsert(2,8);
    Sql.ListInsert(3,90);
    Sql.ListInsert(4,1);
    Sql.ListInsert(5,35);
    Sql.printSeq();

    int small;
    DeleteSmallest(Sql, small);
    cout << small << endl;
    Sql.printSeq();
    return 0;
}