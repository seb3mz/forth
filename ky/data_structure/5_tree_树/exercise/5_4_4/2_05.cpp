#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

typedef struct CSNode {
    char data;
    struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;

/*
    功能:递归求孩子兄弟表示法存储的树的深度
    输入:
        CSTree:
    输出:
        int:
    分析思路:
        
    实现细节:
        
    注意点:
    时间复杂度:
            
    空间复杂度:
        
*/

void Depth(CSNode* node)
{
    cout << node->data << " ";
}

int DepthOfTree(CSTree tree)
{
    if(tree)
    {
        Depth(tree);
        int DepthLeft = DepthOfTree(tree->firstchild)+1;
        int DepthRight = DepthOfTree(tree->nextsibling)+1;
        DepthRight--;
        return (DepthLeft>DepthRight)?DepthLeft:DepthRight;
    }
    else
    {
        return 0;
    }
}

int main()
{
    CSNode* A = new CSNode();
    CSNode* B = new CSNode();
    CSNode* C = new CSNode();
    CSNode* D = new CSNode();
    CSNode* E = new CSNode();
    CSNode* F = new CSNode();
    CSNode* G = new CSNode();
    CSNode* H = new CSNode();
    CSNode* I = new CSNode();
    CSNode* J = new CSNode();
    CSNode* K = new CSNode();
    CSNode* L = new CSNode();
    CSNode* M = new CSNode();
    A->data = 'A';
    A->firstchild = B;
    A->nextsibling = nullptr;
    B->data = 'B';
    B->firstchild = D;
    B->nextsibling = E;
    C->data = 'C';
    C->firstchild = F;
    C->nextsibling = G;
    D->data = 'D';
    D->firstchild = nullptr;
    D->nextsibling = nullptr;
    E->data = 'E';
    E->firstchild = H;
    E->nextsibling = nullptr;
    F->data = 'F';
    F->firstchild = I;
    F->nextsibling = nullptr;
    G->data = 'G';
    G->firstchild = nullptr;
    G->nextsibling =  J;
    H->data = 'H';
    H->firstchild = nullptr;
    H->nextsibling = nullptr;
    I->data = 'I';
    I->firstchild = nullptr;
    I->nextsibling = M;
    J->data = 'J';
    J->firstchild = K;
    J->nextsibling = nullptr;
    K->data = 'K';
    K->firstchild = nullptr;
    K->nextsibling = L;
    L->data = 'L';
    L->firstchild = nullptr;
    L->nextsibling = nullptr;
    M->data = 'M';
    M->firstchild = nullptr;
    M->nextsibling = nullptr;

    cout << DepthOfTree(A) << endl;
    return 0;
}