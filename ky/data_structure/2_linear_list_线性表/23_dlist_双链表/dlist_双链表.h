
//双链表
typedef struct DNode
{
    int data;
    DNode *prior, *next;
}DNode, *DLinkList;

//初始化双链表
bool InitDLinkList(DLinkList &L);

//打印双链表
void PrintDList(const DLinkList &L);

//链表长度
int Length(const DLinkList &L);

//在结点 p 后插入结点 s
bool InsertNextDNode(DNode* p, DNode* s);

//删除 p 的后继结点
bool DeleteNextNode(DNode* p);

//销毁双链表
void DestoryList(DLinkList& L);

//打印
