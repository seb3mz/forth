#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int top0;   //0号栈顶指针
    int top1;   //1号栈顶指针
} ShStack;