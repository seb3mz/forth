#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:利用空栈将队列中元素逆置
    输入:
        
    输出:
        bool:是否对称
    分析思路:
       
    实现细节:
        
    注意点:
    时间复杂度:
            
    空间复杂度:
            O(1)
*/

bool ReverQueue(SqQueue<int>& Q)
{
    SeqStack<int> S;
    S.InitStack();

    int tmp_v;
    while(Q.DeQueue(tmp_v))
    {
        S.Push(tmp_v);
    }

    while(S.Pop(tmp_v))
    {
        cout << "tmp_v:" << tmp_v << endl;
        Q.EnQueue(tmp_v);
    }

    return true;
}

int main()
{
    
    SqQueue<int> Q;
    Q.InitQueue();
    Q.EnQueue(1);
    Q.EnQueue(2);
    Q.EnQueue(3);
    Q.EnQueue(4);
    Q.EnQueue(5);

    ReverQueue(Q);
    return 0;
}