#ifndef D_LIST
#define D_LIST
#include <iostream>
using namespace std;
//双链表
template<typename T>
class DLinkList
{
public: 
    struct DNode
    {
        T data;
        DNode *pre, *next;
        int freq;   //访问频率
    };
    DLinkList():head(nullptr){}
    ~DLinkList(){}
    //获取头结点，测试使用
    DNode* GetHeadNode()
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

    //6.按值查找结点
    DNode* LocateElem(int e) const;

private:
    DNode* head;
};

//初始化链表
template<typename T>
bool DLinkList<T>::InitList()
{
    head = (DNode*)malloc(sizeof(DNode));
    if(head == nullptr)
    {
        cout << "分配头结点失败" << endl;
        return false;
    }

    head->pre = nullptr;
    head->next = nullptr;
    head->freq = -1;
    return true;
}

//判断空表
template<typename T>
bool DLinkList<T>::Empty() const
{
    if(head == nullptr)
    {
        cout << "未构造的单链表" << endl;
        return true;
    }
    return head->next == nullptr;
}

//打印链表
template<typename T>
void DLinkList<T>::PrintList() const
{
    if(head == nullptr)
    {
        cout << "未构造的单链表" << endl;
        return;
    }

    DNode * tmp = head->next;
    while(tmp)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

//插入结点
template<typename T>
bool DLinkList<T>::ListInsert(int i, int e)
{
    // 判断插入位置是否合法
    if(i < 1)
    {
        cout << "插入未知为 " << i << " 不合法，插入失败" << endl;
        return false;
    }
    //插入位序为 i，先找到位置为 i-1 的结点
    DNode* tmp = head;
    // pos 为 0 代表头结点
    int pos = 0;
    // *** ListInset 遍历链表 ***
    while(tmp && pos < i-1)
    {
        tmp = tmp->next;
        pos++;
    }

    if(tmp == nullptr)
    {
        cout << "要在链表中第" << i << "个位置插入 " << e << " ,插入失败" << endl;
        return false;
    }

    //新增结点，然后修改指针域
    DNode* prev = tmp;
    DNode* node = (DNode*)malloc(sizeof(DNode));
    if(node == nullptr)
    {
        cout << "创建结点失败" << endl;
        return false;
    }
    node->data = e;
    node->freq = 0;
    
    node->next = prev->next;
    node->pre = prev;
    prev->next = node;
    if(node->next != nullptr)
    {
        node->next->pre = node;
    }

    return true;
}

//6.按值查找结点
template<typename T>
typename DLinkList<T>::DNode* DLinkList<T>::LocateElem(int e) const
{
    if(head == nullptr)
    {
        cout << "双链表未初始化" << endl;
        return nullptr;
    }
    DNode* tmp = head->next;
    while(tmp && tmp->data != e)
    {
        tmp = tmp->next;
    }

    if(tmp == nullptr)
    {
        cout << "未查到值为 " << e << " 的结点" << endl;
    }

    return tmp;
}

#endif
