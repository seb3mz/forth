#include <iostream>
using namespace std;

#define MaxSize 5

typedef struct {
    int data[MaxSize];  //用静态数组存放队列元素
    int front, rear;    //队头指针和队尾指针，front 指向队首结点，rear 指向队尾结点的后一个结点
    bool tag;
} SqQueue;

//初始化队列
void InitQueue(SqQueue& Q)
{
    Q.front = Q.rear = 0;
    Q.tag = 0;
}

//入队
bool EnQueue(SqQueue& Q, int e)
{
    if(Q.rear == Q.front && Q.tag == 1)
    {
        cout << "队列已满" << endl;
        return false;
    }

    Q.data[Q.rear] = e;
    Q.rear = (Q.rear+1)%MaxSize;
    Q.tag = 1;
    return true;
}

//出队
bool DeQueue(SqQueue& Q, int &e)
{
    if(Q.rear == Q.front && Q.tag == 0)
    {
        cout << "队列已空" << endl;
        return false;
    }

    e = Q.data[Q.front];
    Q.front = (Q.front+1)%MaxSize;
    Q.tag = 0;
    return true;
}

int main()
{
    SqQueue sq;
    InitQueue(sq);
    EnQueue(sq, 1);
    EnQueue(sq, 2);
    EnQueue(sq, 3);
    EnQueue(sq, 4);
    EnQueue(sq, 5);
    EnQueue(sq, 6);

    int tmp;
    DeQueue(sq, tmp);
    cout << tmp << endl;
    DeQueue(sq, tmp);
    cout << tmp << endl;
    DeQueue(sq, tmp);
    cout << tmp << endl;
    DeQueue(sq, tmp);
    cout << tmp << endl;
    DeQueue(sq, tmp);
    cout << tmp << endl;
    DeQueue(sq, tmp);
    cout << tmp << endl;
    return 0;
}