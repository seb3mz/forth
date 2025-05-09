#ifndef DYNAMIC_SEQUENCE_TABLE_H
#define DYNAMIC_SEQUENCE_TABLE_H

#define InitSize 5
#define IncreaseSize 5

typedef struct {
    int *data;
    int MaxSize, length;  //顺序表能容纳元素的最大值和当前元素个数
} SqList;

// 1. 初始化顺序表
void InitList(SqList &L);

// 2. 向顺序表指定位置 i 插入元素 e
bool ListInsert(SqList &L, int i, int e);

// 3. 删除顺序表指定位置 i 处的元素，并传值到 e
bool ListDelete(SqList &L, int i, int &e);

// 4. 查询并返回顺序表中元素为 e 的位序
int LocateElem(SqList L, int e);

//5. 打印顺序表
void printSeq(const SqList& L);

//6. 求表长
int Length(const SqList& L);

//7. 按位查找
int GetElem(const SqList& L, int i);

//8. 判空
bool Empty(const SqList& L);

//9. 销毁顺序表
void DestroySeq(SqList& L);

#endif //DYNAMIC_SEQUENCE_TABLE_H