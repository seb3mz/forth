#include <iostream>
#include "311_seqstack_顺序栈.h"
using namespace std;

int main()
{
    SeqStack<int> sq;
    sq.InitStack();
    sq.Push(1);
    sq.Push(2);
    sq.Push(3);
    sq.Push(4);
    sq.Push(5);
    sq.Push(6);
    return 0;
}