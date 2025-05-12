#include <iostream>
#include "../../21_sequence_table_顺序表/211_static_sequence_table_静态顺序表.h"
using namespace std;

/*
    功能:将数组 R 中的元素 a1,a2,a3,...an 循环左移 p 个位置，得到 ap,ap+1,....
    输入:
        SqList& Sql
        int p: 循环左移的次数
    输出
        void:
    分析思路:
        原本的序列为  A1,A2,...Ap-1,Ap,Ap+1,...An-1,An
        移动后序列为  Ap+1,Ap+2,....An,A1,A2,...Ap
        由 An,An-1,...,Ap+1,Ap,Ap-1,....A2,A1 分为两段 [An,An-1,...Ap+1] 和 [Ap,Ap-1,...A2,A1] 分别逆序得到
    实现细节:
        先对整个数组逆序
        再分别对前 n-p 个元素逆序，再对后 p 个元素逆序即得
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

void RotateLeft(SqList<int>& Sql, int p)
{
    //1. 判空
    if(Sql.Empty())
    {
        cout << "表空" << endl;
        return;
    }
    //2. 分段逆置
    ReverseSql(Sql, 1, Sql.Length());
    ReverseSql(Sql, 1, Sql.Length()-p);
    ReverseSql(Sql, Sql.Length()-p+1, Sql.Length());
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
    Sql.ListInsert(7,22);
    Sql.ListInsert(8,33);
    Sql.printSeq();

    RotateLeft(Sql, 3);
    Sql.printSeq();
    return 0;
}