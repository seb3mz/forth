#include "321_seqqueue_顺序队列.h"
#include <iostream>
using namespace std;

typedef struct {
    int data[MaxSize];  //用静态数组存放队列元素
    int front, rear;    //队头指针和队尾指针
    int length;
} SqQueue;

//初始化队列
void InitQueue(SqQueue& Q)
{
    Q.front = Q.rear = 0;
    Q.length = 0;
    cout << "队列初始化成功" << endl;
}

//销毁队列
void DestroyQueue(SqQueue& Q)
{
    Q.front = Q.rear = -1;
    Q.length = 0;
    cout << "队列销毁成功" << endl;
}

//入队
bool EnQueue(SqQueue& Q, int e)
{
    if(Q.length == MaxSize)
    {
        cout << "队列已满，入队 " << e <<" 失败" << endl;
        return false;
    }
    Q.data[(Q.rear++)%MaxSize] = e;
    Q.length++;
    cout << "入队 " << e <<" 成功" << endl;
    return true;
}

//出队
bool DeQueue(SqQueue& Q, int &e)
{
    if(Q.length == 0)
    {
        cout << "队列空，出队失败" << endl;
        return false;
    }
    e = Q.data[(Q.front++)%MaxSize];
    Q.length--;
    cout << "出队 " << e <<" 成功" << endl;
    return true;
}

//获取队首元素
bool GetHead(const SqQueue& Q, int &e)
{
    if(Q.length == 0)
    {
        cout << "队列空" << endl;
        return false;
    }
    e = Q.data[Q.front];
    return true;
}

//判断队空
bool QueueEmpty(const SqQueue& Q)
{
    return Q.length==0?true:false;
}

// int main()
// {
//     //测试队列操作
//     SqQueue sq;
//     InitQueue(sq);

//     EnQueue(sq, 1);
//     EnQueue(sq, 2);
//     EnQueue(sq, 3);
//     EnQueue(sq, 4);
//     EnQueue(sq, 5);
//     EnQueue(sq, 6);

//     int ret = -1;
//     DeQueue(sq, ret);
//     DeQueue(sq, ret);
//     DeQueue(sq, ret);
//     DeQueue(sq, ret);
//     DeQueue(sq, ret);
//     DeQueue(sq, ret);
//     return 0;
// }