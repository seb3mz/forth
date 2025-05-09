typedef struct Linknode
{
    int data;
    struct Linknode *next;
}*LiStack;

//初始化栈
bool InitStack(LiStack& S);

//判断栈空
bool StackEmpty(const LiStack& S);

//入栈
bool Push(LiStack& S, int e);

//出栈
bool Pop(LiStack& S, int &e);

//获取栈顶元素
bool GetTop(const LiStack &s, int &e);