#include <iostream>
#include "../../24_circlelist_循环链表/241_circlelist_循环单链表.h"
using namespace std;
using LNode=LinkList<int>::LNode;

/*
    功能:将循环单链表 h2 链接到循环单链表 h1 之后
    输入:
        LinkList<int>& h1:
        LinkList<int>& h2:
    输出:
        bool:
    分析思路:
        将 h1 的尾结点的 next 指向 h2 的第一个数据结点，将 h2 的尾结点的 next 指向 h1 的头结点
    实现细节:
        定义 LNode* cur_h1_pre、cur_h1 找到 h1 的尾结点
        定义 LNode* cur_h2_pre、cur_h2 找到 h2 的尾结点
            
    注意点:
        
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

bool LinkCircleList(LinkList<int>& h1, LinkList<int>& h2)
{
    //1. 判空
    if(h1.Empty() || h2.Empty())
    {
        cout << "表空" << endl;
        return false;
    }

    //2. 找 h1 的尾结点
    LNode* cur_h1_pre = h1.GetHeadNode();
    LNode* cur_h1 = cur_h1_pre->next;
    LNode* h1_head = h1.GetHeadNode();
    while(cur_h1 != h1_head)
    {
        //最后循环停止时，cur_h1 指向头结点，cur_h1_pre 指向尾结点
        cur_h1_pre = cur_h1;
        cur_h1 = cur_h1->next;
    }

    LNode* cur_h2_pre = h2.GetHeadNode();
    LNode* cur_h2 = cur_h2_pre->next;
    LNode* h2_head = h2.GetHeadNode();
    while(cur_h2 != h2_head)
    {
        cur_h2_pre = cur_h2;
        cur_h2 = cur_h2->next;
    }

    cur_h1_pre->next = h2_head->next;
    cur_h2_pre->next = cur_h1;
    free(h2_head);
    return true;
}

int main()
{
    LinkList<int> L1, L2;
    L1.InitList();
    L2.InitList();
    L1.ListInsert(1, 1);
    L1.ListInsert(2, 2);
    L1.ListInsert(3, 3);
    L1.ListInsert(4, 4);
    L1.PrintList();
    
    L2.ListInsert(1, 5);
    L2.ListInsert(2, 6);
    L2.ListInsert(3, 7);
    L2.ListInsert(4, 8);
    L2.PrintList();
    
    LinkCircleList(L1, L2);
    L1.PrintList();
    return 0;
}