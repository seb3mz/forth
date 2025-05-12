#include <iostream>
#include "../../21_sequence_table_顺序表/211_static_sequence_table_静态顺序表.h"
using namespace std;

/*
    功能:在无重复元素递增序列 A、B、C中找到都存在的元素

    输入:
        const SqList& A
        const SqList& B
        const SqList& C
    输出
        void:
    分析思路:
        根据序列特点:无重复且递增，用三个遍历索引分别遍历三个序列，
    实现细节:
        定义 A_pos、B_pos、C_pos 分别用来作为A、B、C的索引
        先找到 A、B 相等的元素，然后再去对比 C 中的元素:
                                        若找到相等元素，输出该值，并且所有索引向后移动一位
                                        若找到第一个大于该值的元素，则 A_pos B_pos 向后移动一位继续进行重新开始比较
                                        若未找到大于该值的元素，则未找到任何相等元素
    注意点:
        
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

void FindSameValue(const SqList<int>& A, const SqList<int>& B, const SqList<int>& C)
{
    //1. 判空
    if(A.Empty() || B.Empty() || C.Empty())
    {
        cout << "表空" << endl;
        return;
    }

    //2. 开始遍历比对
    int A_pos = 1, B_pos = 1, C_pos = 1;
    while(A_pos <= A.Length() && B_pos <= B.Length() && C_pos <= C.Length())
    {
        // A_pos 位置的值与 B_pos 的值相等，此时去遍历 C
        if(A.GetElem(A_pos) == B.GetElem(B_pos))
        {
            if(A.GetElem(A_pos) == C.GetElem(C_pos))
            {
                cout << A.GetElem(A_pos) << endl;
                A_pos++;
                B_pos++;
                C_pos++;
            }
            else if(A.GetElem(A_pos) > C.GetElem(C_pos))
            {
                C_pos++;
            }
            else
            {
                A_pos++;
                B_pos++;
            }
        }
        else if(A.GetElem(A_pos) > B.GetElem(B_pos))
        {
            B_pos++;
        }
        else
        {
            A_pos++;
        }
    }
}

int main()
{
    SqList<int> SqlA, SqlB, SqlC;
    SqlA.InitList();
    SqlA.ListInsert(1,1);
    SqlA.ListInsert(2,4);
    SqlA.ListInsert(3,8);
    SqlA.ListInsert(4,41);
    SqlA.ListInsert(5,55);
    SqlA.printSeq();

    SqlB.InitList();
    SqlB.ListInsert(1,3);
    SqlB.ListInsert(2,4);
    SqlB.ListInsert(3,9);
    SqlB.ListInsert(4,33);
    SqlB.ListInsert(5,55);
    SqlB.printSeq();

    SqlC.InitList();
    SqlC.ListInsert(1,1);
    SqlC.ListInsert(2,2);
    SqlC.ListInsert(3,4);
    SqlC.ListInsert(4,55);
    SqlC.ListInsert(5,66);
    SqlC.printSeq();

    FindSameValue(SqlA, SqlB, SqlC);
    
    return 0;
}