#include <iostream>
#include "../31_stack_栈/311_seqstack_顺序栈.h"
#include <vector>
#include <set>
using namespace std;

void PrintVec(vector<string> result)
{
    for(vector<string>::const_iterator it = result.begin(); it != result.end(); it++)
    {
        cout << *it <<" ";
    }
    cout << endl;
}

void PrintVecR(vector<string> result)
{
    for(vector<string>::const_reverse_iterator it = result.rbegin(); it != result.rend(); it++)
    {
        cout << *it <<" ";
    }
    cout << endl;
}

/*
    中缀表达式:20+8*7/4-33+2*3
    前缀表达式:+,20,-,*8,/,7,4,+,33,*,2,3
    中缀表达式:(20+8)*7/4-33+2*3
    前缀表达式:-,*,+,20,8,/,7,4,+,33,*,2,3
    功能:中缀表达式转换为前缀表达式
    输入: 
        const vector<string>& s: 含有中缀表达式的字符串
    输出:
        const vector<string>: 转换后的前缀表达式
    分析思路:
        从尾部向前遍历，根据栈的后进先出(LIFO)特性，实现中缀表达式转前缀表达式
    实现细节:
        从后向前遍历字符串,结合当前栈的状态，对不同种类字符串分别处理
            a. 遇到数字字符串，直接放入后缀表达式
            b. 遇到操作符字符串
                    1.如果栈空，直接放入栈中
                    2.如果栈非空，将栈中优先级别大于或等于当前运算符的符号依次出栈加入后缀表达式中
                        2.1 直到栈空，此时将当前运算符加入栈中
                        2.2 或遇到 ")" 时，停止
            c. 遇到界限符 ')', 直接入栈; 
            d. 遇到界限符 '()',依次弹出栈内运算符加入后缀表达式直到弹出 ")" 为止
    注意点:
    时间复杂度:
        O(n)
    空间复杂度
*/
const vector<string> InfixExpressionToPrefixExpression(const vector<string>& s)
{
    //保存不确定位置的操作符
    SeqStack<string> sqi;
    //保存后缀表达式
    vector<string> result;
    sqi.InitStack();

    for(vector<string>::const_reverse_iterator it = s.rbegin(); it != s.rend(); it++)
    {
        //b. 遇到操作符字符串
        if(*it == "+" || *it == "-")
        {  
            cout << "当前符号为:" << *it << endl;
            string top;
            
            while(sqi.GetTop(top))
            {
                cout << "当前栈顶元素1为" << top << endl;
                //b.2 如果栈非空，将栈中优先级别大于或等于当前运算符的符号依次出栈加入后缀表达式中
                if(top == "+" || top == "-" || top == "*" || top == "/")
                {
                    sqi.Pop(top);
                    cout << "栈顶元素插入后缀表达式" << endl;
                    result.push_back(top);
                    PrintVecR(result);
                }
                //b.2.2 或遇到 "(" 时，停止
                else if(top == ")")
                {
                    sqi.Push(*it);
                    cout << "符号:" << *it << "加入栈中" << endl;
                    break;
                }
            }
            //b.1.如果栈空，直接放入栈中
            //b.2.1 直到栈空，此时将当前运算符加入栈中
            if(sqi.StackEmpty())
            {
                cout << "栈空,直接插入符号:" << *it << endl;
                sqi.Push(*it);
            }
        }
        //b. 遇到操作符字符串
        else if(*it == "*" || *it == "/")
        {
            cout << "当前符号为:" << *it << endl;
            string top;
            while(sqi.GetTop(top))
            {
                cout << "当前栈顶元素2为" << top << endl;
                if(top == "*" || top == "/")
                {
                    sqi.Pop(top);
                    cout << "栈顶元素插入后缀表达式" << endl;
                    result.push_back(top);
                    PrintVecR(result);
                }
                else if(top == ")" || top == "+" || top == "-")
                {
                    sqi.Push(*it);
                    cout << "符号:" << *it << "加入栈中" << endl;
                    break;
                }
            }
            //1.如果栈空，直接放入栈中
            if(sqi.StackEmpty())
            {
                cout << "栈空,直接插入符号:" << *it << endl;
                sqi.Push(*it);
            }
        }
        else if(*it == ")")
        {
            cout << "符号:" << *it << "加入栈中" << endl;
            sqi.Push(*it);
        }
        else if(*it == "(")
        {
            string top;

            do {
                sqi.Pop(top);
                if(top != ")")
                {
                    result.push_back(top);
                    PrintVecR(result);
                }
            }while(top != ")");
        }
        // a. 遇到数字字符串，直接放入后缀表达式
        else
        {
            result.push_back(*it);
            PrintVecR(result);
        }
    }

    string top;
    while(sqi.Pop(top))
    {
        result.push_back(top);
    }

    return result;
}

