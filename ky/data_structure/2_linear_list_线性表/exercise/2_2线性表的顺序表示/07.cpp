#include <iostream>
#include "/home/seb3mz/work/code/ky/data_structure/2_linear_list_线性表/21_sequence_table_顺序表/211_static_sequence_table_静态顺序表.h"
using namespace std;

/*
    功能:将一个数组内的两个顺序表的位置互换 (a1,a2,...,am)和(b1,b2,...bn) 换为 (b1,b2,...bn)和(a1,a2,...am)
    输入:
        SqList& sql; //待置换元素位置的顺序表
    输出:
        void
    分析思路:
        将顺序表 a1,a2,...bn 逆序得到 bn,bn-1,...,am,am-1,...a2,a1
        再将 bn,..b1 逆序得 b1,b2,...,bn
        再将 am,am-1,...a2,a1 逆序的 a1,a2,...am-1,am
    实现细节:
        
    注意点:
        
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

void ReverseSql(SqList<int>& L, int start, int end)
{
    //1. 反转顺序表, 将位序为 pos 和 L.length()+1-pos 的元素互换位置
    int tmp = 0;
    for(int pos = start; pos <= (start+end)/2; pos++)
    {
        tmp = L[pos]; 
        L[pos] = L[end-(pos-start)];
        L[end-(pos-start)] = tmp;
    }
}

void SwapPosOfSeqTable(SqList<int>& sql, int m, int n)
{
    //1. 判空
    if(sql.Empty())
    {
        cout << "空表" << endl;
        return;
    }

    ReverseSql(sql, 1, m+n);
    ReverseSql(sql, 1, n);
    ReverseSql(sql, n+1, m+n);
}

int main()
{
    SqList<int> Sql;
    Sql.InitList();
    Sql.ListInsert(1,1);
    Sql.ListInsert(2,2);
    Sql.ListInsert(3,3);
    Sql.ListInsert(4,4);
    Sql.ListInsert(5,5);
    Sql.ListInsert(6,11);
    Sql.ListInsert(7,12);
    Sql.ListInsert(8,13);
    Sql.ListInsert(9,14);
    Sql.ListInsert(10,15);
    Sql.ListInsert(11,16);
    Sql.printSeq();

    SwapPosOfSeqTable(Sql, 5, 6);

    Sql.printSeq();
    return 0;
}