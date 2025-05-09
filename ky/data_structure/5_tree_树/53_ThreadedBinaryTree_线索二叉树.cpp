#include "53_ThreadedBinaryTree_线索二叉树.h"
#include <iostream>
using namespace std;
/*
    ************************************************************************************************************************************************************************************
    ************************************************************************************************************************************************************************************
    线索化中序二叉树
*/

ThreadNode* pre = nullptr;
void InClueOperation(ThreadNode* node)
{
    if(node->lchild == nullptr)
    {
        node->lchild = pre;
        node->ltag = 1;
    }
    if(pre != nullptr && pre->rchild == nullptr)
    {
        pre->rchild = node;
        pre->rtag = 1;
    }
    pre = node;
}

void VistInThread(ThreadNode* node)
{
    if(node != nullptr)
    {
        VistInThread(node->lchild);
        InClueOperation(node);
        VistInThread(node->rchild);
    }
}
//中序线索化
void CreateInThread(ThreadTree T)
{
    if(T != nullptr)
    {
        VistInThread(T);
        if(pre->rchild == nullptr)
        {
            pre->rtag = 1;
        }
    }
}

/*
    ************************************************************************************************************************************************************************************
    ************************************************************************************************************************************************************************************
    正向遍历中序线索二叉树
*/
//查找中序遍历(左、根、右)中以 p 为根的子树中，第一个被中序遍历的结点
//若结点 p->ltag = 0, 表示有左孩子,找到左孩子中第一个被访问的结点,即最左下的孩子结点
//若结点 p->ltag = 1, 表示 p 没有左孩子,则 p 是第一个被访问的结点
ThreadNode* FirstInNode(ThreadNode* p)
{
    ThreadNode* first = p;
    if(first->ltag == 1)
    {
        return p;
    }
    else
    {
        while(first->ltag == 0)
        {
            first = first->lchild;
        }
        return first;
    }
}

//查找中序遍历(左、根、右)以 p 的后继结点
//若结点 p->rtag = 0, 表示有右孩子,找到右孩子中第一个被访问的结点,即最左下的孩子结点
//若结点 p->rtag = 1, 表示 p 没有左孩子,则 p 是第一个被访问的结点
ThreadNode* NextInNode(ThreadNode* p)
{
    ThreadNode* first = p;
    if(first->rtag == 1)
    {
        return first->rchild;
    }
    else
    {
        return FirstInNode(first->rchild);
    }
}

//非递归算法实现中序遍历线索二叉树，空间复杂度 O(1) 
void InOrder(ThreadNode* T)
{
    for(ThreadNode* p = FirstInNode(T); p != nullptr; p = NextInNode(p))
    {
        cout << p->data << " ";
    }
}

/*
    ************************************************************************************************************************************************************************************
    ************************************************************************************************************************************************************************************
    逆向遍历中序线索二叉树
*/
//找到以 p 为根的子树中，最后一个被中序遍历(左、根、右)的结点
//若结点 p->rtag = 0, 表示有右孩子,找到右孩子中最后一个被访问的结点,即最右下的孩子结点
//若结点 p->rtag = 1, 表示 p 没有右孩子,则 p 是最后一个被访问的结点
ThreadNode* LastInNode(ThreadNode* p)
{
    ThreadNode* first = p;
    if(first->rtag == 1)
    {
        return p;
    }
    else
    {
        while(first->rtag == 0)
        {
            first = first->rchild;
        }
        return first;
    }
}

//查找中序遍历(左、根、右)中以 p 的前驱结点
//若结点 p->ltag = 0, 表示有左孩子,找到左孩子中最后一个被访问的结点,即最右下的孩子结点
//若结点 p->ltag = 1, 表示 p 没有左孩子,则 p 的左指针指向其前驱结点
ThreadNode* PreInNode(ThreadNode* p)
{
    if(p->ltag == 1)
    {
        return p->lchild;
    }
    else
    {
        return LastInNode(p->lchild);
    }
}
// 逆向中序遍历
void RevInorder(ThreadNode* T)
{
    for(ThreadNode* p = LastInNode(T); p != nullptr; p = PreInNode(p))
    {
        cout << p->data << " ";
    }
}

/*
    ************************************************************************************************************************************************************************************
    ************************************************************************************************************************************************************************************
    线索化先序线索二叉树
*/
// 先序
void PreClueOperation(ThreadNode* node)
{
    if(node->lchild == nullptr)
    {
        node->lchild = pre;
        node->ltag = 1;
    }
    if(pre != nullptr && pre->rchild == nullptr)
    {
        pre->rchild = node;
        pre->rtag = 1;
    }
    pre = node;
}

void VistPreThread(ThreadNode* node)
{
    if(node != nullptr)
    {
        PreClueOperation(node);
        if(node->lchild == 0)
        {
            VistPreThread(node->lchild);
        }
        VistPreThread(node->rchild);
    }
}
//先序线索化
void CreatePreThread(ThreadTree T)
{
    if(T != nullptr)
    {
        VistPreThread(T);
        if(pre->rchild == nullptr)
        {
            pre->rtag = 1;
        }
    }
}