/*
    中缀表达式:20+8*7/4-33+2*3
    后缀表达式:20,8,7,*,4,/,+,33,-,2,3,*,+
    功能:中缀表达式转换为后缀表达式
    输入: 
        const vector<string>& s: 含有中缀表达式的字符串
    输出:
        const vector<string>: 转换后的后缀表达式
    分析思路:
        从头遍历字符串，运用栈的后进先出(LIFO)特性，实现中缀表达式转后缀表达式
    实现细节:
        从头遍历字符串,结合当前栈的状态，对不同种类字符串分别处理
            a. 遇到数字字符串，直接放入后缀表达式
            b. 遇到操作符字符串(+、-、*、/)
                    1.如果栈空，直接放入栈中
                    2.如果栈非空，将栈中优先级别大于或等于当前运算符的符号依次出栈加入后缀表达式中
                        2.1 直到栈空，此时将当前运算符加入栈中
                        2.2 或遇到 "(" 时，停止
            c. 遇到界限符 '(', 直接入栈; 
            d. 遇到界限符 ')',依次弹出栈内运算符加入后缀表达式直到弹出 "(" 为止
    注意点:
    时间复杂度:
        O(n)
    空间复杂度
*/
const vector<string> ConvertInfixExpressionToSuffixExpression(const vector<string>& s)
{
    //保存不确定位置的操作符
    SeqStack<string> sqi;
    //保存后缀表达式
    vector<string> result;
    sqi.InitStack();
    
    for(vector<string>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        // if((*it == "+" || *it == "-" || *it == "*" || *it == "/" || *it == "(") && sqi.StackEmpty())
        // {
        //     cout << "栈空,直接插入符号:" << *it << endl;
        //     sqi.Push(*it);
        //     continue;
        // }

        //b. 遇到操作符字符串
        if(*it == "+" || *it == "-")
        {  
            //cout << "当前符号为:" << *it << endl;
            string top;
            
            while(sqi.GetTop(top))
            {
                //cout << "当前栈顶元素1为" << top << endl;
                //b.2 如果栈非空，将栈中优先级别大于或等于当前运算符的符号依次出栈加入后缀表达式中
                if(top == "+" || top == "-" || top == "*" || top == "/")
                {
                    sqi.Pop(top);
                    //cout << "栈顶元素插入后缀表达式" << endl;
                    result.push_back(top);
                    //PrintVec(result);
                }
                //b.2.2 或遇到 "(" 时，停止
                else if(top == "(")
                {
                    sqi.Push(*it);
                    //cout << "符号:" << *it << "加入栈中" << endl;
                    break;
                }
            }
            //b.1.如果栈空，直接放入栈中
            //b.2.1 直到栈空，此时将当前运算符加入栈中
            if(sqi.StackEmpty())
            {
                //cout << "栈空,直接插入符号:" << *it << endl;
                sqi.Push(*it);
            }
        }
        //b. 遇到操作符字符串
        else if(*it == "*" || *it == "/")
        {
            //cout << "当前符号为:" << *it << endl;
            string top;
            while(sqi.GetTop(top))
            {
                //cout << "当前栈顶元素2为" << top << endl;
                if(top == "*" || top == "/")
                {
                    sqi.Pop(top);
                    //cout << "栈顶元素插入后缀表达式" << endl;
                    result.push_back(top);
                    //PrintVec(result);
                }
                else if(top == "(" || top == "+" || top == "-")
                {
                    sqi.Push(*it);
                    //cout << "符号:" << *it << "加入栈中" << endl;
                    break;
                }
            }
            //1.如果栈空，直接放入栈中
            if(sqi.StackEmpty())
            {
                //cout << "栈空,直接插入符号:" << *it << endl;
                sqi.Push(*it);
            }
        }
        else if(*it == "(")
        {
            //cout << "符号:" << *it << "加入栈中" << endl;
            sqi.Push(*it);
        }
        else if(*it == ")")
        {
            string top;

            do {
                sqi.Pop(top);
                if(top != "(")
                {
                    result.push_back(top);
                    //PrintVec(result);
                }
            }while(top != "(");
        }
        // a. 遇到数字字符串，直接放入后缀表达式
        else
        {
            result.push_back(*it);
            //PrintVec(result);
        }
    }

    string top;
    while(sqi.Pop(top))
    {
        result.push_back(top);
    }

    return result;
}

int main()
{
    string ss = "20+8*7/4-33+2*3";
    vector<string> ts_pre = {"(", "20", "+", "8", ")","*", "7", "/", "4",  "-", "33", "+", "2", "*", "3"};
    vector<string> ts_post = {"20", "+", "8", "*", "7", "/", "4",  "-", "33", "+", "2", "*", "3"};

    const vector<string>res_pre = InfixExpressionToPrefixExpression(ts_pre);
    const vector<string>res_post =  ConvertInfixExpressionToSuffixExpression(ts_post);
    
    for(vector<string>::const_reverse_iterator it = res_pre.rbegin(); it != res_pre.rend(); it++)
    {
        cout << *it << " ";
    }

    cout << endl << "********************************" << endl;
    for(vector<string>::const_iterator it = res_post.begin(); it != res_post.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}