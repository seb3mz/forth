#include <iostream>
#include "../../22_list_单链表/221_list_单链表.h"
using namespace std;
using LNode=LinkList<int>::LNode;

/*
    功能:递增链表 A 和 B，求 A 和 B 的交集(值域相等)，并存放于链表中，并将其他结点都释放掉
    输入:
        LinkList<int>& LA
        LinkList<int>& LB
    输出:
        int:有几个交集元素
    分析思路:
        根据递增特性，遍历 A、B，相等的保留，不相等的全部释放
    实现细节:
        定义 LNode* cur_A 用来遍历单链表 A
        定义 LNode* cur_B 用来遍历单链表 B
        定义 LNode* IntersectionElement 指向相同元素
            
    注意点:
        
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

int FindInterSectionElement(LinkList<int>& LA, LinkList<int>& LB)
{    
    //1. 判空
    if(LA.Empty() || LB.Empty())
    {
        cout << "表空" << endl;
        return 0;
    }

    //2. 遍历查找
    int cnt = 0;
    LNode* cur_A = LA.GetHeadNode();
    LNode* tmp_A = nullptr;
    LNode* cur_B = LB.GetHeadNode();
    LNode* tmp_B = nullptr;
    LNode* IntersectionElement = nullptr;
    while(cur_A && cur_B)
    {
        if(cur_A == LA.GetHeadNode() && cur_B == LB.GetHeadNode())
        {
            IntersectionElement = cur_A;
            cur_A = cur_A->next;
            tmp_B = cur_B;
            cur_B = cur_B->next;
            free(tmp_B);
        }
        //如果找到交集元素，则留下 A结点，删除 B 结点
        if(cur_A->data == cur_B->data)
        {
            cnt++;
            IntersectionElement->next = cur_A;
            IntersectionElement = cur_A;
            cur_A = cur_A->next;
            tmp_B = cur_B;
            cur_B = cur_B->next;
            free(tmp_B);
        }
        //如果 B 结点较小，则删除 B 结点
        else if(cur_A->data > cur_B->data)
        {
            tmp_B = cur_B;
            cur_B = cur_B->next;
            free(tmp_B);
        }
        else
        {
            tmp_A = cur_A;
            cur_A = cur_A->next;
            free(tmp_A);
        }
    }

    //3. 剩余的元素都不是交集，全部释放
    while(cur_A)
    {
        tmp_A = cur_A;
        cur_A = cur_A->next;
        free(tmp_A);
    }
    while(cur_B)
    {
        tmp_B = cur_B;
        cur_B = cur_B->next;
        free(tmp_B);
    }
    IntersectionElement->next = nullptr;
    return cnt;
}

int main()
{
    LinkList<int> LA, LB;
    LA.InitList();
    LB.InitList();

    LA.ListInsert(1, 1);
    LA.ListInsert(2, 11);
    LA.ListInsert(3, 32);
    LA.ListInsert(4, 38);
    
    LB.ListInsert(1, 11);
    LB.ListInsert(2, 21);
    LB.ListInsert(3, 32);

    LA.PrintList();
    LB.PrintList();

    cout << FindInterSectionElement(LA, LB) << endl;

    LA.PrintList();
    //有 coredump 
    LB.PrintList();
    
    return 0;
}