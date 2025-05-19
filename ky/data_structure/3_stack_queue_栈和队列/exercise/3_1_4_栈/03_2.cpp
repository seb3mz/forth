#include <iostream>
using namespace std;

bool IsLegalOfStackSeq(const char* p)
{
    int cnt = 0;
    bool result = true;
    char *tmp = const_cast<char*>(p);
    while(*tmp != '\0')
    {
        if(*tmp == 'I')
        {
            cnt++;
        }
        else if(*tmp == 'O')
        {
            cnt--;
        }
        if(cnt < 0)
        {
            result = false;
        }
        tmp++;
    }
    return result;
}

int main()
{
    const char *crr = "IOOIOIIOIIO";

    cout << "出入栈" << (IsLegalOfStackSeq(crr)?"合法":"不合法") << endl;
    return 0;
}