
typedef struct BSTNode {
    int key;
    struct BSTNode *lchild, *rchild;
    int balance;
}BSTNode, *BSTree;