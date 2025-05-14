#include <iostream>
#include "../../22_list_单链表/221_list_单链表.h"
using namespace std;
using LNode = LinkList<int>::LNode;

/*
    功能: 查找带头结点的单链表倒数第 k 个位置结点
            若查找成功，输出 data 域值，并返回1
            若查找失败，返回 0
    输入:
        LinkList<int>& list:
    输出:
        int: 
    分析思路:
        1.先得到链表的长度
        2.用数组存储链表元素
        3.找到第 k 个位置的结点
    实现细节:
        定义 LNode* cur = list.GetFirstNode(); 遍历数组，得到链表长度 n
    注意点:
        
    时间复杂度:
            O(2n)
    空间复杂度:
            O(n)
*/

int GetReverseK(LinkList<int> L, int k)
{
    if(L.Empty())
    {
        cout << "表空" << endl;
        return 0;
    }
    if(k < 0)
    {
        cout << "位序有误" << endl;
        return 0;
    }
    LNode* cur = L.GetHeadNode()->next;
    int length = 0;
    while(cur)
    {
        length++;
        cur = cur->next;
    }

    cout << "length:" << length << endl;
    if(k > length)
    {
        cout << "超出表长范围" << endl;
        return 0;
    }

    int arr[length] = {0};
    cur = L.GetHeadNode()->next;
    length = 0;
    while(cur)
    {
        arr[length++] = cur->data;
        cur = cur->next;
    }
    cout << "倒数第 " << k << " 个值为" << arr[length-k] << endl;
    return 1;
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

    cout << GetReverseK(L, 6) << endl;
    return 0;
}