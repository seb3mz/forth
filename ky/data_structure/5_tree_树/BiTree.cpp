#include <iostream>
using namespace std;



void Visit(BiTNode* node)
{
    cout << "结点数据:" << node->data << endl;
}
// 先序遍历
void PreOrder(BiTree T)
{
    if(T != nullptr)
    {
        Visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 中序遍历递归版本
void InOrder(BiTree T)
{
    if(T != nullptr)
    {
        InOrder(T->lchild);
        Visit(T);
        InOrder(T->rchild);
    }
}

// 中序遍历非递归版本
void InOrder2(BiTree T)
{
    BiTNode * tmp = T;
    Stack s;
    while(tmp)
    {
        if(tmp->lchild)
        {
            s.push(tmp);
            tmp = tmp->lchild;
        }
        else
        {
            BiTNode* node = s.pop();
            Visit(node);
            s.push(tmp->rchild);
            tmp = tmp->rchild;
        }
    }
}

// 后序遍历
void PostOrder(BiTree T)
{
    if(T != nullptr)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        Visit(T);
    }
}

int main()
{
    return 0;
}