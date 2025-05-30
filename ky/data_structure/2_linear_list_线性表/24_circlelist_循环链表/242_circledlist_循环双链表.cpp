#include <iostream>
using namespace std;

typedef struct DNode
{
    int data;
    DNode *prior, *next;
}DNode, *DLinkList;

//初始化链表
bool InitList(DLinkList &L)
{
    L = (DNode*)malloc(sizeof(DNode*));
    if(L == nullptr)
    {
        cout << "分配结点失败" << endl;
        return false;
    }

    L->prior = L;
    L->next = L;
    cout << "初始化链表成功" << endl;
    return true;
}

//判断空表
bool Empty(const DLinkList& L)
{
    return (L->next == L)?true:false;
}


int main()
{
    DLinkList L;
    InitList(L);
    return 0;
}