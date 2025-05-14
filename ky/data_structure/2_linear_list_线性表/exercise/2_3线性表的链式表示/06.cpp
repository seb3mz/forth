#include <iostream>
#include "../../22_list_单链表/221_list_单链表.h"
using namespace std;
using LNode=LinkList<int>::LNode;

/*
    功能:将线性表 C={a1,b1,a2,b2,...,an,bn} 拆分为两个线性表 A={a1,a2,...an} 和 B={b1,b2,...bn}
    输入:
        const LinkList<int>& LC:
        LinkList<int>& LA
        LinkList<int>& LB
    输出:
        bool: 
    分析思路:
        将位序为单号的结点采用尾插法插入 A
        将位序为单号的结点采用尾插法插入 B
    实现细节:
        定义 LNode* cur 遍历 LC 所有结点
        定义 LNode* pre_A 用来插入 LA 结点
        定义 LNode* pre_B 用来插入 LB 结点
        定义 pos 来区分是单数结点还是偶数结点
            当 pos 为奇数时，更新 pre_A 
            当 pos 为偶数时，更新 pre_B
    注意点:
        尾结点的处理
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

bool SplitLinearTable(LinkList<int>& LC, LinkList<int>& LA, LinkList<int>& LB)
{
    //1. 判空
    if(LC.Empty())
    {
        cout << "表空" << endl;
        return false;
    }

    //2.
    LNode* pre = LC.GetHeadNode();
    LNode* cur = pre->next;
    LNode* pre_A = LA.GetHeadNode();
    LNode* pre_B = LB.GetHeadNode();
    int pos = 1;
    
    while(cur != nullptr)
    {
        if(pos%2)
        {
            pre_A->next = cur;
            pre_A = cur;
        }
        else
        {
            pre_B->next = cur;
            pre_B = cur;
        }
        cur = cur->next;
        pos++;
    }
    //3. 尾巴结点
    pre->next = nullptr;
    pre_A->next = nullptr;
    pre_B->next = nullptr;
    return true;
}

int main()
{
    LinkList<int> LC, LA, LB;
    LC.InitList();
    LA.InitList();
    LB.InitList();
    LC.ListInsert(1, 1);
    LC.ListInsert(2, 2);
    LC.ListInsert(3, 3);
    LC.ListInsert(4, 4);
    LC.ListInsert(5, 5);
    LC.ListInsert(6, 6);
    LC.PrintList();
    SplitLinearTable(LC, LA, LB);

    LA.PrintList();
    LB.PrintList();
    return 0;
}