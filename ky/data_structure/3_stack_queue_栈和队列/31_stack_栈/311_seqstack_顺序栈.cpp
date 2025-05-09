#include "311_seqstack_顺序栈.h"
#include <iostream>
using namespace std;

template<typename T>
bool SeqStack<T>::InitStack()
{
    top = -1;
    cout << "栈初始化成功" << endl;
    return true;
}

template<typename T>
bool SeqStack<T>::StackEmpty() const
{
    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<typename T>
bool SeqStack<T>::Push(T e)
{
    if(top == MaxSize-1)
    {
        cout << "栈已满" << endl;
        return false;
    };
    cout << "入栈成功" << endl;
    data[++top] = e;
    return true;
}

template<typename T>
bool SeqStack<T>::Pop(T &e)
{
    if(top == -1)
    {
        cout << "栈已空" << endl;
        return false;
    }
    e = data[top--];
    cout << "出栈成功" << endl;
    return true;
}

template<typename T>
bool SeqStack<T>::GetTop(T &e) const
{
    if(top == -1)
    {
        cout << "栈已空" << endl;
        return false;
    }
    e = data[top];
    return true;
}