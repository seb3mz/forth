#include <iostream>
using namespace std;

typedef struct BSTNode {
    int key;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

//BST 搜索
BSTNode* BST_Search(BSTree T, int key)
{
    BSTNode* cur = T;
    while(cur)
    {
        if(key == cur->key)
        {
            break;
        }
        else if(key > cur->key)
        {
            cur = cur->rchild;
        }
        else if(key < cur->key)
        {
            cur = cur->lchild;
        }
    }
    return cur;
}

//BST 递归搜索
BSTNode* BST_Search_rec(BSTree T, int key)
{
    if(T == nullptr)
    {
        return T;
    }
    if(T->key == key)
    {
        return T;
    }
    else if(T->key > key)
    {
        return BST_Search_rec(T->lchild, key);
    }
    else
    {
        return BST_Search_rec(T->rchild, key);
    }
}

//BST 插入
int BST_Insert(BSTree T, int key)
{
    if(T == nullptr)
    {
        T = (BSTNode*)malloc(sizeof(BSTNode));
        T->key = key;
        T->lchild = nullptr;
        T->rchild = nullptr;
        return 1;
    }

    BSTNode* cur = T;
    BSTNode* pre = nullptr;
    bool lchild = true;
    while(cur)
    {
        if(cur->key == key)
        {
            return 0;
        }

        if(cur->key > key)
        {
            pre = cur;
            cur = cur->lchild;
            lchild = true;
        }
        else
        {
            pre = cur;
            cur = cur->rchild;
            lchild = false;
        }
    }

    BSTNode* insert_node = (BSTNode*)malloc(sizeof(BSTNode));
    insert_node->key = key;
    insert_node->lchild = nullptr;
    insert_node->rchild = nullptr;
        return 1;
    if(lchild)
    {
        pre->lchild = insert_node;
    }
    else
    {
        pre->rchild = insert_node;
    }
}

//BST 递归插入
int BST_Insert_rec(BSTree &T, int key)
{
    if(T == nullptr)
    {
        T = (BSTNode*)malloc(sizeof(BSTNode));
        T->key = key;
        T->lchild = nullptr;
        T->rchild = nullptr;
        return 1;
    }

    if(T->key > key)
    {
        return BST_Insert_rec(T->lchild, key);
    }
    else
    {
        return BST_Insert_rec(T->rchild, key);
    }
}

//创建二叉排序树 BST
void BST_Create(BSTree &T, int key[], int n)
{
    T = nullptr;
    int i = 0;
    while(i < n)
    {
        BST_Insert(T, key[i]);
        i++;
    }
}

int main()
{
    return 0;
}