//循环单链表
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, *LinkList;

//初始化链表
bool InitList(LinkList &L);

//判断空表
bool Empty(const LinkList& L);