/*
    ************************************************************************************************************************************************************************************
    ************************************************************************************************************************************************************************************
    正向遍历先序线索二叉树
*/
//查找先序遍历(根、左、右)中以 p 为根的子树中，第一个被先序遍历的结点
//以 p 为根的子树，p 是第一个被先序遍历的结点
ThreadNode* FirstPreNode(ThreadNode* p)
{
    return p;
}

//查找先序遍历(根、左、右)中，p 的后继结点
//若结点 p->rtag=1, 则 p 的右孩子指针指向的结点为 p 的后继结点
//若结点 p->rtag=0, 则 p 有右孩子，此时需要判断是否有左孩子
//                  若有左孩子(p->ltag=0)，则 p 的后继结点为左孩子
//                  若没有左孩子(p->ltag=1)，则 p 的后继结点为右孩子
ThreadNode* NextPreNode(ThreadNode* p)
{
    if(p->rtag == 1)
    {
        return p->rchild;
    }
    else
    {
        if(p->ltag == 0)
        {
            return p->lchild;
        }
        else
        {
            return p->rchild;
        }
    }
}

void PreOrder(ThreadNode* T)
{
    for(ThreadNode* p = FirstPreNode(T); p != nullptr; p = NextPreNode(p))
    {
        cout << p->data << " ";
    }
}

/*
    ************************************************************************************************************************************************************************************
    ************************************************************************************************************************************************************************************
    逆向遍历先序线索二叉树
*/
//以 p 为根节点的子树中最后一个被访问的结点
ThreadNode* LastPreNode(ThreadNode* p)
{

}

//先序遍历(根、左、右)中, 查找 p 的前驱结点
//若 p->ltag = 1, p 的前驱结点是左孩子指针指向的结点
//若 p->ltag = 0, 无法直接找到 p 的前驱结点，需要三叉链表
//  ① 如果能找到 p 的父结点, 且 p 是左孩子，则 p 的父结点是其前驱结点
//  ② 如果能找到 p 的父结点, 且 p 是右孩子，且其左兄弟为空，则 p 的父结点是其前驱结点
//  ③ 如果能找到 p 的父结点, 且 p 是右孩子，且其左兄弟不为空，则 p 前驱结点为 p 的左兄弟的最后一个被访问的结点
//  ④ 如果 p 是根结点，则 p 没有先序前驱结点
ThreadNode* PrePreNode(ThreadNode* p)
{

}

void RevPreorder(ThreadNode* T)
{

}

/*
    ************************************************************************************************************************************************************************************
    ************************************************************************************************************************************************************************************
    线索化后序线索二叉树
*/
void PostClueOperation(ThreadNode* node)
{
    if(node->lchild == nullptr)
    {
        node->lchild = pre;
        node->ltag = 1;
    }
    if(pre != nullptr && pre->rchild == nullptr)
    {
        pre->rchild = node;
        pre->rtag = 1;
    }
    pre = node;
}

void VistPostThread(ThreadNode* node)
{
    if(node != nullptr)
    {
        VistPostThread(node->lchild);
        VistPostThread(node->rchild);
        PostClueOperation(node);
    }
}
//后序线索化
void CreatePostThread(ThreadTree T)
{
    if(T != nullptr)
    {
        VistPostThread(T);
        if(pre->rchild == nullptr)
        {
            pre->rtag = 1;
        }
    }
}

/*
    ************************************************************************************************************************************************************************************
    ************************************************************************************************************************************************************************************
    正向遍历先序线索二叉树
*/
//后序(左、右、根)后继
//若 p->rtag=1, 则 p 的后继结点为其右孩子指针指向的结点
//若 p->rtag=0, 则 p 有右孩子, p 作为根结点, 无法直接找到其后继结点, 需要借助三叉链表
//              ① 如果能找到 p 的父结点, 且 p 是右孩子, p 的后继结点是其父结点
//              ② 如果能找到 p 的父结点, 且 p 是左孩子，其右兄弟为空，则p 的后继结点是其父结点
//              ③ 如果能找到 p 的父结点, 且 p 是左孩子，其右兄弟不空，则p 的后继结点是其右兄弟中第一个被访问的结点
//              ④ 如果 p 是根结点，则 p 没有后继结点
ThreadNode* FirstPostNode(ThreadNode* p);
ThreadNode* NextPostNode(ThreadNode* p);
void PostOrder(ThreadNode* T);

//后序前驱
ThreadNode* LastPostNode(ThreadNode* p);

//后序(左、右、根)线索二叉树, 找 p 的前驱
//若 p->ltag = 1, 则 p->lchild 为其前驱
//若 p->ltag = 0, 则其必有左孩子
//          若其有右孩子, 则其前驱为右孩子
//          若其没有右孩子, 则其前驱为左孩子
ThreadNode* PrePostNode(ThreadNode* p)
{

}
void RevPostorder(ThreadNode* T);

int main()
{
    return 0;
}