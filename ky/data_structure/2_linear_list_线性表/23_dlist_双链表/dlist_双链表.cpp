#include "dlist_双链表.h"
#include <iostream>
using namespace std;

//初始化双链表
bool InitDLinkList(DLinkList &L)
{
    cout << "InitDLinkList:初始化双链表" << endl;
    L = (DNode*)malloc(sizeof(DNode));
    if(L == nullptr)
    {
        cout << "分配结点失败，初始化双链表失败" << endl;
        return false;
    }
    L->prior = nullptr;
    L->next = nullptr;

    cout << "初始化双链表成功" << endl;
    return true;
}

//打印双链表
void PrintDList(const DLinkList &L)
{
    cout << "PrintDList:打印双链表" << endl;
    if(L == nullptr)
    {
        cout << "未初始化的双链表" << endl;
        return;
    }

    DNode* tmp = L->next;
    while(tmp)
    {
        cout << " " << tmp->data << endl;
        tmp = tmp->next;
    }
}

int Length(const DLinkList &L)
{
    cout << "Length:求链表长度" << endl;
    if(L == nullptr)
    {
        cout << "未初始化的双链表" << endl;
        return -1;
    }
    int length = 0;
    DNode* dn = L->next;
    while(dn)
    {
        length++;
        dn = dn->next;
    }
    return length;
}

/*
    功能: 在结点 p 后插入结点 s
    输入:   
        DNode* p: 指定结点
        DNode* s: 待插入结点
    输出:
        bool: 表示是否插入成功
    分析思路:
        根据双链表的存储结构，需要修改结点 p的 next 指针域、指针 p 后继结点rear的前驱指针域、 结点 s 的前驱和后继指针域
            rear = p->next;
            s->prior = p;
            s->next = rear;
            p->next = s;
            rear->prior = s;
    实现细节:
    注意点:
        a.输入校验
        b.当p是最后一个结点时，需要特殊处理
    时间复杂度:
        O(1)
    空间复杂度:
*/
//在结点 p 后插入结点 s
bool InsertNextDNode(DNode* p, DNode* s)
{
    cout << "InsertNextDNode:指定结点的后插操作" << endl;
    if(p == nullptr || s == nullptr)
    {
        cout << "结点无效" << endl;
        return false;
    }
    
    //修改指针域
    //待插入结点的 prior 和 next 指针域
    s->prior = p;
    s->next = p->next;
    if(p->next == nullptr)
    {
        p->next = s;
    }
    else
    {
        //p的原后继结点的 prior 指针域
        p->next->prior = s;
        //p的后继结点
        p->next = s;
    }
    cout << "插入成功" << endl;
    return true;
}

/*
    功能:删除 p 的后继结点
    输入:
        DNode* p: 待删除结点的前驱结点
    输出:
        bool: 表示是否操作成功
    分析思路:
        删除指定结点 p 的后继结点rear, 需要修改 p 的后继指针域、rear 的后继结点的前驱指针域
    实现细节:
    注意点:
        当 p 是最后一个结点时，无法删除其后面的结点
        当 p 是倒数第二个结点时，将删除最后一个结点，此时需要特殊处理
    时间复杂度:
    空间复杂度:
*/
//
bool DeleteNextNode(DNode* p)
{
    cout << "DeleteNextNode:删除指定结点的后继结点" << endl;
    //
    if(p == nullptr || p->next == nullptr)
    {
        cout << "指定结点非法" << endl;
        return false;
    }
    DNode* rear = p->next;
    if(rear->next != nullptr)
    {
        rear->next->prior = p;
    }
    p->next = rear->next;
    free(rear);
    cout << "删除指定结点的后继结点成功" << endl;
    return true;
}

//销毁双链表
void DestoryList(DLinkList& L)
{
    cout << "DestoryList:销毁双链表" << endl;
    DNode* tmp = L;
    DNode* next;
    while(tmp)
    {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    L = nullptr;
    cout << "成功销毁双链表" << endl;
}

int main()
{
    // 测试初始化双链表操作
    cout << "*******************测试初始化双链表操作*****************" << endl;
    DLinkList L;
    InitDLinkList(L);

    // 测试初始化双链表在指定结点的后插操作
    cout << "*******************测试初始化双链表在指定结点的后插操作*****************" << endl;
    DNode* s = (DNode*)malloc(sizeof(DNode));
    if(s == nullptr)
    {
        cout << "结点分配失败" << endl;
        return -1;
    }
    s->data = 101;
    InsertNextDNode(L, s);
    cout << Length(L) << endl;
    PrintDList(L);

    // 测试初始化双链表删除指定结点的后继结点
    cout << "*******************测试初始化双链表删除指定结点的后继结点*****************" << endl;
    // DeleteNextNode(L);
    // cout << Length(L) << endl;
    // PrintDList(L);

    // 测试销毁双链表
    cout << "*******************测试销毁双链表*****************" << endl;
    DestoryList(L);
    cout << Length(L) << endl;
    PrintDList(L);
    return 0;
}