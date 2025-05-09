#ifndef STATIC_SEQUENCE_TABLE
#define STATIC_SEQUENCE_TABLE
#include <iostream>
using namespace std;
#define MaxSize 50
// 静态顺序表

template<typename T>
class SqList
{
public:
    SqList():length(0){}
    ~SqList(){}
    // 1. 初始化顺序表
    void InitList();
    // 2. 向顺序表指定位置 i 插入元素 e
    bool ListInsert(int i, T e);
    // 3. 删除顺序表指定位置 i 处的元素，并传值到 e
    bool ListDelete(int i, T &e);
    // 4. 查询并返回顺序表中元素为 e 的位序
    int LocateElem(T e) const;
    //5. 打印顺序表
    void printSeq() const;
    //6. 求表长
    int Length() const;
    //7. 按位查找
    int GetElem(int i) const;
    //8. 判空
    bool Empty() const;
    //9. 销毁顺序表
    void DestroySeq();
    //10. 返回指定位序引用
    T& operator[](int i);
    //11. 表长减1
    void DecreaseLength();

private:
    T data[MaxSize];
    int length;
};

// 1. 初始化顺序表
template<typename T>
void SqList<T>::InitList()
{
    //1.1 将所有数据元素设置为默认初始值
    // for(int pos = 0; pos < MaxSize; pos++)
    // {
    //     data[pos] = 0;
    // }

    //1.2 初始化表长
    length = 0;
}

// 2. 向顺序表指定位置 i 插入元素 e
template<typename T>
bool SqList<T>::ListInsert(int i, T e)
{
    //2.1 判断表是否已满
    if(length >= MaxSize)
    {
        cout << "静态顺序表已满，插入元素失败!!!" << endl;
        return false;
    }
    //2.2 判断插入位置是否合法，合法位置为 [1, length+1]
    if(i < 1 || i > length+1)
    {
        cout << "插入位置 " << i <<" 不合法!!!" << endl;
        return false;
    }
    //2.3 移动元素，移动位置 [i, length] 到 [i+1, length+1]
    for(int pos = length; pos >= i; pos --)
    {
        data[pos] = data[pos-1];
    }
    data[i-1] = e;
    length +=1;
    return true;
}

// 3. 删除顺序表指定位置 i 处的元素，并传值到 e
template<typename T>
bool SqList<T>::ListDelete(int i, T &e)
{
    //3.0 删除元素时，若表空，则无法删除任何元素
    if(length == 0)
    {
        cout << "空表无法删除" << endl;
        return false;
    }

    //3.1 判断删除位置是否合法，合法位置为 [1, length]
    if(i < 1 || i > length)
    {
        cout << "删除位置 " << i <<" 不合法!!!" << endl;
        return false;
    }
    e = data[i-1];
    //3.2 移动元素，移动位置 [i+1, length] 到 [i, length-1]
    for(int pos = i; pos < length; pos++)
    {
        data[pos-1] = data[pos];
    }

    length -= 1;
    return true;
}

// 4. 查询并返回顺序表中元素为 e 的位序
template<typename T>
int SqList<T>::LocateElem(T e) const
{
    for(int pos = 1; pos <= length; pos++)
    {
        if(data[pos-1] == e)
            return pos;
    }
    cout << "元素 " << e << " 不存在" << endl;
    return 0;
}

//5. 打印顺序表
template<typename T>
void SqList<T>::printSeq() const
{
    cout << "顺序表中的元素为: ";
    for(int pos = 1; pos <= length; pos++)
    {
        cout << data[pos-1] << " "; 
    }    
    cout << endl;
}

//6. 求表长
template<typename T>
int SqList<T>::Length() const
{
    return length;
}

//7. 按位查找
template<typename T>
int SqList<T>::GetElem(int i) const
{
    //7.0 表判空
    if(length == 0)
    {
        cout << "表为空，无法取值 !!!" << endl;
        return -1;
    }
    //7.1 判断 i 是否合法，合法范围为 [1 , length]
    /*
        当表空时，L.length = 0，如果 i = 1，则(1 < 1 || 1 > 0) 会成功，所以不需要再加一个表为空的判断条件
    */
    if(i < 1 || i > length)
    {
        cout << "位置 " << i << " 不合法，取值失败" << endl;
        return -1;
    }
    return data[i-1];
}

//8. 判空
template<typename T>
bool SqList<T>::Empty() const
{
    return length == 0;
}
//9. 销毁顺序表
template<typename T>
void SqList<T>::DestroySeq()
{
    cout << "销毁顺序表" << endl;
    length = 0;
}

//10. 返回指定位序引用
template<typename T>
T& SqList<T>::operator[](int i)
{
    if(i < 1 || i > length)
    {
        cout << "位序非法" << endl;
        throw std::out_of_range("out of range");
    }
    return data[i-1];
}

//11. 表长减1
template<typename T>
void SqList<T>::DecreaseLength()
{
    length--;
}

#endif  //STATIC_SEQUENCE_TABLE