// 静态顺序表测试
#include <iostream>
#include "211_static_sequence_table_静态顺序表.h"
using namespace std;

int main()
{
    // 初始化顺序表
    SqList<int> L;
    L.InitList();
    cout << "顺序表初始化成功" << endl;
    cout << "顺序表长度为: " << L.Length() << endl;
    cout << "顺序表是否为空: " << (L.Empty() ? "是" : "否") << endl;
    cout << endl;

    // 测试插入
    cout << "向顺序表中插入元素 1" << endl;
    L.ListInsert(1, 1);
    cout << "向顺序表中插入元素 2" << endl;
    L.ListInsert(2, 2);
    cout << "向顺序表中插入元素 3" << endl;
    L.ListInsert(3, 3);
    cout << "向顺序表中插入元素 4" << endl;
    L.ListInsert(4, 4);
    cout << "顺序表长度为: " << L.Length() << endl;
    cout << "顺序表是否为空: " << (L.Empty() ? "是" : "否") << endl;
    cout << "打印顺序表" << endl;
    L.printSeq();
    cout << endl;

    // 测试删除
    cout << "删除顺序表中位置 2 处的元素" << endl;
    int e;
    L.ListDelete(2, e);
    cout << "删除的元素为: " << e << endl;
    cout << "顺序表长度为: " << L.Length() << endl;
    cout << "顺序表是否为空: " << (L.Empty() ? "是" : "否") << endl;
    cout << "打印顺序表" << endl;
    L.printSeq();
    cout << endl;

    // 测试按位查找
    cout << "顺序表中第 2 个元素为: " << L.GetElem(2) << endl;
    cout << "顺序表中第 3 个元素为: " << L.GetElem(3) << endl;
    cout << endl;
    
    // 测试按值查找
    cout << "顺序表中元素 3 的位序为: " << L.LocateElem(3) << endl;
    cout << "顺序表中元素 5 的位序为: " << L.LocateElem(5) << endl;
    cout << endl;

    // 测试销毁顺序表
    L.DestroySeq();
    cout << "顺序表长度为: " << L.Length() << endl;
    cout << "顺序表是否为空: " << (L.Empty() ? "是" : "否") << endl;

    return 0;
}