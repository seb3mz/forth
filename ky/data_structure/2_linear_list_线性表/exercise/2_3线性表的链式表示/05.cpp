#include <iostream>
#include "../../22_list_单链表/221_list_单链表.h"
using namespace std;
using LNode=LinkList<int>::LNode;

/*
    功能:找出两个单链表公共结点
    输入:
        const LinkList<int>& L1:待操作的单链表
        const LinkList<int>& L2:待操作的单链表
    输出:
        LNode*:第一个相同的结点
    分析思路:
        如果两个链表有一个相同的结点，则该结点后面的所有结点都是一样的，所以只需要找到第一个相同的结点
        遍历到两个结点的尾指针，从两个尾结点逆向遍历，直到找到第一个不是共同的结点
    实现细节:
        
    注意点:
        
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

LNode* FindSameNode(LinkList<int>& L1, const LinkList<int>& L2)
{
   
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
    
    L.PrintList();
    
    // std::cout.rdbuf(original_buf);
    // std::cout << "正常输出" << std::endl; // 恢复输出
    return 0;
}