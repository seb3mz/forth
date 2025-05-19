#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/2_linear_list_线性表/22_list_单链表/221_list_单链表.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;
using LNode=LinkList<int>::LNode;

/*
    功能:判断单链表 L 是否中心对称
    输入:
        LinkList<int>& L:待操作的单链表
    输出:
        bool:是否对称
    分析思路:
       判断链表是否中心对称，需要找到链表中心，用栈保存单链表的元素，并记录下个数，
       然后再次遍历单链表和栈顶元素依次比对
    实现细节:
        
    注意点:
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

bool IsSymmetrical(LinkList<int>& L)
{
    SeqStack<int> ss;
    ss.InitStack();

    int cnt = 0;
    LNode* cur = L.GetHeadNode()->next;
    while(cur)
    {
        ss.Push(cur->data);
        cnt++;
        cur = cur->next;
    }
    cout << "cnt = " << cnt << endl;
    cur = L.GetHeadNode()->next;
    int num = 0;
    bool result = true;
    int ss_v;
    int sl_v;
    while(num < cnt)
    {
       sl_v = cur->data;
       ss.Pop(ss_v); 
       if(sl_v == ss_v)
       {
            cur = cur->next;
            num++;
       }
       else
       {
            result = false;
            break;
       }
    }
    return result;
}

int main()
{
    LinkList<int> L;
    L.InitList();
    L.ListInsert(1, 23);
    L.ListInsert(2, 33);
    L.ListInsert(3, 33);

    cout << "链表" << (IsSymmetrical(L)?"中心对称":"不对称") << endl;
    return 0;
}