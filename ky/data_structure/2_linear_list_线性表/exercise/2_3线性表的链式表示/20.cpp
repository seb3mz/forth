#include <iostream>
#include "../../22_list_单链表/221_list_单链表.h"
using namespace std;
using LNode = LinkList<int>::LNode;

/*
    功能: 重排带头结点线性表 L=(a1,a2,a3,...,an-1,an) 得到 (a1,an,a2,an-1,....)
    输入:
        LinkList<int>& L:
    输出:
        bool:是否成功
    分析思路:
        第一次遍历得到链表长度 length 和尾指针 L_end
        第二次遍历将 length/2 后的链表逆置，并记录下逆置后的头指针
        第三次遍历将两表交叉排列
    实现细节:
        定义 LNode* L_end 表示尾指针
        定义 length 表示
        
    注意点:
        
    时间复杂度:
            
    空间复杂度:
            
*/

void ReArrangement(LinkList<int>& L)
{
    //1. 判空
    if(L.Empty())
    {
        cout << "表空" << endl;
        return;
    }

    //2. 第一次遍历得到尾指针和表长
    int length = 0;
    LNode* L_end = L.GetHeadNode();
    LNode* L_end_null = L_end->next;
    while(L_end_null)
    {
        length++;
        L_end = L_end_null;
        L_end_null = L_end_null->next;
    }

    //3. 第二次遍历将后半张链表逆置
    /*
        若表长为 10,则从第 6 个元素开始逆置
        若表长为 11,则从第 7 个元素开始逆置
    */
    int middle = ((length%2)?(length/2+2):(length/2+1));
    cout << "middle:" << middle << endl;
    int cnt = 1;
    LNode* L_pre = L.GetHeadNode();
    LNode* L_cur = L_pre->next;
    while(cnt < middle)
    {
        L_pre = L_cur;
        L_cur = L_cur->next;
        cnt++;
    }
    
    while(cnt <= length)
    {
        if(cnt == middle)
        {
            L_pre->next = nullptr;
            L_pre = L_cur;
            L_cur = L_cur->next;
            cnt++;
            continue;
        }
        else
        {
            LNode* L_nxt = L_cur->next;
            L_cur->next = L_pre;
            L_pre = L_cur;
            L_cur = L_nxt;
            cnt++; 
        }
    }
    
    //4. 第三次遍历，将两张表合并
    LNode* L_start = L.GetHeadNode()->next;
    cnt = 0;
    while(cnt < middle-1)
    {
        LNode* L1 = L_start->next;
        LNode* L2 = L_end->next;
        L_start->next = L_end;
        L_end->next = L1;
        L_start = L1;
        L_end = L2;
        cnt++;
    }
    cout << "成功" << endl;

    return;
}

int main()
{
    LinkList<int> L;
    L.InitList();
    L.ListInsert(1, 1);
    L.ListInsert(2, 2);
    L.ListInsert(3, 3);
    L.ListInsert(4, 4);
    L.ListInsert(5, 5);
    L.ListInsert(6, 11);
    L.ListInsert(7, 22);
    L.ListInsert(8, 33);
    L.ListInsert(9, 44);
    L.ListInsert(10, 55);

    L.PrintList();

    ReArrangement(L);
    
    L.PrintList();

    return 0;
}