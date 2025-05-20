#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:利用栈 S1 和 S2 模拟队列 Q
    输入:
        
    输出:
        
    分析思路:
       
    实现细节:
        
    注意点:
    时间复杂度:
            
    空间复杂度:
            O(1)
*/

typedef struct
{
    SeqStack<int> S1;
    SeqStack<int> S2;
}SqQueue;

void InitQueue(SqQueue& Q)
{
    Q.S1.InitStack();
    Q.S2.InitStack();
}

bool EnQueue(SqQueue& Q, int e)
{
    if(Q.S1.Push(e))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DeQueue(SqQueue& Q, int &e)
{
    int tmp_v;
    while(Q.S1.Pop(tmp_v))
    {
        Q.S2.Push(tmp_v);
    }
    Q.S2.Pop(e);
    while(Q.S2.Pop(tmp_v))
    {
        Q.S1.Push(tmp_v);
    }
}

bool QueueEmpty(SqQueue& Q)
{
    return Q.S1.StackEmpty();
}

int main()
{
    SeqStack<int> S1;
    SeqStack<int> S2;
    S1.InitStack();
    S2.InitStack();
    return 0;
}