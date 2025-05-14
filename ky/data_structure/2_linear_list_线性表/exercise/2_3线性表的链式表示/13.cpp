#include <iostream>
#include "../../23_dlist_双链表/dlist_双链表.h"
using namespace std;
using DNode = DLinkList<int>::DNode;

/*
    功能:   1.查找值为 x 的结点并返回地址
            2.将被访问的结点的 freq 加 1
            3.按照 freq 递减顺序排序
            4.如果 freq 相同，则最新访问的放在前面
    输入:
        DLinkList<int> DL:
        int x:
    输出:
        DNode*: 值为 x 所在结点的地址
    分析思路:
        1. 查找值为 x 的结点并返回地址，可以直接遍历并比对即可
        2. 由于是双链表，可以找到其前驱结点，因此可以比对相邻结点的 freq 值并修改
    实现细节:
        定义 LNode* cur_h1_pre、cur_h1 找到 h1 的尾结点
        定义 LNode* cur_h2_pre、cur_h2 找到 h2 的尾结点
            
    注意点:
        
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

DNode* Locate(DLinkList<int> DL, int x)
{
    //1.判空
    if(DL.Empty())
    {
        cout << "表空" << endl;
        return nullptr;
    }
    
    //2.查找 x 并更新链表
    DNode* headNode = DL.GetHeadNode();
    DNode* resultNode = headNode->next;
    while(resultNode && resultNode->data != x)
    {
        resultNode = resultNode->next;
    }

    if(resultNode == nullptr)
    {
        cout << "未查到值为 " << x << " 的结点" << endl;
    }
    else
    {
        //查找到
        //1.更新 freq
        resultNode->freq++;
        //2.根据 freq 更新链表
        DNode* FirstBigNode = resultNode;
        while(FirstBigNode != headNode && FirstBigNode->freq <= resultNode->freq)
        {
            FirstBigNode = FirstBigNode->pre;
        }

        /*
            将  resultNode 前驱结点的 next 修改为 resultNode->next
                resultNode 后继结点的 pre  修改为 resultNode->pre
                resultNode 的 pre 修改为 FirstBigNode, next 修改为 FirstBigNode->next 
                FirstBigNode 的 next 更改 resultNode

                resultNode->pre->next = resultNode->next;
                resultNode->next->pre = resultNode->pre;
                resultNode->pre = FirstBigNode;
                resultNode->next = FirstBigNode->next;
                FirstBigNode->next = resultNode;
        */

        resultNode->pre->next = resultNode->next;
        if(resultNode->next != nullptr)
        {
            resultNode->next->pre = resultNode->pre;
        }
        resultNode->pre = FirstBigNode;
        resultNode->next = FirstBigNode->next;
        FirstBigNode->next = resultNode;   
    }

    return resultNode;
}

int main()
{
    DLinkList<int> D1;
    D1.InitList();
    D1.ListInsert(1, 1);
    D1.ListInsert(2, 2);
    D1.ListInsert(3, 3);
    D1.ListInsert(4, 4);
    D1.ListInsert(5, 5);
    
    D1.PrintList();

    cout << (Locate(D1, 2)?"查找成功":"查找失败") << endl;
    cout << (Locate(D1, 2)?"查找成功":"查找失败") << endl;
    cout << (Locate(D1, 5)?"查找成功":"查找失败") << endl;
    cout << (Locate(D1, 5)?"查找成功":"查找失败") << endl;

    D1.PrintList();
    return 0;
}