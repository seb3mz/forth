#ifndef SEQSTACK_H
#define SEQSTACK_H

#include <iostream>
using namespace std;

#define MaxSize 100

template<typename T>
class SeqStack {
public:
    SeqStack():top(-1){}
    ~SeqStack(){}
    //初始化栈
    bool InitStack();
    //判断栈空
    bool StackEmpty() const;
    //入栈
    bool Push(T v);
    //出栈
    bool Pop(T& v);
    //获取栈顶元素
    bool GetTop(T& v) const;

private:
    T data[MaxSize];
    int top;    //栈顶指针，表示数组的下标
};

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
        //cout << "栈已满" << endl;
        return false;
    };
    //cout << "入栈成功" << endl;
    data[++top] = e;
    return true;
}

template<typename T>
bool SeqStack<T>::Pop(T &e)
{
    if(top == -1)
    {
        //cout << "栈已空" << endl;
        return false;
    }
    e = data[top--];
    //cout << "出栈成功" << endl;
    return true;
}

template<typename T>
bool SeqStack<T>::GetTop(T &e) const
{
    if(top == -1)
    {
        //cout << "栈已空" << endl;
        return false;
    }
    e = data[top];
    return true;
}

#endif //SEQSTACK_H