#include <iostream>
#include "../../22_list_单链表/221_list_单链表.h"
using namespace std;
using LNode=LinkList<int>::LNode;

/*
    功能:将带头结点的单链表逆置
    输入:
        LinkList<int>& L:待操作的单链表
    输出:
        bool:操作是否成功
    分析思路:
        就地逆置单链表(空间复杂度O(1))，将所有结点的指针域反向
    实现细节:
        定义 LNode* head 保存链表头结点
        定义 LNode* pre, LNode* cur, LNode* nxt 分别代表前驱结点、当前结点、后继结点
        将 cur 的 next 域从指向 nxt 改为指向 pre
    注意点:
        a. 单链表为空的情况
        b. 单链表只有 1 个结点的情况
        c. 头结点的 next 需要指向尾结点
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

bool ReverseList(LinkList<int>& L)
{
    //链表判空
    if(L.Empty())
    {
        cout << "表空" << endl;
        return false;
    }
    LNode* head = L.GetHeadNode();
    LNode* pre = head;
    LNode* cur = head->next;
    LNode* nxt = nullptr;

    while(cur != nullptr)
    {
        //修改当前结点指针域，使其指向前驱结点 pre
        nxt = cur->next;
        if(pre == head)
        {   
            cur->next = nullptr;
        }
        else
        {
            cur->next = pre;   
        }
        pre = cur;
        cur = nxt;
    }
    //将头指针指向尾结点
    head->next = pre;
    return true;
}

int main()
{
    // // 保存原来的缓冲区
    // std::streambuf* original_buf = std::cout.rdbuf();

    // // 关闭输出：将缓冲区设为 nullptr
    // std::cout.rdbuf(nullptr);
    LinkList<int> L;
    L.InitList();
    L.ListInsert(1, 1);
    // L.ListInsert(2, 2);
    // L.ListInsert(3, 3);
    // L.ListInsert(4, 4);
    // L.ListInsert(5, 3);
    L.PrintList();
    cout << "逆置后:" << endl;
    ReverseList(L);
    L.PrintList();
    
    // std::cout.rdbuf(original_buf);
    // std::cout << "正常输出" << std::endl; // 恢复输出
    return 0;
}