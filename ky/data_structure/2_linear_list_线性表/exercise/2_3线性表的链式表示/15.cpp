#include <iostream>
#include "../../22_list_单链表/221_list_单链表.h"
using namespace std;
using LNode = LinkList<int>::LNode;

/*
    功能: 判断单链表是否有环
    输入:
        LinkList<int>& L:
    输出:
        bool: 
    分析思路:
        利用 LNode* fast 和 LNode* slow 指针，
        fast 每次移动两个距离
        slow 每次移动一个距离
        如果 fast 和 slow 相等说明有环
    实现细节:
            
    注意点:
        
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

bool IsLoop(LinkList<int>& DL)
{
    if(DL.Empty())
    {
        cout << "表空" << endl;
        return false;
    }

    bool result = false;
    LNode* slow = DL.GetHeadNode()->next;
    LNode* fast = slow->next;

    while(fast != nullptr && fast->next != nullptr)
    {
        if(fast == slow)
        {
            result = true;
            break;
        }
        else
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
    }

    return result;
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
    L.PrintList();

    LNode* cirNode = L.GetElem(3);

    LNode* endNode = L.GetElem(5);

    endNode->next = cirNode;

    cout << (IsLoop(L)?"有环":"无环") << endl;

    return 0;
}