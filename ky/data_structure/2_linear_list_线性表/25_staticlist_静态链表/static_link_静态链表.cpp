#include "static_link_静态链表.h"
#include <iostream>
using namespace std;

/*
    功能:初始化静态链表
    输入:
        SLinkList &L: 待初始化的静态链表
    输出:
        bool 表示初始化是否成功
    分析思路:
        静态链表是一串连续的内存空间，指定初始结点固定为头结点，初始化时头结点的游标为 -1,其他结点游标为 -2
    实现细节:
    注意点:
    时间复杂度:
        O(n)
    空间复杂度:
*/
//初始化链表
bool InitList(SLinkList &L)
{
    cout << "InitList:初始化静态链表" << endl;
    //初始化头结点游标为 -1
    L[0].next = -1;
    //默认其他结点游标为 -2
    for(int pos = 2; pos <= MaxSize; pos++)
    {
        L[pos-1].next = -2;
    }
    cout << "初始化静态链表成功" << endl;
    return true;
}

//判断空表
bool Empty(const SLinkList& L)
{
    return (L[0].next==-1)?true:false;
}

//求链表长度
int Length(const SLinkList& L)
{
    int cnt = 0;
    int tmp_index = L[cnt].next;
    while(tmp_index != -1)
    {
        tmp_index = L[tmp_index].next;
        cnt++;
    }
    return cnt;
}

//打印链表
void PrintList(const SLinkList &L)
{
    cout << "PrintList:打印静态链表" << endl;
    //判断头结点是否有后继结点
    int index = L[0].next;
    if(index == -1)
    {
        cout << "表为空" << endl;
        return;
    }

    while(index != -1)
    {
        cout << "index:" << index << endl;
        cout << "data:" << L[index].data << endl;
        cout << "next:" << L[index].next << endl << endl;
        index = L[index].next;
    }
    cout << endl;
}

// 链表的插入操作
//在链表位序 i 处插入值 e
/*
    功能:在静态链表位序 i 处插入值 e
    输入:
        SLinkList &L:待插入的静态链表
        int i:待插入的位序
        int e:待插入元素
    输出:
        bool: 表示是否插入成功
    分析思路:
        a.先找到第一个空白结点 cur，将 e 插入，记录其在数组中的下标索引 cur_index;
                L[cur_index].data = e;
        b.找到位序为 i-1 的结点 pre_index，先记录下其next域到 pre_cursor，然后将其 next 域修改为 cur_index;
                pre_cursor = L[pre_index].next;
                L[pre_index].next = cur_index;
        c.将新插入结点 cur 的 next 域改为 pre_cursor
                L[cur_index].next = pre_cursor;
    实现细节:
        a. 从索引 1 开始遍历数组，找到第一个 next 值域为 -2 的结点，即为空白结点，记录其在数组中的索引 cur_index;
            索引 0 的结点是头结点
        b. 从头结点开始找到位序为 i-1 的结点
                i.若在位序 i-1 之前的结点出现了 next 域为 -1，表明表长不足 i-1，无法在第 i 位序插入
                ii.若在位序 i-1 处的结点 next 域为 -1，表明表长为 i-1，要在链表尾新增元素，此结点当前结点的数组下标 cur_index 需要记录下来
        c. 修改第 i-1 个结点的 next 域和 新结点的 next 域
    注意点:
        
    时间复杂度:
    空间复杂度:
*/
bool ListInsert(SLinkList &L, int i, int e)
{
    cout << "ListInsert:在静态链表插值" << endl;
    if(i < 1)
    {
        cout << "插入位置:" << i << "不合法" << endl;
        return false;
    }

    // 步骤 a，查找数组中第一个空闲结点
    int free_index = 1;
    while(L[free_index].next != -2 && free_index < MaxSize)
    {
        free_index++;
        //free_index = L[free_index].next;
    }
    if(free_index == MaxSize)
    {
        cout << "静态链表已满，插入结点失败" << endl;
        return false;
    }
    cout << "free_index:" << free_index << endl;
    L[free_index].data = e;

    // 步骤 b，查找位序为 i-1 的结点
    int pos = 0;
    int cur_index = 0;
    int next_index = L[pos].next;
    while(next_index != -1 && pos < i-1)
    {
        cur_index = next_index;
        next_index = L[next_index].next;
        pos++;
    }
    cout << "cur_index:" << cur_index  << ",next_index:" << next_index << ", pos:" << pos << endl;
    if(next_index == -1 && pos != i-1)
    {
        cout << "当前表长:" << Length(L) << ",而查找的位序为:" << i << ",查找失败" << endl;
        return false;
    }
    else if(next_index == -1 && pos == i-1)
    {
        //第 i-1 个结点是链表最后一个结点
        cout << "插入表尾" << endl;
    }
    
    // 步骤 c
    int pre_index = L[cur_index].next;
    L[cur_index].next = free_index;
    L[free_index].next = pre_index;
    cout << "插入结点成功" << endl;
    cout << endl;
    return true;
}

/*
    功能:删除链表中第 i 处的元素，并用 e 返回
    输入:
        LinkList &L:待删除结点的链表
        int i:待删除结点的位序
        int e:待删除结点的值
    输出:
        bool:表示是否删除成功
    分析思路:
        找到位序为 i-1 的结点 pre_node 和位序为 i 的结点 cur_node
        将  pre_node 的 next 域修改为 cur_node 的 next 域
        将 cur_node 的 next 域修改为 -2:表示空白结点
    实现细节:
    注意点:
    时间复杂度:
    空间复杂度:
*/

bool ListDelete(SLinkList &L, int i, int e)
{
    cout << "ListDelete:在静态链表删值" << endl;
    if(i < 1)
    {
        cout << "删除位置:" << i << "不合法" << endl;
        return false;
    }
    int pos = 0;
    int cur_node = 0;
    int next_node = L[0].next;
    while(next_node != -1 && pos < i-1)
    {
        cur_node = next_node;
        next_node = L[next_node].next;
        pos++;
    }
    if(next_node == -1)
    {
        cout << "当前表长:" << Length(L) << ",而删除的位序为:" << i << ",删除失败" << endl;
        return false;
    }

    L[cur_node].next = L[next_node].next;
    L[next_node].next = -2;

    cout << "删除成功" << endl;
    return true;
}

int main()
{
    // 测试初始化静态链表操作
    cout << "*******************测试初始化静态链表操作*****************" << endl;
    SLinkList L;
    InitList(L);
    cout << "表是否为空:" << (Empty(L)?"是":"否") << endl;
    PrintList(L);

    // 测试静态链表插入操作
    cout << "*******************测试静态链表插入操作*****************" << endl;
    ListInsert(L, 1, 11);
    ListInsert(L, 2, 22);
    ListInsert(L, 2, 77);
    ListInsert(L, 3, 33);
    ListInsert(L, 4, 44);
    ListInsert(L, 6, 66);
    ListInsert(L, 8, 88);
    cout << "表长:" << Length(L) << endl;
    PrintList(L);

    // 测试静态链表删除操作
    cout << "*******************测试静态链表删除操作*****************" << endl;
    int ret = 0;
    ListDelete(L, 1, ret);
    ListDelete(L, 5, ret);
    ListDelete(L, 3, ret);
    cout << "表长:" << Length(L) << endl;
    PrintList(L);
    return 0;
}