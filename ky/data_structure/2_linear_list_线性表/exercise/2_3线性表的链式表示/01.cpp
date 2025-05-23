#include <iostream>
#include "../../22_list_单链表/221_list_单链表.h"
using namespace std;
using LNode=LinkList<int>::LNode;

/*
    功能:在单链表中删除值为 x 的结点
    输入:
        LinkList<int>& L:待操作的单链表
        int x:
    输出:
        int:被删除 x 的个数
    分析思路:
       遍历顺序表，把元素与x比对，若相等则删除;若不等，继续向后遍历
    实现细节:
        定义 LNode* cur 表示当前指针指向的位置的元素
        定义 LNode* pre 表示前驱结点元素，以便在遇到 x 后更改指针域使用
    注意点:
        a. 单链表为空的情况
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

int DeleteX(LinkList<int>& L, int x)
{
    if(L.Empty())
    {
        cout << "表空" << endl;
        return 0;
    }
    int cnt = 0;
    LNode* pre = L.GetHeadNode();
    LNode* cur = pre->next;
    while(cur != nullptr)
    {
        //当遇到 x 时，需要修改 pre 指针next域指向，释放 cur 所指结点，并且移动 cur 到下一结点
        if(cur->data == x)
        {
            cnt++;
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }  
    }
    return cnt;
}

int main()
{
    // // 保存原来的缓冲区
    // std::streambuf* original_buf = std::cout.rdbuf();

    // // 关闭输出：将缓冲区设为 nullptr
    // std::cout.rdbuf(nullptr);
    LinkList<int> L;
    L.InitList();
    L.ListInsert(1, 1);
    L.ListInsert(2, 2);
    L.ListInsert(3, 3);
    L.ListInsert(4, 4);
    L.ListInsert(5, 3);
    L.PrintList();

    cout << "元素3有 " << DeleteX(L, 3) << "个" << endl;
    L.PrintList();
    
    // std::cout.rdbuf(original_buf);
    // std::cout << "正常输出" << std::endl; // 恢复输出
    return 0;
}