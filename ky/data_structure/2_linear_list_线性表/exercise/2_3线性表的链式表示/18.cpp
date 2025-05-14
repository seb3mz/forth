#include <iostream>
#include "../../22_list_单链表/221_list_单链表.h"
using namespace std;
using LNode = LinkList<int>::LNode;

/*
    功能: 查找带头结点的两个单链表的共享结点的起始结点
    输入:
        LinkList<char>& str1:
        LinkList<char>& str2:
    输出:
        LNode*: 
    分析思路:
        如果 str1 和 str2 有共享结点，则它俩的尾结点一定是共享的
        先找到它俩尾结点，若一样，则继续查找上一个结点，直到两个结点不同
    实现细节:
        定义 LNode* str1_end 表示最后一个结点 LNode* str1_pre 表示倒数第二个结点
        定义 LNode* str2_end 表示最后一个结点 LNode* str2_pre 表示倒数第二个结点
        先比较 str1_end 是否域 str2_end 相等，若想等，继续比较 str1_pre 和 str2_pre，并且找到 str1_pre 和 str2_pre 的前驱结点
        直到不相等
    注意点:
        
    时间复杂度:
            假设 str1 长度为 n，str2 长度为 m
            共 m+n+(m-1)+(n-1)+(m-2)+(n-2) m*m+n*n
    空间复杂度:
            O(max(m, n))
*/

LinkList<int> str1;
LinkList<int> str2;

LNode* CompareNode(LNode* str1_node, LNode* str2_node)
{
    //出现第一个不相等的结点
    if(str1_node != str2_node)
    {
        return str1_node->next;
    }
    //相等的话，继续比较上一个结点
    else
    {
        LNode* str1_pre = nullptr;
        LNode* str1_tmp = str1.GetHeadNode();
        LNode* str2_pre = nullptr;
        LNode* str2_tmp = str2.GetHeadNode();

        while(str1_tmp != str1_node)
        {
            str1_pre = str1_tmp;
            str1_tmp = str1_tmp->next;
        }

        while(str2_tmp != str2_node)
        {
            str2_pre = str2_tmp;
            str2_tmp = str2_tmp->next;
        }

        return CompareNode(str1_pre, str2_pre);
    }
}

LNode* FindSharedNode()
{
    if(str1.Empty() || str2.Empty())
    {
        return 0;
    }

    LNode* str1_end = str1.GetHeadNode();
    LNode* str1_pre = nullptr;
    LNode* str2_end = str2.GetHeadNode();
    LNode* str2_pre = nullptr;

    while(str1_end)
    {
        str1_pre = str1_end;
        str1_end = str1_end->next;
    }

    while(str2_end)
    {
        str2_pre = str2_end;
        str2_end = str2_end->next;
    }

    //从最后一个结点开始
    return CompareNode(str1_pre, str2_pre);
}

int main()
{
    // 保存原来的缓冲区
    std::streambuf* original_buf = std::cout.rdbuf();

    // 关闭输出：将缓冲区设为 nullptr
    std::cout.rdbuf(nullptr);
    str1.InitList();
    str2.InitList();

    // str1.ListInsert(1, 1);
    // str1.ListInsert(2, 2);
    // str1.ListInsert(3, 3);

    // str2.ListInsert(1, 11);
    // str2.ListInsert(2, 22);
    // str2.ListInsert(3, 33);

    LNode* common1 = (LNode*)malloc(sizeof(LNode));
    common1->data = 30303;
    common1->next = nullptr;

    LNode* str1_3th = str1.GetHeadNode();
    str1_3th->next = common1;
    LNode* str2_3th = str2.GetHeadNode();
    str2_3th->next = common1;

    std::cout.rdbuf(original_buf);
    std::cout << "正常输出" << std::endl; // 恢复输出

    str1.PrintList();
    str2.PrintList();
    if(FindSharedNode())
    {
        cout << "找到共同结点" << endl;
    }
    else
    {
        cout << "没有找到共同结点" << endl;
    }

    return 0;
}