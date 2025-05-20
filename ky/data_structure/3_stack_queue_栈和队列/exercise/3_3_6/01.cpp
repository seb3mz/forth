#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    设计思想：
        使用栈来批评括号
    时间复杂度: O(n)
    空间复杂度: O(1)
*/

bool Fitter(char arr[])
{
    //定义顺序栈
    SeqStack<char> ss;
    //初始化
    ss.InitStack();
    int i = 0;
    char ss_top = '\0';
    bool result = true;
    while(arr[i] != '\0')
    {
        switch(arr[i])
        {
            case '(':
                ss.Push(arr[i]);
                break;
            case ')':
                if(ss.StackEmpty())
                {
                    result = false;
                    break;
                }
                ss.Pop(ss_top);
                if(ss_top != '(')
                {
                    result = false;
                }
                break;
            case '[':
                ss.Push(arr[i]);
                break;
            case ']':
                if(ss.StackEmpty())
                {
                    result = false;
                    break;
                }
                ss.Pop(ss_top);
                if(ss_top != '[')
                {
                    result = false;
                }
                break;
            case '{':
                ss.Push(arr[i]);
                break;
            case '}':
                if(ss.StackEmpty())
                {
                    result = false;
                    break;
                }
                ss.Pop(ss_top);
                if(ss_top != '{')
                {
                    result = false;
                }
                break;
            default:
                break;
        }
        if(result == false)
        {
            return false;
        }
        i++;
    }
    if(ss.StackEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char * crr = "([([][]{{}})])";

    cout << (Fitter(crr)?"匹配":"不匹配") << endl;
    return 0;
}