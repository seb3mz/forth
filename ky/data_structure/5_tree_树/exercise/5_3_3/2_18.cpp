#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/32_queue_队列/321_seqqueue_顺序队列.h"
#include "/home/seb3mz/work/code/forth/ky/data_structure/3_stack_queue_栈和队列/31_stack_栈/311_seqstack_顺序栈.h"
using namespace std;

typedef struct BiTNode {
    char data;   //数据域
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

/*
    功能:将表达式树转换为等价的中缀表达式
    输入:
        BiTree:
    输出:
        string:
    分析思路:
        1) 使用中序遍历将各个结点的值串起来
        2) 当遇到只有左子树为空，右子树不为空的情况时
            2.1 如果此时栈中还有数据，则记录栈顶数据，并在下一次弹出该栈顶数据前加 ")"
            2.2 如果此时栈中没有数据，则直到栈内元素都为空时，加 ")"
        3) 当遇到左右子树都为空的结点时
            3.1 若该结点为左子树，则加 "("
            3.2 若该结点为右子树，则加 ")"
            
    实现细节:
    注意点:
    时间复杂度:
            
    空间复杂度:
            
*/

string ConvertExpressionTreeToInfixExpression(BiTree root)
{
    SeqStack<BiTNode*> sq;
    BiTNode* p = root;
    bool firstHasOnlyRchild = false;
    BiTNode* preSingleAnc = nullptr;
    BiTNode* preSingleAnc_tmp = nullptr;
    BiTNode* prePushNode = nullptr;
    BiTNode* prePopNode = nullptr;
    string result;

    while(p || !sq.StackEmpty())
    {
        if(p)
        {
            //左子树为空，右子树不空，找到栈顶元素，当弹出p子树的最后一个元素时与该栈顶进行比对后，添 ')'
            if(p->lchild == nullptr && p->rchild != nullptr)
            {
                result += '(';
                //2.1 记录当前栈顶元素
                if(p != root)
                {
                    firstHasOnlyRchild = true;
                }
                
                if(!sq.GetTop(preSingleAnc))
                {
                    preSingleAnc = nullptr;
                }
            }

            sq.Push(p);
            //3.1 左右子树都为空的结点，并且该结点为左子树
            if((prePushNode==nullptr || prePushNode->lchild == p) && p->lchild == nullptr && p->rchild == nullptr)
            {
                result += '(';
            }
            prePushNode = p;
            p = p->lchild;
        }
        else
        {
            sq.Pop(p);
            result += p->data;
            //3.2 左右子树都为空的结点，并且该结点为右子树
            if(prePopNode != nullptr && prePopNode->rchild == p && p->lchild == nullptr && p->rchild == nullptr)
            {
                result += ')';
                if(!sq.GetTop(preSingleAnc_tmp))
                {
                    preSingleAnc_tmp = nullptr;
                }
                //2.1 + 2.2
                if(firstHasOnlyRchild && preSingleAnc_tmp == preSingleAnc)
                {
                    result += ')';
                    firstHasOnlyRchild = false;
                }
            }
            prePopNode = p;
            p = p->rchild;
        }
    }

    return result;
}

int main()
{
    BiTNode* node_a = new BiTNode();
    node_a->data = '*';
    BiTNode* node_al = new BiTNode();
    node_al->data = '+';
    BiTNode* node_ar = new BiTNode();
    node_ar->data = '*';
    BiTNode* node_al_al = new BiTNode();
    node_al_al->data = 'a';
    BiTNode* node_al_ar = new BiTNode();
    node_al_ar->data = 'b';
    BiTNode* node_ar_al = new BiTNode();
    node_ar_al->data = 'c';
    BiTNode* node_ar_ar = new BiTNode();
    node_ar_ar->data = '-';
    BiTNode* node_ar_ar_ar = new BiTNode();
    node_ar_ar_ar->data = 'd';

    node_a->lchild = node_al;
    node_a->rchild = node_ar;

    node_al->lchild = node_al_al;
    node_al->rchild = node_al_ar;

    node_ar->lchild = node_ar_al;
    node_ar->rchild = node_ar_ar;

    node_al_al->lchild = nullptr;
    node_al_al->rchild = nullptr;

    node_al_ar->lchild = nullptr;
    node_al_ar->rchild = nullptr;

    node_ar_al->lchild = nullptr;
    node_ar_al->rchild = nullptr;

    node_ar_ar->lchild = nullptr;
    node_ar_ar->rchild = node_ar_ar_ar;

    node_ar_ar_ar->lchild = nullptr;
    node_ar_ar_ar->rchild = nullptr;

    cout << ConvertExpressionTreeToInfixExpression(node_ar) << endl;
    return 0;
}