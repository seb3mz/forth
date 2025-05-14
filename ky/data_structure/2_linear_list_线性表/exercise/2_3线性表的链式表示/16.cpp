#include <iostream>
#include "../../22_list_单链表/222_list_不带头结点.h"
using namespace std;
using LNode = LinkList<int>::LNode;

/*
    功能: 求不带头结点的单链表的最大孪生和
    输入:
        LinkList<int>& L:
    输出:
        int: 
    分析思路:
        要求第 i 和第 n-i 结点的和，需要遍历完所有结点
    实现细节:
        采用头插入法建立另一个链表，顺序刚好与 L 相反，并记录下链表长度
        将两个表对应元素相加
    注意点:
        
    时间复杂度:
            O(n)
    空间复杂度:
            O(n)
*/

int MaxTwinSum(LinkList<int>& L)
{
    if(L.Empty())
    {
        cout << "空表" << endl;
        return 0;
    }

    LinkList<int> L_bak;
    L_bak.InitList();
    LNode* cur_L = L.GetFirstNode()->next;
    int cnt = 0;
    while(cur_L)
    {
        L_bak.ListInsert(1, cur_L->data);
        cur_L = cur_L->next;
        cnt++;
    }

    int cnt_bak = 1;
    int biggest = 0;
    while(cnt_bak <= cnt/2)
    {
        if(L.GetElem(cnt_bak)->data + L_bak.GetElem(cnt_bak)->data > biggest)
        {
            biggest = L.GetElem(cnt_bak)->data + L_bak.GetElem(cnt_bak)->data;
        }
        cnt_bak++;
    }

    return biggest;
}

int main()
{
    LinkList<int> L;
    L.InitList();
    L.ListInsert(1, 10);
    L.ListInsert(1, 100);
    L.ListInsert(2, 11);
    L.ListInsert(3, 12);
    L.ListInsert(4, 13);
    L.ListInsert(5, 1000);
    L.PrintList();

    cout << "最大值是:" << MaxTwinSum(L) << endl;
    return 0;
}