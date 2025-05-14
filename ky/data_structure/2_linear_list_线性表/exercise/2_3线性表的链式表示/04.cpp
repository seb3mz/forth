#include <iostream>
#include "../../22_list_单链表/221_list_单链表.h"
using namespace std;
using LNode=LinkList<int>::LNode;

/*
    功能:将带头结点的单链表逆置
    输入:
        LinkList<int>& L:待操作的单链表
        int min:范围下限
        int max:范围上限
    输出:
        int:删除的个数
    分析思路:
        遍历链表，对比范围，如果处于范围内，则删除
    实现细节:
        定义 LNode* pre, LNode* cur 负责遍历和修改指针域
    注意点:
        
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

int DeleteSpecRangeValue(LinkList<int>& L, int min, int max)
{
    //1. 链表判空
    if(L.Empty())
    {
        cout << "表空" << endl;
        return false;
    }

    //2. 遍历并修改
    LNode* pre = L.GetHeadNode();
    LNode* cur = pre->next;
    int cnt = 0;

    while(cur != nullptr)
    {
        if(cur->data >min && cur->data < max)
        {
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
            cnt++;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }

    return cnt;
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
    L.ListInsert(2, 2);
    L.ListInsert(3, 3);
    L.ListInsert(4, 4);
    L.ListInsert(5, 3);
    L.PrintList();
    cout << "删除" << DeleteSpecRangeValue(L, 5, 6) << "个元素" << endl;
    L.PrintList();
    
    // std::cout.rdbuf(original_buf);
    // std::cout << "正常输出" << std::endl; // 恢复输出
    return 0;
}