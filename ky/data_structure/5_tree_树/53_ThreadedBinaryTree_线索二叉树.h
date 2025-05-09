typedef struct ThreadNode {
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; //左右线索标志，为0表示指向孩子;为1表示是线索
}ThreadNode, *ThreadTree;

//线索化中序二叉树
void InClueOperation(ThreadNode* node);
void VistInThread(ThreadNode* node);
void CreateInThread(ThreadTree T);
//中序后继
ThreadNode* FirstInNode(ThreadNode* p);
ThreadNode* NextInNode(ThreadNode* p);
void InOrder(ThreadNode* T);
//中序前驱
ThreadNode* LastInNode(ThreadNode* p);
ThreadNode* PreInNode(ThreadNode* p);
void RevInorder(ThreadNode* T);


//线索化前序二叉树
void PreClueOperation(ThreadNode* node);
void VistPreThread(ThreadNode* node);
void CreatePreThread(ThreadTree T);
//先序后继
ThreadNode* FirstPreNode(ThreadNode* p);
ThreadNode* NextPreNode(ThreadNode* p);
void PreOrder(ThreadNode* T);
//先序前驱
ThreadNode* LastPreNode(ThreadNode* p);
ThreadNode* PrePreNode(ThreadNode* p);
void RevPreorder(ThreadNode* T);

//线索化后序二叉树
void PostClueOperation(ThreadNode* node);
void VistPostThread(ThreadNode* node);
void CreatePostThread(ThreadTree T);
//后序后继
ThreadNode* FirstPostNode(ThreadNode* p);
ThreadNode* NextPostNode(ThreadNode* p);
void PostOrder(ThreadNode* T);
//后序前驱
ThreadNode* LastPostNode(ThreadNode* p);
ThreadNode* PrePostNode(ThreadNode* p);
void RevPostorder(ThreadNode* T);