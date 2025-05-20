#ifndef SEQ_QUEUE_H
#define SEQ_QUEUE_H
#include <iostream>
using namespace std;
#define QMaxSize 5

template<typename T>
class SqQueue
{
public:
    //初始化队列
    void InitQueue();

    //销毁队列
    void DestroyQueue();

    //入队
    bool EnQueue(int e);

    //出队
    bool DeQueue(int &e);

    //获取队首元素
    bool GetHead(int &e)const;

    //判断队空
    bool QueueEmpty()const;

private:
    int data[QMaxSize];  //用静态数组存放队列元素
    int front, rear;    //队头指针和队尾指针
    int length;
};

template<typename T>
void SqQueue<T>::InitQueue()
{
    front = rear = 0;
    length = 0;
}

//销毁队列
template<typename T>
void SqQueue<T>::DestroyQueue()
{
    front = rear = -1;
    length = 0;
}

//入队
template<typename T>
bool SqQueue<T>::EnQueue(int e)
{
    if(length == QMaxSize)
    {
        cout << "队列已满，入队 " << e <<" 失败" << endl;
        return false;
    }
    data[(rear++)%QMaxSize] = e;
    length++;
    return true;
}

//出队
template<typename T>
bool SqQueue<T>::DeQueue(int &e)
{
    if(length == 0)
    {
        cout << "队列空，出队失败" << endl;
        return false;
    }
    e = data[(front++)%QMaxSize];
    length--;
    return true;
}

//获取队首元素
template<typename T>
bool SqQueue<T>::GetHead(int &e) const
{
    if(length == 0)
    {
        cout << "队列空" << endl;
        return false;
    }
    e = data[front];
    return true;
}

//判断队空
template<typename T>
bool SqQueue<T>::QueueEmpty() const
{
    return length==0?true:false;
}

#endif