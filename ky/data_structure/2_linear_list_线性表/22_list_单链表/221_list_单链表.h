#ifndef LIST_H
#define LIST_H

//单链表
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, *LinkList;

//初始化链表
bool InitList(LinkList &L);

//判断空表
bool Empty(const LinkList& L);

//求链表长度
int Length(const LinkList& L);

//打印链表
void PrintList(const LinkList& L);

//按位序查找结点
LNode* GetElem(const LinkList& L, int i);

//按值查找结点
LNode* LocateElem(const LinkList& L, int e);


// 链表的插入操作
//在链表位序 i 处插入值 e
bool ListInsert(LinkList &L, int i, int e);
//指定结点的后插操作
bool InsertNextNode(LNode* p, int e);
//指定结点的前插操作
bool InsertPriorNode_w1(LinkList& L, LNode* p, int e);
bool InsertPriorNode_w2(LinkList& L, LNode* p, int e);


// 链表的删除操作
//删除联邦中第 i 处的元素，并用 e 返回
bool ListDelete(LinkList &L, int i, int e);
//删除指定结点 p
bool DeleteNode_w1(LinkList& L, LNode* p);
bool DeleteNode_w2(LinkList& L, LNode* p);

//头插法建表
LinkList List_HeadInsert(LinkList& L);

//尾插法建表
LinkList List_TailInsert(LinkList& L);

//销毁单链表
void DestoryList(LinkList& L);

#endif  //LIST_H