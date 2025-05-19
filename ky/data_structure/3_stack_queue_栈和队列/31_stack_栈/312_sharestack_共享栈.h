#ifndef SHARED_STACK
#define SHARED_STACK
#define MaxSize 10

template<typename T>
class ShStack
{
public:
    //初始化栈
    bool InitStack();
    //判断栈空
    bool StackEmpty() const;
    //S1入栈
    bool S1_Push(T v);
    //S2入栈
    bool S2_Push(T v);
    //S1出栈
    bool S1_Pop(T& v);
    //S2出栈
    bool S2_Pop(T& v);
    //获取S1栈顶元素
    bool GetTop1(T& v) const;
    //获取S2栈顶元素
    bool GetTop2(T& v) const;
private:
    T data[MaxSize];
    int top0;   //0号栈顶指针
    int top1;   //1号栈顶指针
};

//初始化栈
template<typename T>
bool ShStack<T>::InitStack()
{
    top0 = -1;
    top1 = MaxSize;
    return true;
}

//判断栈空
template<typename T>
bool ShStack<T>::StackEmpty() const
{
    return (top0 == -1 && top1 == MaxSize);
}

//入栈
template<typename T>
bool ShStack<T>::S1_Push(T v)
{
    if(top1 - top0 == 1)
    {
        //cout << "栈已满" << endl;
        return false;
    };
    //cout << "入栈成功" << endl;
    data[++top0] = e;
    return true;
}

//入栈
template<typename T>
bool ShStack<T>::S2_Push(T v)
{
    if(top1 - top0 == 1)
    {
        //cout << "栈已满" << endl;
        return false;
    };
    //cout << "入栈成功" << endl;
    data[--top1] = e;
    return true;
}

//出栈
template<typename T>
bool ShStack<T>::S1_Pop(T& v)
{
    if(top0 == -1)
    {
        //cout << "栈已空" << endl;
        return false;
    }
    e = data[top--];
    //cout << "出栈成功" << endl;
    return true;
}

//出栈
template<typename T>
bool ShStack<T>::S2_Pop(T& v)
{
    if(top1 == MaxSize)
    {
        //cout << "栈已空" << endl;
        return false;
    }
    e = data[top1++];
    //cout << "出栈成功" << endl;
    return true;
}

//获取栈顶元素
template<typename T>
bool ShStack<T>::GetTop1(T& v) const
{
    if(top0 == -1)
    {
        //cout << "栈已空" << endl;
        return false;
    }
    e = data[top0];
    return true;
}

template<typename T>
bool ShStack<T>::GetTop2(T& v) const
{
    if(top0 == MaxSize)
    {
        //cout << "栈已空" << endl;
        return false;
    }
    e = data[top1];
    return true;
}

#endif