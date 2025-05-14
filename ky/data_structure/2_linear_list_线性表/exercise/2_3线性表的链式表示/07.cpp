#include <iostream>
#include "../../22_list_单链表/221_list_单链表.h"
using namespace std;
using LNode=LinkList<int>::LNode;

/*
    功能:删除递增单链表中的重复元素
    输入:
        LinkList<int>& L
    输出:
        int: 删除元素个数
    分析思路:
        递增序列的特点是重复元素相邻，找到第一个不重复的元素，将指针指过去
    实现细节:
        定义 LNode* pre 表示第一个不重复的元素
            当遇到 pre 与 cur 的数据域不同时，修改该值的 next 域
            当遇到 pre 与 cur 的数据域相同时，不动
        定义 LNode* cur 遍历单链表
        定义 int cnt 表示被删除的个数
    注意点:
        尾结点的处理
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

int UniqueLinearTable(LinkList<int>& L)
{
    //1. 判空
    if(L.Empty())
    {
        cout << "表空" << endl;
        return 0;
    }

    //2. 表非空，所以至少有一个结点，pre 为第一个结点
    LNode* pre = L.GetHeadNode()->next;
    LNode* cur = pre->next;
    int cnt = 0;
    while(cur != nullptr)
    {
        //遇到重复元素，将 pre->next 指向 cur->next，并将 cur 释放掉
        if(pre->data == cur->data)
        {
            LNode* tmp = cur;
            cur = cur->next;
            free(tmp);
            pre->next = cur;
            cnt++;
        }
        //遇到不重复元素，更新 pre 和 cur
        else
        {
            pre->next = cur;
            pre = cur;
            cur = cur->next;
        }
    }
    return cnt;
}

int main()
{
    LinkList<int> LC;
    LC.InitList();

    LC.ListInsert(1, 1);
    LC.ListInsert(2, 1);
    LC.ListInsert(3, 3);
    LC.ListInsert(4, 3);
    LC.ListInsert(5, 5);
    LC.ListInsert(6, 6);
    LC.PrintList();
    cout << "删除" << UniqueLinearTable(LC) << "个重复元素" << endl;
    LC.PrintList();
    return 0;
}