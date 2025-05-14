#include <iostream>
#include "../../22_list_单链表/221_list_单链表.h"
using namespace std;
using LNode=LinkList<int>::LNode;

/*
    功能:两个整数序列 A、B，判断 B 是否是 A 的连续子序列
    输入:
        LinkList<int>& LA
        LinkList<int>& LB
    输出:
        bool:
    分析思路:
        使用暴力匹配法，先找到第一个匹配的元素，然后依次匹配后面的元素，失配后从刚才位置后移一位继续匹配
    实现细节:
        定义 LNode* cur_A 用来遍历单链表 A
        定义 LNode* cur_B 用来遍历单链表 B
        定义 LNode* matchA 用来对比子序列
        定义 LNode* matchB 用来对比子序列
            
    注意点:
        
    时间复杂度:
            O(n*m)
    空间复杂度:
            O(1)
*/

bool MatchSequence(LinkList<int>& LA, LinkList<int>& LB)
{    
    //1. 判空
    if(LA.Empty() || LB.Empty())
    {
        cout << "表空" << endl;
        return false;
    }

    //2. 遍历查找
    LNode* cur_A = LA.GetHeadNode()->next;
    LNode* cur_B = LB.GetHeadNode()->next;
    bool result = false;

    while(cur_A && cur_B)
    {
        LNode* matchA = cur_A;
        LNode* matchB = cur_B;
        while(matchA && matchB && matchA->data == matchB->data)
        {
            matchA = matchA->next;
            matchB = matchB->next;
        }

        if(matchB == nullptr)
        {
            result = true;
            break;
        }
        else
        {
            cur_A = cur_A->next;
            cur_B = LB.GetHeadNode()->next;
        }
    }
    
    return result;
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
    LB.ListInsert(2, 32);
    LB.ListInsert(3, 38);

    LA.PrintList();
    LB.PrintList();

    cout << "匹配" << (MatchSequence(LA, LB)?"成功":"失败") << endl;
    return 0;
}