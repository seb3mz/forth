typedef struct BiTNode {
    int data;   //数据域
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef struct BiThreeNode {
    int data;
    struct BiThreeNode *lchild, *rchild;
    struct BiThreeNode *parent;
}BiThreeNode, * BiThreeTree;

//初始化空二叉树
bool InitBiTree(BiTree& tree, int e);

//销毁二叉树
void DestroyBiTree(BiTree& tree);

//根据定义创建二叉树
void CreateBiTree(BiTree& tree);

//清空二叉树
void ClearBiTree(BiTree& tree);


//二叉树判空
bool BiTreeEmpty(const BiTree& tree);

//求树高度
int BiTreeDepth(const BiTree& tree);

//返回树的根节点
BiTNode* Root(const BiTree& tree);

//返回 node 的值
int Value(const BiTree& tree, BiTNode* node);

//将 value 值赋给 node
bool Assign(BiTree& tree, BiTNode* node, int value);

//若 e 是 tree 的非根结点，则返回它的双亲，否则返回 "空"
BiTNode* Parent(const BiTree& tree, BiTNode* node);

//返回 node 的左孩子;若无左孩子，则返回空
BiTNode* LeftChild(const BiTree& tree, BiTNode* node);

//返回 node 的右孩子;若无右孩子，则返回空
BiTNode* RightChild(const BiTree& tree, BiTNode* node);

//返回 node 的左兄弟，否则返回空
BiTNode* LeftSibling(const BiTree& tree, BiTNode* node);

//返回 node 的右兄弟，否则返回空
BiTNode* RightSibling(const BiTree& tree, BiTNode* node);

//
bool InsertChild(BiTree& tree, BiTNode* node, bool LR, BiTree& ctree);


void DeleteChild(BiTree& tree, BiTNode* pnode, bool LR);

//先序遍历,第一次路过时访问
void PreOrderTraverse(BiTree tree);

//中序遍历,第二次路过时访问
void InOrderTraverse(BiTree tree);

//后序遍历,第三次路过时访问
void PostOrderTraverse(BiTree tree);

//层序遍历二叉树
void LevelOrderTraverse(BiTree tree);

//非递归先序遍历
void NonRecursiveSequentialTraversalBT(BiTree tree);

//非递归中序遍历

//非递归后序遍历
// 习题 2_05