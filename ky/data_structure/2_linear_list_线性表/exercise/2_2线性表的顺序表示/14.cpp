#include <iostream>
#include "../../21_sequence_table_顺序表/211_static_sequence_table_静态顺序表.h"
using namespace std;

/*
    功能:查找非空整数集合 S1,S2,S3 中距离最小的三元组
    输入:
        const SqList<int>& Sql1;
        const SqList<int>& Sql2;
        const SqList<int>& Sql3;
    输出
        void
    分析思路:
        将3个顺序表排序成1个顺序表，
        表中如果出现 s1,s2,s3 连续的三个元素，则三个元素之间的距离最小，找出所有3个连续的多组元素，比较得出最小的
        S1、S2、S3 三个整数集合中的元素根据大小排序，相对位置是固定的，根据 smallest、middle、biggest(三个分属不同的集合) 排序，只需要
        找到 biggest-smallest 为最小的即可
    实现细节:
        
    注意点:
        
    时间复杂度:
        O(n)
    空间复杂度:
        O(n)
*/

int ab_(int value)
{
    if(value < 0)
        return -value;
    else
        return value;
}

bool isSmallest(int a, int b, int c)
{
    if(a <= b && a <= c)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int FindSmallest(const SqList<int>& S1, const SqList<int>& S2, const SqList<int>& S3)
{
    int s1_pos = 1, s2_pos = 1, s3_pos = 1;
    int smallestdistance = 0x7fffffff;
    int tmpdistance = 0;
    while(s1_pos <= S1.Length() && s2_pos <= S2.Length() && s3_pos <= S3.Length() && smallestdistance > 0)
    {
        tmpdistance = ab_(S1.GetElem(s1_pos)-S2.GetElem(s2_pos)) + ab_(S2.GetElem(s2_pos)-S3.GetElem(s3_pos)) + ab_(S3.GetElem(s3_pos)-S1.GetElem(s1_pos)) ;
        if(tmpdistance < smallestdistance)
        {
            smallestdistance = tmpdistance;
        }
        if(isSmallest(S1.GetElem(s1_pos), S2.GetElem(s2_pos), S3.GetElem(s3_pos)))
        {
            s1_pos++;
        }
        else if(isSmallest(S2.GetElem(s2_pos), S1.GetElem(s1_pos), S3.GetElem(s3_pos)))
        {
            s2_pos++;
        }
        else
        {
            s3_pos++;
        }
    }
    return smallestdistance;
}

int main()
{
    SqList<int> Sql1, Sql2, Sql3;
    Sql1.InitList();
    Sql1.ListInsert(1,-1);
    Sql1.ListInsert(2,0);
    Sql1.ListInsert(3,9);
    Sql1.printSeq();

    Sql2.InitList();
    Sql2.ListInsert(1,-25);
    Sql2.ListInsert(2,-10);
    Sql2.ListInsert(3,10);
    Sql2.ListInsert(4,11);
    Sql2.printSeq();

    Sql3.InitList();
    Sql3.ListInsert(1,2);
    Sql3.ListInsert(2,9);
    Sql3.ListInsert(3,17);
    Sql3.ListInsert(4,30);
    Sql3.ListInsert(5,41);
    Sql3.printSeq();

    cout << FindSmallest(Sql1, Sql2, Sql3) << endl;

    return 0;
}