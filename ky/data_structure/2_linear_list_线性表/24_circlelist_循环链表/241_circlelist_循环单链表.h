#ifndef CIRCLE_LIST_H
#define CIRCLE_LIST_H
#include <iostream>
using namespace std;
//循环单链表
template<typename T>
class LinkList
{
public:
    struct LNode
    {
        T data;
        LNode* next;
    };
    //获取头结点，测试使用
    LNode* GetHeadNode()
    {
        return head;
    }

    //初始化链表
    bool InitList();

    //判断空表
    bool Empty() const;

    //打印链表
    void PrintList() const;

    //插入结点
    bool ListInsert(int i, int e);

private:
    LNode* head;
};

//初始化链表
template<typename T>
bool LinkList<T>::InitList()
{
    head = (LNode*)malloc(sizeof(LNode));
    if(head == nullptr)
    {
        cout << "初始化循环单链表失败" << endl;
        return false;
    }
    head->next = head;
    return true;
}

//判断空表
template<typename T>
bool LinkList<T>::Empty() const
{
    if(head == nullptr)
    {
        cout << "链表未初始化";
        return false;
    }

    return (head->next == head);
}

//打印链表
template<typename T>
void LinkList<T>::PrintList() const
{
    if(head == nullptr)
    {
        cout << "链表未初始化";
        return;
    }
    LNode* cur = head->next;
    while(cur != head)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

//插入结点
template<typename T>
bool LinkList<T>::ListInsert(int i, int e)
{
    // 判断插入位置是否合法
    if(i < 1)
    {
        cout << "插入未知为 " << i << " 不合法，插入失败" << endl;
        return false;
    }

    //插入位序为 i，先找到位置为 i-1 的结点，采用后插法
    LNode* tmp_pre = head;
    LNode* tmp = tmp_pre->next;
    // pos 为 0 代表头结点
    int pos = 1;
    // *** ListInset 遍历链表 ***
    while(pos < i && tmp != head)
    {
        tmp_pre = tmp;
        tmp = tmp->next;
        pos++;
    }

    // 
    if(pos != i)
    {
        cout << "在链表中第" << i << "个位置插入 " << e << " ,插入失败" << endl;
        return false;
    }

    //新增结点，然后修改指针域
    LNode* node = (LNode*)malloc(sizeof(LNode));
    if(node == nullptr)
    {
        cout << "创建结点失败" << endl;
        return false;
    }
    node->data = e;
    node->next = tmp_pre->next;
    tmp_pre->next = node;

    cout <<"在位置" << i <<"插入数据:" << e <<"成功" << endl;
    return true;
}

#endif //CIRCLE_LIST_H