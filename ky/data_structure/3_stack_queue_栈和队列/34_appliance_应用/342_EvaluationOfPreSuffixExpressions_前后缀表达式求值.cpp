#include <iostream>
#include "../31_stack_栈/311_seqstack_顺序栈.h"
#include <vector>
using namespace std;

/*
    中缀表达式:A+B*(C-D)-E/F
    前缀表达式:+A-*B-CD/EF
    功能:后缀表达式求值
    输入: 
        const vector<string>& vs: 含有前缀表达式的字符串
    输出:
        int: 前缀表达式求值结果
    分析思路:
        从头遍历字符串，运用栈的后进先出(LIFO)特性，实现前缀表达式求值
    实现细节:
        从尾部向前遍历字符串，对不同字符串分别处理
            a. 遇到数值，直接压入栈
            b. 遇到符号后，依次弹出两个操作数a(栈顶元素)、b分别作为左操作数和右操作数，进行运算后 a op b,将结果放入栈中
    注意点:
    时间复杂度:
        O(n)
    空间复杂度
*/

float EvaluationOfPrefixExpression(const vector<string>& vs)
{
    SeqStack<float> sqi;
    float result = 0;
    float lv, rv;
    sqi.InitStack();
    for(vector<string>::const_reverse_iterator rs = vs.rbegin(); rs != vs.rend(); rs++)
    {
        if(*rs == "+")
        {
            if(sqi.Pop(lv) && sqi.Pop(rv))
            {
                cout << lv << "+" << rv << "=" << lv+rv << endl;
                sqi.Push(lv+rv);
            }
        }
        else if(*rs == "-")
        {
            if(sqi.Pop(lv) && sqi.Pop(rv))
            {
                cout << lv << "-" << rv << "=" << lv-rv << endl;
                sqi.Push(lv-rv);
            }
        }
        else if(*rs == "*")
        {
            if(sqi.Pop(lv) && sqi.Pop(rv))
            {
                cout << lv << "*" << rv << "=" << lv*rv << endl;
                sqi.Push(lv*rv);
            }
        }
        else if(*rs == "/")
        {
            if(sqi.Pop(lv) && sqi.Pop(rv))
            {
                cout << lv << "/" << rv << "=" << lv/rv << endl;
                sqi.Push(lv/rv);
            }
        }
        else
        {
            float val = stof(*rs);
            sqi.Push(val);
        }  
    }
    return sqi.GetTop(result)?result:-1;
}

/*
    中缀表达式:20+8*7/4-33+2x3
    后缀表达式:87
    功能:后缀表达式求值
    输入: 
        const string s: 含有后缀表达式的字符串
    输出:
        int: 后缀表达式求值结果
    分析思路:
        从头遍历字符串，运用栈的后进先出(LIFO)特性，实现后缀表达式求值
    实现细节:
        从头遍历字符串，对不同字符串分别处理
            a. 遇到数值，直接压入栈
            b. 遇到符号后，依次弹出两个操作数a(栈顶元素)、b分别作为右操作数和左操作数，进行运算后 b op a,将结果放入栈中
    注意点:
    时间复杂度:
        O(n)
    空间复杂度
*/

float EvaluatePostfixExpression(const vector<string>& vs)
{
    SeqStack<float> sqi;
    float result = 0;
    float lv, rv;
    sqi.InitStack();
    for(auto s : vs)
    {
        if(s == "+")
        {
            if(sqi.Pop(rv) && sqi.Pop(lv))
            {
                cout << lv << "+" << rv << "=" << lv+rv << endl;
                sqi.Push(lv+rv);
            }
        }
        else if(s == "-")
        {
            if(sqi.Pop(rv) && sqi.Pop(lv))
            {
                cout << lv << "-" << rv << "=" << lv-rv << endl;
                sqi.Push(lv-rv);
            }
        }
        else if(s == "*")
        {
            if(sqi.Pop(rv) && sqi.Pop(lv))
            {
                cout << lv << "*" << rv << "=" << lv*rv << endl;
                sqi.Push(lv*rv);
            }
        }
        else if(s == "/")
        {
            if(sqi.Pop(rv) && sqi.Pop(lv))
            {
                cout << lv << "/" << rv << "=" << lv/rv << endl;
                sqi.Push(lv/rv);
            }
        }
        else
        {
            float val = stof(s);
            sqi.Push(val);
        }  
    }
    return sqi.GetTop(result)?result:-1;
}

int main()
{
    //12+22*(13-41)-66/5
    vector<string> vs_post{"12" , "22" , "13" , "41", "-", "*", "+", "66", "5", "/", "-"};
    cout << EvaluatePostfixExpression(vs_post) << endl;
    cout << endl;

    vector<string> vs_pre{"+" , "12", "-", "*", "22", "-", "13", "41", "/", "66", "5"};
    cout << EvaluationOfPrefixExpression(vs_pre) << endl;
    return 0;
}