#define MaxSize 5

typedef struct {
    int data[MaxSize];  //用静态数组存放队列元素
    int front, rear;    //队头指针和队尾指针
    int length;
} SqQueue;

//初始化队列
void InitQueue(SqQueue& Q);

//销毁队列
void DestroyQueue(SqQueue& Q);

//入队
bool EnQueue(SqQueue& Q, int e);

//出队
bool DeQueue(SqQueue& Q, int &e);

//获取队首元素
bool GetHead(const SqQueue& Q, int &e);

//判断队空
bool QueueEmpty(const SqQueue& Q);