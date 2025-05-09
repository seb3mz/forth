//循环双链表

typedef struct DNode
{
    int data;
    DNode *prior, *next;
}DNode, *DLinkList;

//初始化链表
bool InitList(DLinkList &L);

//判断空表
bool Empty(const DLinkList& L);