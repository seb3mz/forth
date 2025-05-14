#include <iostream>
#include "../../24_circlelist_循环链表/242_circledlist_循环双链表.h"
using namespace std;
using DNode=DlinkList<int>::DNode;

/*
    功能:判断带头结点的循环双链表是否对称
    输入:
        DlinkList<int>& DL:待判断的循环双链表
    输出:
        bool:
    分析思路:
        根据循环双链表的性质，分别从正向和逆向遍历链表，逐个对比是否相等
    实现细节:
        定义 DNode* front = head->next 正向遍历
        定义 DNode* rear = head->prior 逆向遍历
        当 front==rear 或者 front->next=rear
            
    注意点:
        
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

bool IsSymmetrical(DlinkList<int>& DL)
{
    //1. 判空
    if(DL.Empty())
    {
        cout << "表空" << endl;
        return false;
    }

    //2.
    bool result = false;
    DNode* front = DL.GetHeadNode()->next;
    DNode* rear = DL.GetHeadNode()->prior;

    while(front->data == rear->data)
    {
        if(front == rear || front->next == rear)
        {
            result = true;
            break;
        }
        front = front->next;
        rear = rear->prior;
    }

    return result;
}

int main()
{
    DlinkList<int> DL;
    DL.InitList();
    DL.ListInsert(1, 1);
    DL.ListInsert(1, 11);
    DL.ListInsert(2, 11);
    // DL.ListInsert(1, 2);
    // DL.ListInsert(1, 3);
    // DL.ListInsert(1, 4);
    // DL.ListInsert(2, 8);
    // DL.ListInsert(6, 88);
    DL.PrintList();

    cout << (IsSymmetrical(DL)?"对称":"不对称") << endl;
    return 0;
}