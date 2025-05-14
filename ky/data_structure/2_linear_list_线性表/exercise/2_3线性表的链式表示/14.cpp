#include <iostream>
#include "../../22_list_单链表/222_list_不带头结点.h"
using namespace std;
using LNode = LinkList<int>::LNode;

/*
    功能: 将不带头结点的单链表中 n 个整数循环右移 k 个位置
    输入:
        LinkList<int>& DL:
        int k:
    输出:
        bool:
    分析思路:
        往右边移动 k 个位置，就要把
                尾结点的 next 域置为 firstNode
                倒数第 k 个元素设置为 firstNode
                倒数第 k+1 个元素的 next 域置为 nullptr,
    实现细节:
            
    注意点:
        
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

bool RotateRight(LinkList<int>& DL, int k)
{
    //1.判空
    if(DL.Empty())
    {
        cout << "表空" << endl;
        return false;
    }

    int DL_Length = DL.Length();
    if(k <= 0 || k >= DL_Length)
    {
        cout << "移位次数不合法" << endl;
        return false;
    }

    int pos = 1;
    LNode*& firstNode = DL.GetFirstNode();
    LNode* dNode = firstNode;
    
    while(pos < DL_Length-k)
    {
        dNode = dNode->next;
        pos++;
    }

    LNode* dNode_end = dNode;
    while(pos < DL_Length)
    {
        dNode_end = dNode_end->next;
        pos++;
    }
    
    //尾结点
    dNode_end->next = firstNode;
    //首结点
    firstNode = dNode->next;
    //新的尾结点
    dNode->next = nullptr;
    
    return true;
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

    RotateRight(L, 4);

    L.PrintList();
    return 0;
}