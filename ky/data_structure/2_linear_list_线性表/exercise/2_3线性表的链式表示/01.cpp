#include <iostream>
#include "../../22_list_单链表/221_list_单链表.h"
using namespace std;

/*
    功能:在单链表中删除值为 x 的结点
    输入:
        SqList& L:待删除最小值的静态顺序表
        int& val: 最小值
    输出:
        bool:是否删除成功
    分析思路:
       遍历顺序表，把最小值与所有元素比对，找到最小值
    实现细节:
        定义变量 smallest = L.data[0], pos = 1;
        依次比对所有元素，记录下最小值 smallest 和其位序 pos
    注意点:
        a. 顺序表为空时，显示错误信息并退出
    时间复杂度:
            O(n)
    空间复杂度:
            O(1)
*/

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
    L.PrintList();

    int res = 0;
    L.ListDelete(2, res);
    L.PrintList();
    // std::cout.rdbuf(original_buf);
    // std::cout << "正常输出" << std::endl; // 恢复输出
    return 0;
}