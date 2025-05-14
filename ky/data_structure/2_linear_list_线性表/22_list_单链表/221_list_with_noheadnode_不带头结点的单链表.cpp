#include <iostream>
#include "221_list_单链表.h"
using namespace std;

typedef struct LNode
 {
    int data;
    struct LNode* next;
}LNode, *LinkList;

//1. 初始化链表
bool InitList(LinkList &L)
{
    L = nullptr;
    cout << "不带头结点的单链表初始化成功" << endl;
    return true;
}

//判断空表
bool Empty(const LinkList& L)
{
    return L == nullptr;
}

//2. 求链表长度
int Length(const LinkList& L)
{
    int length = 0;
    LNode* tmp = L;
    while(tmp)
    {
        tmp = tmp->next;
        length++;
    }
    return length;
}

//打印链表
void PrintList(const LinkList& L)
{
    LNode * tmp = L;
    cout << "单链表遍历:";
    while(tmp)
    {
        cout << " " << tmp->data;
        tmp = tmp->next;
    }
    cout << endl;
}

//3. 按序号查找结点
LNode* GetElem(const LinkList& L, int i)
{
    LNode* tmp = L;
    int pos = 1;
    while(tmp && pos < i)
    {
        tmp = tmp->next;
        pos++;
    }

    return tmp;
}

//4. 按值查找结点
LNode* LocateElem(const LinkList& L, int e)
{
    LNode* tmp = L;
    while(tmp && tmp->data != e)
    {
        tmp = tmp->next;
    }

    return tmp;
}

//5. 在不带头结点单链表 L 中的第 i 个位置上插入指定元素 e
/*
    5.1 功能: 在表 L 中的第 i 个位置上插入指定元素 e
    5.2 输入:
            LinkList& L: 待插入元素的单链表
            i: 位序
            e: 待插入元素
    5.3 输出:
            bool 表示插入是否成功
    5.4 分析思路:
            将指定元素 e 插入到单链表的第 i 个位置，结合单链表的存储结构，
                a.需要找到第 i-1 个位置的结点 pre
                b.将待插入结点 current 的后继指针指向 pre 结点的后继指针: current->next = pre->next
                c.将结点 pre 的后继指针指向新插入的结点 current: pre->next = current
    5.5 实现细节
            定义变量:  
                    a. LNode* tmp : 代表正在遍历的结点指针;
                       int pos : 表示正在遍历结点的位序，用于找到位序 i-1
                        初始化: tmp 被初始化为单链表的指针 L, pos 为 1
                        变化: tmp 与 pos 同步变化, 代表位序为 pos 的结点,其指针为 tmp
                        结束: (tmp == nullptr || pos == i-1), 当 tmp 为空代表链表已经到尾部; pos==i-1 代表找到位序为 i-1 
    5.6 注意点
            a.当插入位序为 1 时，需要更改指针 L

    5.7 时间复杂度
            a. 当插入到链表头结点后的位置，特殊处理，时间复杂度为 O(1)
            b. 当插入到链表尾部的位置，*** ListInset 遍历链表 *** 处执行最长循环，时间复杂度为 O(n)
            c. 平均时间复杂度 O(n)
    5.8 空间复杂度
*/
bool ListInsert(LinkList &L, int i, int e)
{
    //无头结点的链表，当 i 为 1 时，特殊处理
    if(i == 1)
    {
        cout << "链表为空，创建第一个结点:" << e << endl; 
        LNode* node = (LNode*)malloc(sizeof(LNode));
        if(node == nullptr)
        {
            cout << "创建结点失败" << endl;
            return false;
        }
        node->data = e;
        node->next = nullptr;
        L = node;
        return true;
    }

    //5.1 插入位置为 i，先找到位置为 i-1 的结点
    LNode* tmp = L;
    int pos = 1;
    //*** ListInset 遍历链表 ***
    while(tmp && pos < i-1)
    {
        tmp = tmp->next;
        pos++;
    }
    // 如果链表结点个数少于 i-1 个，则无法在第 i 位置插入元素，直接返回 false
    // 或者到了链表尾部
    if(tmp == nullptr)
    {
        cout << "当前链表长度为:" << Length(L) << endl;
        cout << "在链表中第" << i-1 << "个位置插入 " << e << " 失败" << endl;
        return false;
    }

    //新增结点，然后修改指针域
    LNode* prev = tmp;
    LNode* node = (LNode*)malloc(sizeof(LNode));
    if(node == nullptr)
    {
        cout << "创建结点失败" << endl;
        return false;
    }
    node->data = e;
    node->next = prev->next;
    prev->next = node;
    cout <<"在位置" << i <<"插入数据:" << e <<"成功" << endl;
    return true;
}

//删除
bool ListDelete(LinkList &L, int i, int e)
{
    //如果删除第一个结点
    if(i == 1 && L != nullptr)
    {
        LNode* tmp = L;
        e = tmp->data;
        L = L->next;
        free(tmp);
        return true;
    }

    LNode* tmp = L;
    int pos = 1;
    while(tmp && pos < i-1)
    {
        tmp = tmp->next;
        pos++;
    }
    //第 i-1 或者 第 i 位置为空，直接返回 false
    if(tmp == nullptr || tmp->next == nullptr)
    {
        cout << "链表长度不够" << endl;
        return false;
    }
    //修改指针域并删除结点
    LNode* mid = tmp->next;
    e = mid->data;
    tmp->next = mid->next;
    free(mid);
    return true;
}

//7. 头插法建表
LinkList List_HeadInsert(LinkList& L)
{
    L = nullptr;
    int x = 0;
    scanf("%d", &x);
    L = (LNode*)malloc(sizeof(LNode));
    L->next = nullptr;
    L->data = x;
    while(x != 999)
    {
        LNode* node = (LNode*)malloc(sizeof(LNode));
        node->data = x;
        node->next = L->next;
        L->next = node;
        scanf("%d", &x);
    }
    return L;
}

//8. 尾插法建表
LinkList List_TailInsert(LinkList& L)
{
    int x = 0;
    scanf("%d", &x);
    L = (LNode*)malloc(sizeof(LNode));
    L->next = nullptr;
    L->data = x;
    LNode* rear;

     while(x != 999)
    {
        LNode* node = (LNode*)malloc(sizeof(LNode));
        node->data = x;
        node->next = nullptr;
        rear->next = node;
        rear = node;
        scanf("%d", &x);
    }

    return L;
}

int main()
{
    // 测试链表
    LinkList L;
    InitList(L);
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    ListInsert(L, 5, 5);
    ListInsert(L, 3, 100);
    ListInsert(L, 10, 200);
    PrintList(L);
    cout << "表是否为空:" << (Empty(L)?"是":"否") << endl;
    cout << "表长:" << Length(L) << endl;

    return 0;
}