#include <iostream>
#include "../../22_list_单链表/221_list_单链表.h"
using namespace std;
using LNode = LinkList<int>::LNode;

/*
    功能: 删除带头结点单链表中绝对值重复的结点，保留第一个结点
    输入:
        LinkList<int>& L:
    输出:
        int:被删除结点的个数
    分析思路:
        已知条件: 结点绝对值小于 n
        将单链表绝对值去重，需要遍历单链表，并且能记下已遍历结点的值
    实现细节:
        1. 所有元素值小于等于 n，可以定义一个数组 int arr[n+1];
        2. 遍历单链表，将不重复的数加入数组中，用于每次比对
        
    注意点:
        
    时间复杂度:
            
    空间复杂度:
            
*/

int abs_(int v)
{
    if(v < 0)
        return -v;
    else 
        return v;
}

bool isInArr(int *arr, int n, int v)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == v)
        {
            return true;
        }
        if(arr[i] == -1)
        {
            arr[i] = v;
            return false;
        }
    }
    return false;
}

int UniqueAbs(LinkList<int>& L)
{
    //1. 判空
    if(L.Empty())
    {
        cout << "表空" << endl;
        return 0;
    }

    //2. 
    int arr[20] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int num = 0;
    LNode* preNode = L.GetHeadNode();
    LNode* curNode = preNode->next;
    while(curNode)
    {
        int tmpData = curNode->data;
        if(isInArr(arr, 20, abs_(tmpData)))
        {
            num++;
            preNode->next = curNode->next;
            free(curNode);
            curNode = preNode->next;
        }
        else
        {
            preNode = curNode;
            curNode = curNode->next;
        }
    }

    return num;
}

int main()
{
    LinkList<int> L;
    L.InitList();
    L.ListInsert(1, 1);
    L.ListInsert(2, -1);
    L.ListInsert(3, 5);
    L.ListInsert(4, 1);
    L.ListInsert(5, -5);

    L.PrintList();

    cout << "删除了 " << UniqueAbs(L) << " 个重复的结点" << endl;

    L.PrintList();

    return 0;
}