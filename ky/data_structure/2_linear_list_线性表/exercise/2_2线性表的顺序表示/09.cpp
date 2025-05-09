#include <iostream>
#include "/home/seb3mz/work/code/ky/data_structure/2_linear_list_线性表/21_sequence_table_顺序表/211_static_sequence_table_静态顺序表.h"
using namespace std;

int main()
{
    SqList<int> Sql;
    Sql.InitList();
    Sql.ListInsert(1,1);
    Sql.ListInsert(2,4);
    Sql.ListInsert(3,8);
    Sql.ListInsert(4,41);
    Sql.ListInsert(5,55);

    Sql.printSeq();
    Sql.printSeq();
    return 0;
}