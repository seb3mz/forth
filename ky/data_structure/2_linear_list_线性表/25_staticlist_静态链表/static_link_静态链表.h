//静态链表

#define MaxSize 50

typedef struct
{
    int data;
    int next;
}SLinkList[MaxSize];

//初始化链表
bool InitList(SLinkList &L);

//判断空表
bool Empty(const SLinkList& L);

//求链表长度
int Length(const SLinkList& L);

//打印链表
void PrintList(const SLinkList &L);

// 链表的插入操作
//在链表位序 i 处插入值 e
bool ListInsert(SLinkList &L, int i, int e);

// 链表的删除操作
//删除链表中第 i 处的元素，并用 e 返回
bool ListDelete(SLinkList &L, int i, int e);