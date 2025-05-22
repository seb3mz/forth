#include <iostream>
#include "../31_stack_栈/311_seqstack_顺序栈.h"
#include <vector>
using namespace std;

/*
    中缀表达式:20+8*7/4-33+2x3
    功能:中缀表达式求值
    输入: 
        const vector<string>& vs: 含有后缀表达式的字符串
    输出:
        float: 后缀表达式求值结果
    分析思路:
        从头遍历字符串，运用栈的后进先出(LIFO)特性，实现中缀表达式求值
    实现细节:
        定义两个栈，分别保存运算符的栈 opera_stack 和存储操作数的栈 num_stack
        从头遍历字符串，对不同字符串分别处理
            a. 遇到数值，直接压入栈 num_stack
            b. 遇到符号后，与栈顶元素比较优先级
                    b.1 若栈顶元素优先级较低:将符号入栈
                    b.2 若栈顶元素优先级不低于当前符号:弹出 opera_stack 栈顶元素 ope 和 num_stack 内两个元素 lv和rv，计算 lv ope rv,将结果存入 num_stack        
                    b.3 若栈顶元素为 "("，直接入栈
            c. 遇到分隔符号 "(", 直接入栈 opera_stack
            d. 遇到分隔符号 ")", 将 opera_stack 所有元素弹出，直到遇到 "("
        遍历完成后，再遍历 opera_stack，将所有元素计算得出最终结果
    注意点:
        b. 第一次遇到符号时，此时栈空，直接入栈
            b.2 若弹出 opera_stack 栈顶元素后，栈变空，此时将当前符号入栈 opera_stack;后续遇到符号后，直接加入栈;
            b.2 连续弹出 opera_stack 栈顶元素，直到遇到第一个优先级低于当前符号的符号，或者遇到 "("
                    此时将当前符号入栈 opera_stack
    时间复杂度:
        O(n)
    空间复杂度
*/

float EvaluationOfInfixExpressions(const vector<string>& vs)
{
    SeqStack<float> sq_num;
    SeqStack<string> sq_opera;
    float result = 0.0;
    sq_num.InitStack();
    sq_opera.InitStack();

    for(auto s : vs)
    {
        string top;
        float lv, rv;
        //b. 遇到符号后，与栈顶元素比较优先级
        if(s == "+" || s == "-")
        {
            ////b.2 若栈顶元素优先级不低于当前符号
            while(sq_opera.GetTop(top))
            {
                //b.3 若栈顶元素为 "("，直接入栈
                if(top == "(")
                {
                    sq_opera.Push(s);
                    break;
                }

                sq_opera.Pop(top);
                sq_num.Pop(rv);
                sq_num.Pop(lv);
                if(top == "+")
                {
                    result = lv + rv;
                    cout << "result = " << lv << "+" << rv << endl;
                }
                else if(top == "-")
                {
                    result = lv - rv;
                    cout << "result = " << lv << "-" << rv << endl;
                }
                else if(top == "*")
                {
                    result = lv * rv;
                    cout << "result = " << lv << "*" << rv << endl;
                }
                else if(top == "/")
                {
                    result = lv / rv;
                    cout << "result = " << lv << "/" << rv << endl;
                }
                sq_num.Push(result);
            }
            //b. 栈空，直接入栈
            if(sq_opera.StackEmpty())
            {
                sq_opera.Push(s);
            }
        }
        //b. 遇到符号后，与栈顶元素比较优先级
        else if(s == "*" || s == "/")
        {
            //b.2 若栈顶元素优先级不低于当前符号
            while(sq_opera.GetTop(top))
            {
                //b.3 若栈顶元素为 "("，直接入栈
                if(top == "+" || top == "-" || top == "(")
                {
                    sq_opera.Push(s);
                    break;
                }

                sq_opera.Pop(top);
                sq_num.Pop(rv);
                sq_num.Pop(lv);
                if(top == "*")
                {
                    result = lv * rv;
                    cout << "result = " << lv << "*" << rv << endl;
                }
                else if(top == "/")
                {
                    result = lv / rv;
                    cout << "result = " << lv << "/" << rv << endl;
                }
                sq_num.Push(result);
                
            }
            //b. 栈空，直接入栈
            if(sq_opera.StackEmpty())
            {
                sq_opera.Push(s);
            }
        }
        //c. 遇到分隔符号 "(", 直接入栈 opera_stack
        else if(s == "(")
        {
            sq_opera.Push(s);
        }
        //d. 遇到分隔符号 ")", 将 opera_stack 所有元素弹出，直到遇到 "("
        else if(s == ")")
        {
            do {
                sq_opera.Pop(top);
                if(top != "(")
                {
                    sq_num.Pop(rv);
                    sq_num.Pop(lv);
                    if(top == "+")
                    {
                        result = lv + rv;
                    }
                    else if(top == "-")
                    {
                        result = lv - rv;
                    }
                    else if(top == "*")
                    {
                        result = lv * rv;
                    }
                    else if(top == "/")
                    {
                        result = lv / rv;
                    }
                    sq_num.Push(result);
                }
            } while(top != "(");
        }
        //a. 遇到数值，直接压入栈 num_stack
        else
        {
            sq_num.Push(stof(s));
        }
    }
    string top;
    while(sq_opera.GetTop(top))
    {
        float lv, rv;
        sq_opera.Pop(top);
        sq_num.Pop(rv);
        sq_num.Pop(lv);
        if(top == "+")
        {
            result = lv + rv;
        }
        else if(top == "-")
        {
            result = lv - rv;
        }
        else if(top == "*")
        {
            result = lv * rv;
        }
        else if(top == "/")
        {
            result = lv / rv;
        }
        sq_num.Push(result);
    }
    sq_num.GetTop(result);
    return result;
}

int main()
{
    //20+8*7/4-33+2x3
    // 20+8*7/(4-33)+2x3
    const vector<string> vs{"20", "+", "8", "*", "7", "/", "(", "4", "-", "33", ")", "+", "2", "*", "3"};
    cout << EvaluationOfInfixExpressions(vs) << endl;
    return 0;
}