#include <iostream>
using namespace std;

// 在 s 中暴力匹配子串 T
int Index(string S, string T)
{
    int spos = 1, tpos = 1;
    while(spos < S.length() && tpos < T.length())
    {
        if(S[spos-1] == T[tpos-1])
        {
            spos++;
            tpos++;
        }
        else
        {
            spos = spos - tpos + 2;
            tpos = 1;
        }
    }

    if(tpos == T.length())
    {
        return spos-tpos+1;
    }
    else
    {
        return 0;
    }
}

// next 数组
void next(string T, int *arr)
{
    // i 表示当前 next 数组元素的序号
    // j 表示 next 数组元素的值
    int i = 1, j = 0;
    //字符串的第一位字符匹配失败后，重新定位到字符串的 0 位
    arr[i-1] = 0;
    while(i < T.length())
    {
        // 对于第 i 位，匹配失败后，该移动到哪个位置继续匹配
        /*
            如果第 i 位批评失败，需要先看下 i-1 失败移动的位置 j = arr[i-1]，比较 T[j] 和 T[i] 是否相等
                        如果相等，则 arr[i]=arr[i-1]+1
                        如果不等，继续查看 j = arr[j] 的位置上的值 T[j] 是否与 T[i] 相等
        */ 
        if(T[i] == T[j])
        {
            
        }
        else
        {

        }
    }
}

// KMP 算法
int KMP(string S, string T)
{
    // 先求 next 数组
    const int num = T.length();
    int arr[num] = {0};
    next(T, arr);

}

int main()
{
    cout << Index("abcdefssdsad", "xx") << endl;
    return 0;
}