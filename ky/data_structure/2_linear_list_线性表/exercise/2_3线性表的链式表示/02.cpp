#include <iostream>
#include "../../22_list_单链表/221_list_单链表.h"
using namespace std;
using LNode=LinkList<int>::LNode;

/*
    功能:删除带头结点的单链表中最小值
    输入:
        LinkList<int>& L:待操作的单链表
    输出:
        bool:操作是否成功
    分析思路:
       遍历顺序表，找到最小值结点的位置，删除
    实现细节:
        定义 LNode* cur、LNode* pre 用来遍历单链表
        定义 LNode* smallest、LNode* smallest_pre 用来记录最小值所在结点及前驱结点
        遍历单链表，并将最小值的结点赋值给 smallest，及其前驱结点赋值给 smallest_pre
    注意点:
        a. 单链表为空的情况
        b. 单链表只有 1 个结点的情况
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

bool DeleteSmallest(LinkList<int>& L)
{
    //链表判空
    if(L.Empty())
    {
        cout << "表空" << endl;
        return false;
    }
    LNode* pre = L.GetHeadNode();
    LNode* cur = pre->next;
    LNode* smallest_pre = pre;
    LNode* smallest = cur;

    while(cur != nullptr)
    {
        if(pre != L.GetHeadNode())
        {
            if(cur->data < smallest->data)
            {
                smallest_pre = pre;
                smallest = cur;
            }
        }
        pre = cur;
        cur = cur->next;
    }
    smallest_pre->next = smallest->next;
    free(smallest);
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

    cout << (DeleteSmallest(L)?"成功":"失败") << endl;
    L.PrintList();
    
    // std::cout.rdbuf(original_buf);
    // std::cout << "正常输出" << std::endl; // 恢复输出
    return 0;
}