#include <iostream>
#include "../../21_sequence_table_顺序表/211_static_sequence_table_静态顺序表.h"
using namespace std;

/*
    功能:找到两个序列A和B的中位数
    输入:
        const SqList& A
        const SqList& B
        int &middle:中位数
    输出
        bool:查找是否成功
    分析思路:
        顺序表升序排列，按照大小找到第 n 个元素即可
    实现细节:
        定义位置索引 A_pos 和  B_pos 分别指向 A 中元素和 B 中元素
        依次遍历找到 A_pos+B_pos == n 位置的元素即是中位数
    注意点:
        
    时间复杂度:
        O(n)
    空间复杂度:
        O(1)
*/

bool FindMiddle(const SqList<int>& A, const SqList<int>& B, int &middle)
{
    //1. 判空
    if(A.Empty() || B.Empty())
    {
        cout << "空表" << endl;
        return false;
    }
    //2. 遍历对比查找直到找到第 middle_pos 个元素
    int A_pos = 1, B_pos = 1, middle_pos = (A.Length()+B.Length())%2?(A.Length()+B.Length())/2+1:(A.Length()+B.Length())/2;
    int cnt = 0;
    while(A_pos <= A.Length() && B_pos <= B.Length() && cnt < middle_pos)
    {
        if(A.GetElem(A_pos) >= B.GetElem(B_pos))
        {
            middle = B.GetElem(B_pos);
            B_pos++;
        }
        else
        {
            middle = A.GetElem(A_pos);
            A_pos++;
        }   
        cnt++;
    }

    if(cnt < middle_pos)
    {
        while(A_pos <= A.Length() && cnt < middle_pos)
        {
            middle = A.GetElem(A_pos);
            A_pos++;
            cnt++;
        }
        while(B_pos <= B.Length() && cnt < middle_pos)
        {
            middle = B.GetElem(B_pos);
            B_pos++;
            cnt++;
        }
    }
    
    cout << "found middle:" << middle << endl;
    return true;
}

int main()
{
    SqList<int> Sql1, Sql2;

    Sql1.InitList();
    Sql1.ListInsert(1,1);
    Sql1.ListInsert(2,8);
    Sql1.ListInsert(3,22);
    Sql1.ListInsert(4,48);
    Sql1.printSeq();

    Sql2.InitList();
    Sql2.ListInsert(1,2);
    Sql2.ListInsert(2,29);
    Sql2.ListInsert(3,33);
    Sql2.ListInsert(4,55);
    Sql2.printSeq();


    int middle = -1;
    FindMiddle(Sql1, Sql2, middle);
    return 0;
}