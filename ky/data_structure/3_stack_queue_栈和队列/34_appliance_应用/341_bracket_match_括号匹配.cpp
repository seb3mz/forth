#include <iostream>
#include "../31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

/*
    功能:检查字符串中括号是否匹配
    输入:
        const string s: 待验证的字符串
    输出:
        bool: 表示是否匹配成功
    分析思路:
        从头遍历字符串，运用栈的后进先出(LIFO)特性，对括号进行匹配 
    实现细节:
        从头遍历字符串，对不同字符串分别处理
            a. 遇到普通字符串，直接跳过
            b. 遇到 '(' '[' '{'，这三种字符串直接压入栈
            c. 遇到 ')' ']' '}', 将栈顶元素弹出，进行匹配
                                    若匹配成功，则继续遍历
                                    若匹配失败，则返回
        直到遇到 '\0' 表示结束，此时查看栈内是否为空，
                                若为空，则匹配成功
                                若不空，则匹配失败
    注意点:
    时间复杂度:
        O(n)
    空间复杂度
*/

bool BracketMatch(const string str)
{
    //栈
    SeqStack<char> sq;
    //栈顶元素
    char top = '\0';
    //匹配结果
    bool result = true;
    sq.InitStack();
    for(auto c : str)
    {
        switch(c)
        {
            case '(':
            case '{':
            case '[':
                sq.Push(c);
                break;
            case ')':
                if(!sq.Pop(top) || top != '(')
                {
                    result = false;
                }
                break;
            case '}':
                if(!sq.Pop(top) || top != '{')
                {
                    result = false;
                }
                break;
            case ']':
                if(!sq.Pop(top) || top != '[')
                {
                    result = false;
                }
                break;
            default:
                break;
        }
        if(!result)
            break;
    }
    //匹配完成后栈内还有元素:左右括号单身
    if(!result || !sq.StackEmpty())
    {
        result = false;
    }
    return result;
}

int main()
{
    string s1 = "{ccse{sxxd[ddea(a,bcdes(xdad)edfc)sad]}}";
    string s2 = "{([";
    cout << "匹配是否成功:" << (BracketMatch(s2)?"是":"否") << endl;
}