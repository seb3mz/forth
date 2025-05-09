typedef struct LinkNode {
    int data;
    struct LinkNode* next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
}LinkQueue;

//初始化队列
bool InitQueue(LinkQueue& Q);

//销毁队列
void DestroyQueue(LinkQueue& Q);

//入队
bool EnQueue(LinkQueue& Q, int e);

//出队
bool DeQueue(LinkQueue& Q, int &e);

//获取队首元素
bool GetHead(const LinkQueue& Q, int &e);

//判断队空
bool QueueEmpty(const LinkQueue& Q);