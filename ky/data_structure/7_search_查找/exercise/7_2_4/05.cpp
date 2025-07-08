#include <iostream>
using namespace std;

/*
    功能:
        1. 顺序表实现将经常访问的元素放到前面
        2. 链表实现将经常访问的元素放到前面
    输入:
    输出:

    分析思路:
    实现细节:
    注意点:
    时间复杂度:
    空间复杂度:
*/

int SeqFind(int arr[], int len, int key)
{
    for(int i = 0; i < len; i++)
    {
        if(key == arr[i])
        {
            if(i == 0)
            {
                return i;
            }
            else 
            {
                arr[i] = arr[i-1];
                arr[i-1] = key;
                return i-1;
            }
        }
    }
    return -1;
}

typedef struct LNode
 {
    int data;
    struct LNode* next;
}LNode, *LinkList;

//带头结点的链表
LNode* ListFind(LinkList list, int key)
{
    LNode * pre = list;
    LNode * cur = list->next;

    while(cur)
    {
        if(cur->data == key)
        {
            if(pre == list)
            {
                return cur;
            }
            else
            {
                cur->data = pre->data;
                pre->data = key;
                return pre;
            }
        }
        cur = cur->next;
    }

    return nullptr;
}

int main()
{
    return 0;
}