#include <iostream>
#include "41_seq_string_顺序存储串.h"
using namespace std;

//初始化串
bool InitString(SString &str)
{
    //串的第一个字符留置不用
    str.ch[0] = 0;
    str.length = 0;
    cout << "初始化字符串成功" << endl;
    return true;
}

//求子串，用 sub 返回
bool SubString(SString &sub, SString &str, int pos)
{
    //判断截取位置是否合法
    if(pos > str.length)
    {
        cout << "截取的子串位置不合法" << endl;
        return false;
    }
    int tmp_pos = pos;
    while(tmp_pos <= str.length)
    {
        sub.ch[1+tmp_pos-pos] = str.ch[tmp_pos++];
    }
    return true;
}

//比较
int StrCompare(const SString &str1, const SString &str2)
{
    int str1_tmp_pos = 1;
    int str2_tmp_pos = 1;
    int result = 0;
    while(str1_tmp_pos <= str1.length && str2_tmp_pos <= str2.length)
    {
        if(str1.ch[str1_tmp_pos] != str2.ch[str2_tmp_pos])
        {
            result = str1.ch[str1_tmp_pos] - str2.ch[str2_tmp_pos];
            break;
        }
        str1_tmp_pos++;
        str2_tmp_pos++;
    }
    if(result == 0)
    {
        result = str1.length - str2.length;
    }
    return result;
}

/*
    功能:求模式串在主串中的位置
    输入: 
        const SString &str:主串
        const SString &sub:模式串
    输出:
        int: 匹配成功的位置，0 表示匹配失败
    分析思路:
        将主串的[1, n-m+1 ] 为起始位置的所有的子串与模式串进行对比，如果对比成功，返回当前子串的起始位置
                                                            如果对比失败，返回 0
    实现细节:
        
    注意点:
        
    时间复杂度:
        O(nm)
    空间复杂度
*/
int Index_SimpleCode(const SString &str, const SString &sub)
{
    int result_pos = 0;
    if(str.length < sub.length)
    {
        cout << "模式串的长度大于主串的长度，匹配失败" << endl;
        return 0;
    }
    int end_pos = str.length - sub.length + 1;
    int sub_pos = 1;
    for(int pos = 1; pos <= end_pos; pos++)
    {

        while(sub_pos <= sub.length && str.ch[pos+sub_pos-1] == sub.ch[sub_pos])
        {
            sub_pos++;
        }
        
        if(sub_pos > sub.length)
        {
            cout << "匹配成功" << endl;
            result_pos = pos;
            break;
        }
    }
    return result_pos;
}

/*
    功能:求模式串的 next 数组
    输入: 
        const SString &sub:模式串
        int next[]
    输出:
        void
    分析思路:
        从头遍历字符串，比对当前位置 i 的字符与 i 匹配失败后移动的 next[i] 的位置 j 处的字符串
                        a.若相等,则 i+1 位置字符的 next[i+1]=j+1
                        b.若不等,则将 j = next[j]，继续比较，直到 j=0 或者满足条件 a
    实现细节:
        第一个字符串的 next 值为 0
        第二个字符串的 next 值为 1
            
    注意点:
        
        
    时间复杂度:
        O(nm)
    空间复杂度    
    
*/
void GetNext(const SString &sub, int next[])
{
    int i = 1;
    int j = 0;
    next[i] = j;
    while(i < sub.length)
    {
        //
        if(j == 0 || sub.ch[i] == sub.ch[j])
        {
            ++i;
            ++j;
            next[i] = j; 
        }
        else
        {
            j = next[j];
        }
    }
    for(int i = 1; i <= sub.length; i++)
    {
        cout << next[i] << " ";
    }
    cout << endl;
}

/*
    功能:求模式串在主串中的位置
    输入: 
        const SString &str:主串
        const SString &sub:模式串
        int next[]: next 数组
    输出:
        int: 匹配成功的位置，0 表示匹配失败
    分析思路:
        从头遍历主串 str，并在每次匹配失败后，将匹配串 sub 的当前指针 cur_p 移到 next[cur_p] 继续进行匹配
    实现细节:
        
    注意点:
        
    时间复杂度:
        O(n+m)
    空间复杂度
*/
int Index_KMP(const SString &str, const SString &sub, int next[])
{
    int i = 1;
    int j = 1;
    while(i <= str.length-sub.length+1 && j <= sub.length)
    {
        if(j == 0 || str.ch[i] == sub.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if(j > sub.length)
        return i-sub.length;
    else
        return 0;
}

//赋值操作
bool StrAssign(SString &str, const char *chars)
{
    if(!chars)
    {
        cout << "字符串无效" << endl;
        return false;
    }
    int pos = 1;
    str.length = 0;
    while(chars[pos-1] && pos < MAXLEN)
    {
        str.ch[pos] = chars[pos-1];
        pos++;
        str.length++;
    }
    return true;
}

//复制操作
void StrCopy(SString &str, const SString &src)
{
    StrAssign(str, src.ch+1);
}

//判空操作
bool StrEmpty(const SString &str)
{
    return (str.length==0)?true:false;
}

//求长度操作
int StrLength(const SString &str)
{
    return str.length;
}

//清空操作
void ClearString(SString &str)
{
    for(int pos = 1; pos <= str.length; pos++)
    {
        str.ch[pos] = '\0';
    }
    str.length = 0;
}

//销毁操作
void DestroyString(SString &str)
{
    for(int pos = 1; pos <= str.length; pos++)
    {
        str.ch[pos] = '\0';
    }
    str.length = 0;
}

//串连接操作
void Concat(SString &str, const SString &str1, const SString &str2)
{
    int str1_pos = 1;
    while(str1_pos <= str1.length)
    {
        str.ch[str1_pos] = str1.ch[str1_pos];
        str1_pos++;
    }
    str.length = str1.length;
    int str2_pos = 1;
    while(str.length+1 <= MAXLEN && str2_pos <= str2.length)
    {
        str.ch[str.length+str2_pos] = str2.ch[str2_pos];
        str2_pos++;
        str.length++;
    }
}

//打印串
void PrintStr(const SString &str)
{
    for(int pos = 1; pos <= str.length; pos++)
    {
        cout << str.ch[pos];
    }
    cout << endl;
}

int main()
{
    SString Str1, Str2, Str3;
    int next[MAXLEN];
    const char * ps1 = "hhhhhh";
    const char * ps2 = "hello world2";
    InitString(Str1);
    InitString(Str2);
    InitString(Str3);
    StrAssign(Str1, ps1);
    StrAssign(Str2, ps2);
    StrCopy(Str3, Str2);
    PrintStr(Str1);
    PrintStr(Str2);
    PrintStr(Str3);
    cout << StrCompare(Str1, Str1) << endl;
    cout << "Str1 Empty:" << StrEmpty(Str1) << endl;
    cout << "Str1 Length:" << StrLength(Str1) << endl;

    cout << Index_SimpleCode(Str2, Str1) << endl;

    GetNext(Str1, next);
    
    return 0;
}