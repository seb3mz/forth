#include "322_linkqueue_链队.h"
#include <iostream>
using namespace std;

//初始化队列
bool InitQueue(LinkQueue& Q)
{
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    if(Q.front == nullptr)
    {
        cout << "分配结点失败，初始化链队失败" << endl;
        return false;
    }
    Q.front->next = nullptr;
    cout << "初始化队列成功" << endl;
    return true;
}

//销毁队列
void DestroyQueue(LinkQueue& Q)
{
    while(Q.front != Q.rear)
    {
        LinkNode* tmp = Q.front->next;
        free(Q.front);
        Q.front = tmp;
    }
    free(Q.front);
    Q.front = Q.rear = nullptr;
}

//入队
bool EnQueue(LinkQueue& Q, int e)
{
    LinkNode *node = (LinkNode *)malloc(sizeof(LinkNode));
    if(node == nullptr)
    {
        cout << "创建结点失败，入队 " << e <<" 失败" << endl;
        return false;
    }
    node->data = e;
    Q.rear->next = node;
    node->next = nullptr;
    Q.rear = node;
    cout << "入队 " << e <<" 成功" << endl;
    return true;
}

//出队
bool DeQueue(LinkQueue& Q, int &e)
{
    if(Q.front == Q.rear)
    {
        cout << "队列空，出队失败" << endl;
        return false;
    }

    LinkNode* first_node = Q.front->next;
    e = first_node->data;
    free(Q.front);
    Q.front = first_node;
    cout << "出队 " << e <<" 成功" << endl;
    return true;
}

//获取队首元素
bool GetHead(const LinkQueue& Q, int &e)
{
    if(Q.front == Q.rear)
    {
        cout << "队列空" << endl;
        return false;
    }
    e = Q.front->next->data;
    return true;
}

//判断队空
bool QueueEmpty(const LinkQueue& Q)
{
    return Q.front==Q.rear?true:false;
}

int main()
{
    //测试队列操作
    LinkQueue lq;
    InitQueue(lq);
    EnQueue(lq, 1);
    EnQueue(lq, 2);
    EnQueue(lq, 3);
    EnQueue(lq, 4);
    EnQueue(lq, 5);
    cout << endl;
    
    int ret = -1;
    DeQueue(lq, ret);
    DeQueue(lq, ret);
    DeQueue(lq, ret);
    DeQueue(lq, ret);
    DeQueue(lq, ret);
    DeQueue(lq, ret);

    GetHead(lq, ret);

    DestroyQueue(lq);
    return 0;
}