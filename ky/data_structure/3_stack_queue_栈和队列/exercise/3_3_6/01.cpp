/*
    设计思想：
        使用栈来批评括号
    时间复杂度: O(n)
    空间复杂度: O(1)
*/

bool Fitter(char arr[])
{
    //定义顺序栈
    SqStack ss;
    //初始化
    InitStack(ss);
    int i = 0;
    char ss_top = '\0';
    bool result = true;
    while(arr[i] != "\0")
    {
        switch(arr[i])
        {
            case "(":
                Push(ss, arr[i]);
                break;
            case ")":
                if(ss.StackEmpty())
                {
                    result = false;
                    break;
                }
                Pop(ss, ss_top);
                if(ss_top != "(")
                {
                    result = false;
                }
                break;
            case "[":
                Push(ss, arr[i]);
                break;
            case "]":
                if(ss.StackEmpty())
                {
                    result = false;
                    break;
                }
                Pop(ss, ss_top);
                if(ss_top != "[")
                {
                    result = false;
                }
                break;
            case "{":
                Push(ss, arr[i]);
                break;
            case "}":
                if(ss.StackEmpty())
                {
                    result = false;
                    break;
                }
                Pop(ss, ss_top);
                if(ss_top != "{")
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
        return false;
    }
    else
    {
        return false;
    }
}