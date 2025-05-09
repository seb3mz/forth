//动态顺序表
#include <iostream>
using namespace std;
#define InitSize 5
#define IncreaseSize 5

typedef struct {
    int *data;
    int MaxSize, length;  //顺序表能容纳元素的最大值和当前元素个数
} SqList;

// 1. 初始化顺序表
void InitList(SqList &L)
{
    L.data = (int *)malloc(sizeof(int) * InitSize);
    L.length = 0;
    L.MaxSize = InitSize;
    cout << "初始化顺序表成功" << endl;
}

// 2. 向顺序表指定位置 i 插入元素 e
bool ListInsert(SqList &L, int i, int e)
{
    //2.1 判断插入位置 i 是否合法，合法范围 [1, length+1]
    /*
        如果表为空，L.length=0，此时，只有当 i=1 时，(1<1 || 1>0+1) 不成立，会跳过去，所以对空表不用多加判断
    */
    if(i < 1 || i > L.length+1)
    {
        cout << "插入位置不合法 !!!" << endl; 
        return false;
    }
    //2.2 判断当前表是否已满，若满，则动态分配新的内存
    if(L.length == L.MaxSize)
    {
        cout << "顺序表已满，重新分配内存" << endl;
        //2.2.1 分配新内存
        int* newL = (int *)malloc(sizeof(int) * (L.MaxSize + IncreaseSize));
        //2.2.2 拷贝原内存元素到新内存
        for(int num = 0; num < L.length; num++)
        {
            newL[num] = L.data[num];
        }
        //2.2.3 释放旧内存
        free(L.data);
        //2.2.4 将新内存地址赋给顺序表
        L.data = newL;
        L.MaxSize += IncreaseSize;
    }
    //2.3 将位置 [i, L.length] 的元素移动到 [i+1, L.length+1]
    for(int pos = L.length; pos >= i; pos--)
    {
        L.data[pos] = L.data[pos-1];
    }
    //2.4 将位置 i 的元素赋值为 e
    L.data[i-1] = e;
    L.length += 1;

    return true;
}

// 3. 删除顺序表指定位置 i 处的元素，并传值到 e
bool ListDelete(SqList &L, int i, int &e)
{
    //3.0 表为空时，不可删除
    if(L.length == 0)
    {
        cout << "表为空，无法删除任何元素!!!" << endl;
        return false;
    }
    //3.1 判断删除的位置是否合法，合法位置为 [1, L.length]
    if(i < 1 || i > L.length)
    {
        cout << "删除位置不合法" << endl;
        return false;
    }
    //3.2 取值并赋值给 e
    e = L.data[i-1];
    //3.3 将位置 [i+1,L.length] 的元素移动到 [i, L.length-1]
    for(int pos = i; i < L.length; i++)
        L.data[i-1] = L.data[i];
    L.length -= 1;
    
    return true;
}

// 4. 查询并返回顺序表中元素为 e 的位序
int LocateElem(SqList L, int e)
{
    for(int pos = 1; pos <= L.length; pos++)
    {
        if(L.data[pos-1] == e)
            return pos;
    }
    cout << "元素 " << e << " 不存在" << endl;
    return 0;
}

//5. 打印顺序表
void printSeq(const SqList& L)
{
    for(int pos = 1; pos <= L.length; pos++)
    {
        cout << L.data[pos-1] << " "; 
    }    
    cout << endl;
}

//6. 求表长
int Length(const SqList& L)
{
    return L.length;
}

//7. 按位查找
int GetElem(const SqList& L, int i)
{
    //7.0 若表空，则无法查找
    if(L.length == 0)
    {
        cout << "表为空，无法查找!!!" << endl;
        return -1;
    }
    //7.1 判断 i 是否合法，合法范围为 [1 , L.length]
    if(i < 1 || i > L.length)
    {
        cout << "位置 " << i << " 不合法，取值失败" << endl;
        return -1;
    }
    return L.data[i-1];
}

//8. 判空
bool Empty(const SqList& L)
{
    return L.length == 0;
}

//9. 销毁顺序表
void DestroySeq(SqList& L)
{
    cout << "销毁顺序表" << endl;
    if(L.data)
    {
        free(L.data);
        L.data = nullptr;
        L.length = 0;
    }
}

int main(void)
{
    // 初始化顺序表
    SqList L;
    InitList(L);
    cout << "顺序表初始化成功" << endl;
    cout << "顺序表长度为: " << Length(L) << endl;
    cout << "顺序表是否为空: " << (Empty(L) ? "是" : "否") << endl;
    cout << endl;

    // 测试插入
    cout << "向顺序表中插入元素 1" << endl;
    ListInsert(L, 1, 1);
    cout << "向顺序表中插入元素 2" << endl;
    ListInsert(L, 2, 2);
    cout << "向顺序表中插入元素 3" << endl;
    ListInsert(L, 3, 3);
    cout << "向顺序表中插入元素 4" << endl;
    ListInsert(L, 4, 4);
    cout << "向顺序表中插入元素 5" << endl;
    ListInsert(L, 5, 5);
    cout << "向顺序表中插入元素 6" << endl;
    ListInsert(L, 6, 6);
    cout << "顺序表长度为: " << Length(L) << endl;
    cout << "顺序表是否为空: " << (Empty(L) ? "是" : "否") << endl;
    cout << "打印顺序表" << endl;
    printSeq(L);
    cout << endl;

    // 测试删除
    cout << "删除顺序表中位置 2 处的元素" << endl;
    int e;
    ListDelete(L, 2, e);
    cout << "删除的元素为: " << e << endl;
    cout << "顺序表长度为: " << Length(L) << endl;
    cout << "顺序表是否为空: " << (Empty(L) ? "是" : "否") << endl;
    cout << "打印顺序表" << endl;
    printSeq(L);
    cout << endl;

    // 测试按位查找
    cout << "顺序表中第 2 个元素为: " << GetElem(L, 2) << endl;
    cout << "顺序表中第 3 个元素为: " << GetElem(L, 3) << endl;
    cout << endl;
    
    // 测试按值查找
    cout << "顺序表中元素 3 的位序为: " << LocateElem(L, 3) << endl;
    cout << "顺序表中元素 5 的位序为: " << LocateElem(L, 5) << endl;
    cout << "顺序表中元素 88 的位序为: " << LocateElem(L, 88) << endl;
    cout << endl;

    // 测试销毁顺序表
    DestroySeq(L);
    cout << "顺序表长度为: " << Length(L) << endl;
    cout << "顺序表是否为空: " << (Empty(L) ? "是" : "否") << endl;

    return 0;
}
