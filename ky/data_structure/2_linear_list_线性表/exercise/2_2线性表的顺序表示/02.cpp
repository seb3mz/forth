#include <iostream>
#include "../../21_sequence_table_顺序表/211_static_sequence_table_静态顺序表.h"
using namespace std;

/*
    功能:将顺序表所有元素逆置
    输入:
        SqList& L:待逆置的顺序表
    输出:
        void
    分析思路:
        从头开始遍历到顺序表中间位置，把位序为 i 和 n-i+1 的元素互换位置
    实现细节:
        定义中间变量 tmp
    注意点:
        
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

void ReverseSql(SqList<int>& L)
{
    //1. 判空
    if(L.Empty())
    {
        cout << "空表" << endl;
        return;
    }
    //2. 反转顺序表, 将位序为 pos 和 L.length()+1-pos 的元素互换位置
    int tmp = 0;
    for(int pos = 1; pos <= L.Length()/2; pos++)
    {
        tmp = L[pos]; 
        L[pos] = L[L.Length()+1-pos];
        L[L.Length()+1-pos] = tmp;
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

    ReverseSql(Sql);

    Sql.printSeq();
    return 0;
}