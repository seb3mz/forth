#ifndef LIST_WITH_NO_HEAD_NODE
#define LIST_WITH_NO_HEAD_NODE
#include <iostream>
using namespace std;

template<typename T>
class LinkList
{
public:
    struct LNode
    {
        T data;
        struct LNode* next;
    };
    LinkList(){}
    ~LinkList(){}

    //获取头结点，测试使用
    LNode*& GetFirstNode() const
    {
        return firstNode;
    }

    LNode*& GetFirstNode()
    {
        return firstNode;
    }

    //1.初始化链表
    bool InitList();

    //2.判断空表
    bool Empty() const;

    //3.求链表长度
    int Length() const;

    //4.打印链表
    void PrintList() const;

    //5.按位序查找结点
    LNode* GetElem(int i) const;

    //6.按值查找结点
    LNode* LocateElem(int e) const;

    // 链表的插入操作
    //7.在链表位序 i 处插入值 e
    bool ListInsert(int i, int e);

private:
    LNode* firstNode;
};

//1.初始化链表
template<typename T>
bool LinkList<T>::InitList()
{
    firstNode = nullptr;
    return true;
}

//2.判断空表
template<typename T>
bool LinkList<T>::Empty() const
{
    return firstNode == nullptr;
}

//3.求链表长度
template<typename T>
int LinkList<T>::Length() const
{
    LNode* cur = firstNode;
    int len = 0;
    while(cur)
    {
        len++;
        cur = cur->next;
    }

    return len;
}

//4.打印链表
template<typename T>
void LinkList<T>::PrintList() const
{
    LNode* cur = firstNode;
    while(cur)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

//5.按位序查找结点
template<typename T>
typename LinkList<T>::LNode* LinkList<T>::GetElem(int i) const
{
    LNode* tmp = firstNode;
    int pos = 1;
    while(tmp && pos < i)
    {
        tmp = tmp->next;
        pos++;
    }

    return tmp;
}

//6.按值查找结点
template<typename T>
typename LinkList<T>::LNode* LinkList<T>::LocateElem(int e) const
{
    LNode* tmp = firstNode;
    while(tmp && tmp->data != e)
    {
        tmp = tmp->next;
    }

    return tmp;
}

//7.在链表位序 i 处插入值 e
template<typename T>
bool LinkList<T>::ListInsert(int i, int e)
{
    //无头结点的链表，当 i 为 1 时，特殊处理
    if(i == 1)
    {
        LNode* node = (LNode*)malloc(sizeof(LNode));
        if(node == nullptr)
        {
            cout << "创建结点失败" << endl;
            return false;
        }
        node->data = e;
        if(firstNode)
        {
            node->next = firstNode;
        }
        else
        {
            node->next = nullptr;
        }
        
        firstNode = node;
        return true;
    }
    //插入其他位序的结点
    int pos = 1;
    LNode* tmpNode = firstNode;
    while(tmpNode && pos < i-1)
    {
        tmpNode = tmpNode->next;
        pos++;
    }

    //
    if(tmpNode == nullptr)
    {
        cout << "插入无头结点链表失败" << endl;
        return false;
    }

    LNode* node = (LNode*)malloc(sizeof(LNode));
    if(node == nullptr)
    {
        cout << "创建结点失败" << endl;
        return false;
    }

    node->data = e;
    node->next = tmpNode->next;
    tmpNode->next = node;

    return true;
}
#endif //LIST_WITH_NO_HEAD_NODE
