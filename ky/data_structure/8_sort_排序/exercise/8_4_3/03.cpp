#include <iostream>
#include "/home/seb3mz/work/code/forth/ky/data_structure/2_linear_list_线性表/22_list_单链表/221_list_单链表.h"
using namespace std;

void SimpleSelectSort(LinkList<int>& L)
{
    cout << "开始排序" << endl;
    LinkList<int> new_list;
    new_list.InitList();
    LinkList<int>::LNode* new_list_tmp = new_list.GetHeadNode();
    LinkList<int>::LNode* pre_node = L.GetHeadNode(); 
    LinkList<int>::LNode* cur_node = pre_node->next;
    LinkList<int>::LNode* min_node = cur_node;
    LinkList<int>::LNode* pre_min_node = pre_node;
    
    while(cur_node)
    {
        int min = cur_node->data;
        while(cur_node)
        {
            if(cur_node->data < min)
            {
                min_node = cur_node;
                pre_min_node = pre_node;
            }
            pre_node = cur_node;
            cur_node = cur_node->next;
        }
        pre_min_node->next = min_node->next;
        new_list_tmp->next = min_node;
        min_node->next = nullptr;
        new_list_tmp = new_list_tmp->next;

        pre_node = L.GetHeadNode();
        cur_node = pre_node->next;
    }
    cout << "排序后" << endl;
    new_list.PrintList();
}

int main()
{
    LinkList<int> L;
    //L.InitList();
    L.List_HeadInsert();
    SimpleSelectSort(L);
    return 0;
}