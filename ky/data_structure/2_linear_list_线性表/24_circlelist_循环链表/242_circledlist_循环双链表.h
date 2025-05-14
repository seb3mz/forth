//循环双链表
#ifndef D_CIRCLE_LIST
#define D_CIRCLE_LIST

#include <iostream>
using namespace std;

template<typename T>
class DlinkList
{
public:
    struct DNode
    {
        T data;
        DNode *prior, *next;
    };

    DlinkList():head(nullptr){}
    ~DlinkList(){}

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
private:
    DNode* head;
};

//初始化链表
template<typename T>
bool DlinkList<T>::InitList()
{
    head = (DNode*)malloc(sizeof(DNode));
    if(head == nullptr)
    {
        cout << "初始化循环双链表失败" << endl;
        return false;
    }
    head->prior = head;
    head->next = head;
    return true;
}

//判断空表
template<typename T>
bool  DlinkList<T>::Empty() const
{
    if(head == nullptr)
    {
        cout << "链表未初始化";
        return false;
    }

    return (head->prior == head && head->next == head);
}

//打印链表
 template<typename T>
void  DlinkList<T>::PrintList() const
{
    if(Empty())
    {
        return;
    }
    DNode* cur = head->next;
    while(cur!=head)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

//插入结点
template<typename T>
bool  DlinkList<T>::ListInsert(int i, int e)
{
    // 判断插入位置是否合法
    if(i < 1)
    {
        cout << "插入未知为 " << i << " 不合法，插入失败" << endl;
        return false;
    }

    //插入位序为 i，先找到位置为 i 的结点，采用前插法
    DNode* tmp = head->next;
    // pos 为 0 代表头结点
    int pos = 1;
    // *** ListInset 遍历链表 ***
    while(pos < i && tmp != head)
    {
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
    DNode* nxt = tmp;
    DNode* node = (DNode*)malloc(sizeof(DNode));
    if(node == nullptr)
    {
        cout << "创建结点失败" << endl;
        return false;
    }
    node->data = e;
    node->next = nxt;
    node->prior = nxt->prior;
    nxt->prior->next = node;
    nxt->prior = node;

    cout <<"在位置" << i <<"插入数据:" << e <<"成功" << endl;
    return true;
}

#endif //D_CIRCLE_LIST