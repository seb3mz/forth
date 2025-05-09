#include <iostream>
#include "241_circlelist_循环单链表.h"
using namespace std;

//初始化链表
bool InitList(LinkList &L)
{
    cout << "InitList:初始化循环单链表" << endl;
    
    L = (LNode*)malloc(sizeof(LNode));
    if(L == nullptr)
    {
        cout << "创建结点失败" << endl;
        return false;
    }
    L->next = L;
    return true;
}

//判断空表
bool Empty(const LinkList& L)
{
    if(L == nullptr)
    {
        cout << "未构造的循环单链表" << endl;
    }
    
    return (L->next == L)?true:false;
}

int main()
{
    // 测试链表初始化操作
    cout << "*******************测试链表初始化操作*****************" << endl;
    LinkList L;
    InitList(L);
    return 0;
}