#include <iostream>
#include "../../22_list_单链表/221_list_单链表.h"
using namespace std;
using LNode=LinkList<int>::LNode;

/*
    功能:查找单链表 A 和 B 的公共元素，构建新的链表 C
    输入:
        LinkList<int>& LA
        LinkList<int>& LB
        LinkList<int>& LC
    输出:
        bool:是否找到
    分析思路:
        A、B是递增序列，如果有公共元素，则
                        a. 公共元素后面的所有元素都是公共元素
    实现细节:
        定义 LNode* cur_A 用来遍历单链表 A
        定义 LNode* cur_B 用来遍历单链表 B
            找到第一个 cur_A == cur_B 的元素即是要找的结点
    注意点:
        
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

bool FindCommonNode(LinkList<int>& LA, LinkList<int>& LB, LinkList<int>& LC)
{    
    //1. 判空
    if(LA.Empty() || LB.Empty())
    {
        cout << "表空" << endl;
        return false;
    }

    //2. 遍历查找
    bool res = false;
    LNode* cur_A = LA.GetHeadNode();
    LNode* cur_B = LB.GetHeadNode();
    while(cur_A && cur_B)
    {
        if(cur_A == cur_B)
        {
            LC.GetHeadNode()->next = cur_A;
            res = true;
            break;
        }
        if(cur_A->data > cur_B->data)
        {
            cur_B = cur_B->next;
        }
        else
        {
            cur_A = cur_A->next;
        }
    }

    return res;
}

int main()
{
    LinkList<int> LA, LB, LC;
    LA.InitList();
    LB.InitList();
    LC.InitList();

    LA.ListInsert(1, 1);
    LA.ListInsert(2, 1);
    LA.ListInsert(3, 3);
    LA.ListInsert(4, 3);
    LNode* LA_tail = LA.GetElem(4);
    
    LB.ListInsert(1, 11);
    LB.ListInsert(2, 21);
    LB.ListInsert(3, 31);
    LNode* LB_tail = LB.GetElem(3);

    LNode* common1 = (LNode*)malloc(sizeof(LNode));
    common1->data = 30303;
    common1->next = nullptr;

    LNode* common2 = (LNode*)malloc(sizeof(LNode));
    common2->data = 20202;
    common2->next = common1;

    LNode* common3 = (LNode*)malloc(sizeof(LNode));
    common3->data = 10101;
    common3->next = common2;

    LA_tail->next = common3;
    LB_tail->next = common3;

    cout << (FindCommonNode(LA, LB, LC)?"成功":"失败") << endl;
    
    LA.PrintList();
    LB.PrintList();
    LC.PrintList();
    return 0;
}