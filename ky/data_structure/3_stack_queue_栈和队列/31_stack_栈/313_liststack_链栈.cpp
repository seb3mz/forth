#include "313_liststack_链栈.h"
#include <iostream>
using namespace std;

//初始化栈
bool InitStack(LiStack& S)
{
    cout << "初始化栈" << endl;
    S = (Linknode*)malloc(sizeof(Linknode));
    if(S == nullptr)
    {
        cout << "创建结点失败" << endl;
        return false;
    }
    S->next = nullptr;
    cout << "栈初始化成功" << endl;
    return true;
}

//判断栈空
bool StackEmpty(const LiStack& S)
{
    if(S == nullptr)
    {
        cout << "栈未初始化" << endl;
        return false;
    }
    return (S->next==nullptr)?true:false;
}

//入栈
bool Push(LiStack& S, int e)
{
    if(S == nullptr)
    {
        cout << "栈未初始化" << endl;
        return false;
    }

    Linknode* node = (Linknode*)malloc(sizeof(Linknode));
    if(node == nullptr)
    {
        cout << "结点分配失败，入栈失败" << endl;
        return false;
    }
    node->data = e;

    node->next = S->next;
    S->next = node;
    cout << "入栈:" << e << "成功" << endl;
    return true;
}

//出栈
bool Pop(LiStack& S, int &e)
{
    if(S == nullptr)
    {
        cout << "栈未初始化" << endl;
        return false;
    }

    if(S->next == nullptr)
    {
        cout << "空栈，出栈失败" << endl;
        return false;
    }

    Linknode* tmp = S->next;
    S->next = tmp->next;
    e = tmp->data;
    free(tmp);
    cout << "出栈:" << e << "成功" << endl;
    return true;
}

//获取栈顶元素
bool GetTop(const LiStack &S, int &e)
{
    if(S == nullptr)
    {
        cout << "栈未初始化" << endl;
        return false;
    }

    if(S->next == nullptr)
    {
        cout << "空栈，获取栈顶元素失败" << endl;
        return false;
    }

    e = S->next->data;
    cout << "获取栈顶元素成功" << endl;
    return true;
}

int main()
{
    //测试栈操作
    LiStack L;
    InitStack(L);
    cout << "栈" << (StackEmpty(L)?"空":"非空") << endl;

    Push(L, 1);
    Push(L, 88);
    Push(L, 77);
    Push(L, 66);

    int ret = -1;
    Pop(L, ret);
    Pop(L, ret);
    Pop(L, ret);
    Pop(L, ret);
    Pop(L, ret);
    return 0;
}