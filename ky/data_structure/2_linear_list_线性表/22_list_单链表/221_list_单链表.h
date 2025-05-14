#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

//单链表
template<typename T>
class LinkList
{
public:
    struct LNode
    {
        T data;
        struct LNode* next;
    };
    LinkList():head(nullptr){}
    ~LinkList()
    {
        if(head)
        {
            DestoryList();
        }
    }
    //1.初始化链表
    bool InitList();

    //2.判断空表
    bool Empty() const;

    //3.求链表长度
    int Length() const;

    //4.打印链表
    void PrintList() const;

    //5.按位序查找结点
    LNode* GetElem(int i) const;

    //6.按值查找结点
    LNode* LocateElem(int e) const;

    // 链表的插入操作
    //7.在链表位序 i 处插入值 e
    bool ListInsert(int i, int e);
    //8.指定结点的后插操作
    bool InsertNextNode(LNode* p, int e);
    //9.指定结点的前插操作
    bool InsertPriorNode_w1(LNode* p, int e);
    bool InsertPriorNode_w2(LNode* p, int e);

    // 链表的删除操作
    //10.删除联邦中第 i 处的元素，并用 e 返回
    bool ListDelete(int i, int e);
    //11.删除指定结点 p
    bool DeleteNode_w1(LNode* p);
    bool DeleteNode_w2(LNode* p);

    //12.头插法建表
    LinkList List_HeadInsert();

    //13.尾插法建表
    LinkList List_TailInsert();

    //14.销毁单链表
    void DestoryList();
private:
    LNode* head;
};

//1.初始化链表
template<typename T>
bool LinkList<T>::InitList()
{
    head = (LNode*)malloc(sizeof(LNode));
    if(head == nullptr)
    {
        cout << "分配头结点失败" << endl;
        return false;
    }

    head->next = nullptr;
    cout << "带头结点的单链表初始化成功" << endl;
    return true;
}

//2.判断空表
template<typename T>
bool LinkList<T>::Empty() const
{
    if(head == nullptr)
    {
        cout << "未构造的单链表" << endl;
        return true;
    }
    return head->next == nullptr;
}

//3.求链表长度
template<typename T>
int LinkList<T>::Length() const
{
    if(head == nullptr)
    {
        cout << "未构造的单链表" << endl;
        return -1;
    }

    //3.1 带头结点链表的头结点不算进长度
    int length = 0;
    LNode* tmp = head->next;
    //从 tmp 开始计算，tmp 算第一个结点(如果 tmp 不为空)
    while(tmp)
    {
        tmp = tmp->next;
        length++;
    }
    return length;
}

//4.打印链表
template<typename T>
void LinkList<T>::PrintList() const
{
    if(head == nullptr)
    {
        cout << "未构造的单链表" << endl;
        return;
    }

    cout << endl;
    LNode * tmp = head->next;
    cout << "PrintList:单链表遍历:";
    while(tmp)
    {
        cout << " " << tmp->data;
        tmp = tmp->next;
    }
    cout << endl;
}

//5. 按位序查找结点
/*
    功能:按位序在链表中查找结点
    输入:
        const LinkList& L: 待查找链表
        int i: 位序
    输出:
        LNode*: 被查找位序结点的指针
    分析思路:
        通过遍历找到位序为第 i 个的结点
    实现细节:

    注意点:
        a. 输入校验
        b. 循环遍历时的终止条件
    时间复杂度:
        O(n)
    空间复杂度
*/
template<typename T>
typename LinkList<T>::LNode* LinkList<T>::GetElem(int i) const
{
    cout << endl << "GetElem:根据位序查找结点" << endl;
    //输入校验
    if(i < 1)
    {
        cout << "位序 i:" << i << " 不合法" << endl;
        return nullptr;
    }
    //需要注意
    //  5.1 当位序 i 大于链表长度时，返回 nullptr
    //  5.2 带头结点的链表需要从第一个非头结点的结点开始遍历计数
    LNode* tmp = head;
    int pos = 0;
    while(tmp && pos < i)
    {
        tmp = tmp->next;
        pos++;
    }

    if(tmp == nullptr)
    {
        cout << "当前链表长度为:" << Length() << " ,但需要查找链表中第" << i << "个位置的结点，查找失败" << endl;
    }
    else
    {
        cout << "查找位序为 " << i << "的元素成功" << endl;
    }

    return tmp;
}

/*
    功能:6.按值查找单链表
    输入:
        const LinkList& L:待查单链表
        int e:待查找的值
    输出
        LNode*: 返回的第一个等于给定值的结点指针
    分析思路
        遍历单链表进行比对值
    实现细节
    注意点
    时间复杂度
        O(n)
    空间复杂度
*/
template<typename T>
typename LinkList<T>::LNode* LinkList<T>::LocateElem(int e) const
{
    cout << endl << "LocateElem:按值查找结点" << endl;

    LNode* tmp = head->next;
    while(tmp && tmp->data != e)
    {
        tmp = tmp->next;
    }

    if(tmp == nullptr)
    {
        cout << "未查到值为 " << e << " 的结点" << endl;
    }
    else
    {
        cout << "按值查找成功" << endl;
    }

    return tmp;
}

//7. 在带头结点单链表 L 中的第 i 个位置上插入指定元素 e
/*
    7.1 功能: 在表 L 中的第 i 个位置上插入指定元素 e
    7.2 输入:
            LinkList& L: 待插入元素的单链表
            i: 位序
            e: 待插入元素
    7.3 输出:
            bool 表示插入是否成功
    7.4 分析思路:
            将指定元素 e 插入到单链表的第 i 个位置，结合单链表的存储结构，
                a.需要找到第 i-1 个位置的结点 pre
                b.将待插入结点 current 的后继指针指向 pre 结点的后继指针: current->next = pre->next
                c.将结点 pre 的后继指针指向新插入的结点 current: pre->next = current
    7.5 实现细节
            定义变量:  
                    a. LNode* tmp : 代表正在遍历的结点指针;
                       int pos : 表示正在遍历结点的位序，用于找到位序 i-1
                        初始化: tmp 被初始化为单链表的头结点, pos 为 0(头结点不计入位序)
                        变化: tmp 与 pos 同步变化, 代表位序为 pos 的结点,其指针为 tmp
                        结束: (tmp == nullptr || pos == i-1), 当 tmp 为空代表链表已经到尾部; pos==i-1 代表找到位序为 i-1 
    7.6 注意点
            a.当插入位序为 1 时，代表插入头结点后的位置，此时需要知道头结点指针 L 即可
            b.找到第 i-1 位序的结点后，需要判断该结点是否为空，为空的话就不能在其后插入结点
    7.7 时间复杂度
            a. 当插入到链表头结点后的位置，*** ListInset 遍历链表 *** 处循环不执行，时间复杂度为 O(1)
            b. 当插入到链表尾部的位置，*** ListInset 遍历链表 *** 处执行最长循环，时间复杂度为 O(n)
            c. 平均时间复杂度 O(n)
    7.8 空间复杂度
*/
template<typename T>
bool LinkList<T>::ListInsert(int i, int e)
{
    cout << endl << "ListInsert:指定位序的插入操作" << endl;

    // 判断插入位置是否合法
    if(i < 1)
    {
        cout << "插入未知为 " << i << " 不合法，插入失败" << endl;
        return false;
    }
    //7.1 插入位序为 i，先找到位置为 i-1 的结点
    LNode* tmp = head;
    // pos 为 0 代表头结点
    int pos = 0;
    // *** ListInset 遍历链表 ***
    while(tmp && pos < i-1)
    {
        tmp = tmp->next;
        pos++;
    }

    //下面的代码可以使用 return InsertNextNode(tmp, e); 代替
    // 如果链表结点个数少于 i-1 个，则无法在第 i 位置插入元素，直接返回 false
    // 或者已经到达链表尾部时
    if(tmp == nullptr)
    {
        cout << "当前链表长度为:" << Length() << " ,但需要在链表中第" << i << "个位置插入 " << e << " ,插入失败" << endl;
        return false;
    }

    //新增结点，然后修改指针域
    LNode* prev = tmp;
    LNode* node = (LNode*)malloc(sizeof(LNode));
    if(node == nullptr)
    {
        cout << "创建结点失败" << endl;
        return false;
    }
    node->data = e;
    node->next = prev->next;
    prev->next = node;

    cout <<"在位置" << i <<"插入数据:" << e <<"成功" << endl;

    return true;
}

/*
    功能: 向指定结点 p 后插入一个结点，值为 e
    输入: 
        LNode* p: 指定结点，其后要被插入结点
        int e: 待插入的值
    输出:
        bool: 表示插入成功或者失败
    分析思路:
        将元素插入指定结点 p 后面，需要进行结点指针域的修改
            a. 将 p 的后继指针域赋值给新结点 current 的后继指针域: current->next = p->next;
            b. 将 p 的后继指针指向 current: p->next = current;
    注意点
        a. 如果结点 p 为空则不可以进行后插结点操作
    时间复杂度:
        O(1)
    空间复杂度
*/
//8.指定结点的后插操作
template<typename T>
bool LinkList<T>::InsertNextNode(LNode* p, int e)
{

    cout << endl << "InsertNextNode:指定结点的后插操作" << endl;

    //判断 p 是否是合法值
    if(p == nullptr)
    {
        cout << "指定结点无效" << endl;
        return false;
    }
    LNode* node = (LNode*)malloc(sizeof(LNode));
    if(node == nullptr)
    {
        cout << "分配结点失败" << endl;
        return false;
    }
    node->data = e;
    node->next = p->next;
    p->next = node;
    cout << "指定结点后插入元素 " << e << " 成功" << endl;
    return true;
}

/*
    功能: 9.向指定结点 p 前插入一个结点，值为 e
    输入: 
        LNode* p: 指定结点，其前面要被插入结点
        int e: 待插入的值
    输出:
        bool: 表示插入成功或者失败
    分析思路:
        方法1: 遍历查找结点 p 的前一结点 pre，然后对 pre 进行后插操作 InsertNextNode(pre, e)
        方法2: 对结点 p 进行后插操作，然后将结点 p 的值与其后继结点 next 的值互换 
    实现细节:
        方法1:
            定义变量:
                LNode* tmp; //用于遍历单链表的当前结点
                LNode* pre; //代表当前结点的前一结点
                初始化: tmp 初始化为链表的第一个结点，pre 初始化为链表的头结点
                变化: 向后遍历时，pre 指向 tmp 结点，tmp 指向 tmp 的后继结点
                结束: 当 tmp 结点与指定结点 p 相等时，表明已经找到结点 p 和它的前结点 pre
        方法2:
            新建结点 LNode* node 和交换数据用的临时变量 int tmp;
    注意点:
        a. 需要判断输入的指定结点是否合法
        b. 当遍历结束，需要判断当前的结点 tmp 是否为空，为空表明未找到指定结点
        
    时间复杂度:
        方法1:
            需要从头遍历单链表，时间复杂度为 O(n)
        方法2:
            只需要交换数据，时间复杂度为 O(1)
    空间复杂度
*/
template<typename T>
bool LinkList<T>::InsertPriorNode_w1(LNode* p, int e)
{
    cout << endl << "InsertPriorNode_w1:方法1的指定结点的前插操作" << endl;
    //判断 p 结点是否合法
    if(p == nullptr || p == head)
    {
        cout << "非法结点" << endl;
        return false;
    }

    //tmp 初始化为第一个结点
    LNode* tmp = head->next;
    //pre 初始化为头结点
    LNode* pre = head;
    //当 tmp 不为空，并且不等于指定结点 p 时
    while(tmp && tmp != p)
    {
        pre = tmp;
        tmp = tmp->next;
    }
    if(tmp == nullptr)
    {
        cout << "未找到指定结点" << endl;
        return false;
    }
    cout << "找到指定结点,执行其前结点的后插操作" << endl;

    return InsertNextNode(pre, e); 
}

template<typename T>
bool LinkList<T>::InsertPriorNode_w2(LNode* p, int e)
{
    cout << endl << "InsertPriorNode_w2:方法2的指定结点的前插操作" << endl;
    //判断 p 结点是否合法
    if(p == nullptr || p == head)
    {
        cout << "输入的指定结点不合法" << endl;
        return false;
    }

    cout << "找到指定结点, 执行后插操作并交换数据" << endl;
    // p 结点的后插操作
    LNode* node = (LNode*)malloc(sizeof(LNode));
    if(node == nullptr)
    {
        cout << "新建结点失败" << endl;
        return false;
    }
    node->data = e;
    node->next = p->next;
    p->next = node;

    //交换 p 结点和新建结点 node 的值
    int tmp = node->data;
    node->data = p->data;
    p->data = tmp;
    return true;
}

/*
    功能: 10.删除单链表 L 指定位序 i 处的结点,并把其值用 e 返回
    输入:
        LinkList &L: 待删除结点的链表
        int i: 位序
        int e: 传值
    输出:
        bool: 删除是否成功
    分析思路:
        删除位序为 i 的结点,需要找到位序为 i-1 的结点，修改其指针域
    实现细节:
        同 ListInsert
    注意点:
        a. 判断输入的位序是否合法
        b. 找到位序为 i-1 的结点后，也要判断位序为 i 的结点是否为空，为空的话表示不可删除
    时间复杂度
        需要遍历，O(n)
    空间复杂度
*/
template<typename T>
bool LinkList<T>::ListDelete(int i, int e)
{
    cout << endl << "ListDelete:删除指定位序结点" << endl;
    // 判断输入的位序 i 是否合法
    if(i < 1)
    {
        cout << "删除的位序不合法" << endl;
        return false;
    }

    //找到第 i-1 处的元素
    LNode* tmp = head;
    int pos = 0;
    while(tmp && pos < i-1)
    {
        tmp = tmp->next;
        pos++;
    }

    //第 i-1/i 位序结点为空表明链表长度达不到 i,所以无法删除该位序的结点
    if(tmp == nullptr || tmp->next == nullptr)
    {
        cout << "当前链表长度为:" << Length() << " ,但需要在链表中第" << i << "个位置删除结点" << ",删除失败" << endl;
        return false;
    }
    //修改指针域并删除结点
    LNode* mid = tmp->next;
    e = mid->data;
    tmp->next = mid->next;
    free(mid);
    cout << "删除位序:" << i << " 结点成功" << endl;
    return true;
}

/*
    功能: 11.根据结点 p 位置，删除指定结点 p
    输入:
        LNode* p: 待删除的结点
    输出:
        bool: 表示是否成功删除
    分析思路:
        同 InsertPriorNode，有两种方法
        方法1:从链表头开始遍历，找到指定结点 p 的前驱结点 pre,修改结点 pre 的后继指针指向
        方法2:找到指定结点 p 的后继结点 nxt, 将结点 nxt 的值覆盖掉 结点 p 的值，删除结点 nxt

    实现细节
        方法1:
            变量:
                LNode* cur; 遍历链表时的当前结点
                LNode* pre; 遍历链表时的当前结点的前驱结点
                初始化: cur 初始化为第一个结点，pre 初始化为头结点
                变化: cur 和 pre 同步变化，且 pre 一直保持 cur 为前驱结点
                结束: 当 cur 为空时，表示到达链表尾部; 当 cur == p 时，表示找到指定结点

    注意点
        a.输入值的合法校验
        b.使用方法2时，注意当删除的结点如果是单链表的最后一个结点时的特殊情况
    时间复杂度
    空间复杂度
*/
//删除指定结点 p
template<typename T>
bool LinkList<T>::DeleteNode_w1(LNode* p)
{
    cout << endl << "DeleteNode_w1:方法1的删除指定结点操作" << endl;
    //判断 p 结点是否合法
    if(p == nullptr || p == head)
    {
        cout << "非法结点" << endl;
        return false;
    }

    // 当前结点初始化为头结点
    LNode* cur = head->next;
    LNode* pre = head;
    while(cur && cur != p)
    {
        pre = cur;
        cur = cur->next;
    }

    if(cur == nullptr)
    {
        cout << "未找到指定结点" << endl;
        return false;
    }

    // 修改指定结点的前驱结点指针域
    pre->next = cur->next;
    //释放指定结点
    free(cur);
    cout << "删除指定结点成功" << endl;
    return true;
}

/*

*/

template<typename T>
bool LinkList<T>::DeleteNode_w2(LNode* p)
{
    cout << endl << "DeleteNode_w2:方法2的删除指定结点操作" << endl;
    //输入合法校验
    if(head == nullptr)
    {
        cout << "链表为空" << endl;
        return false;
    }

    if(p == nullptr)
    {
        cout << "删除的结点不合法" << endl;
        return false;
    }

    //前提是 p 是单链表 L 的结点
    if(p->next == nullptr)
    {
        cout << "该结点为最后一个结点" << endl;
        return DeleteNode_w1(p);
    }
    else
    {
        // 删除指定结点 p 的后继结点，修改指针域并把后继结点的值覆盖当前结点的值
        LNode* nxt = p->next;
        p->data = nxt->data;
        p->next = nxt->next;
        free(nxt);
        cout << "删除结点成功" << endl;
        return true;
    }

    // LNode* cur = L->next;
    // LNode* pre = L;
    // while(cur && cur != p)
    // {
    //     pre = cur;
    //     cur = cur->next;
    // }

    // if(cur == nullptr)
    // {
    //     cout << "未找到指定结点" << endl;
    //     return false;
    // }

    
    return true;
}

/*
    功能: 12.头插法建立单链表
    输入:
        LinkList& L: 待创建的单链表
    输出:
        LinkList: 创建完成后的单链表
    分析思路:
        在获取元素后，调用前插操作
                            bool ListInsert(LinkList &L, int i, int e);
                            bool InsertPriorNode_w1(LinkList& L, LNode* p, int e);
                            bool InsertPriorNode_w2(LinkList& L, LNode* p, int e);
    实现细节:
    注意点:
    时间复杂度:
    空间复杂度:
*/
template<typename T>
LinkList<T> LinkList<T>::List_HeadInsert()
{
    //初始化链表
    InitList();

    LNode* pre = head;
    int x = 0;
    scanf("%d", &x);
    while(x != 999)
    {
        ListInsert(1, x); //每次在第一个结点处插入
        PrintList();
        scanf("%d", &x);
    }

    return *this;
}

/*
    功能:使用尾部插入结点的方法创建单链表
    输入:
        LinkList& L: 待创建的链表
    输出:
        插入结点后的链表
    分析思路:
        获取用户输入后，调用上述结点插入操作:
                                        bool ListInsert(LinkList &L, int i, int e);
                                        bool InsertNextNode(LNode* p, int e);
    实现细节:
            变量 LNode* rear:代表单链表尾元素
                初始化: 初始化为头结点
                变化: 每次尾部加入结点后，都把该指针指向最后一个结点
                结束
    注意点:
    时间复杂度:
            调用 ListInsert, O(n2)
            调用 InsertNextNode, O(n)
    空间复杂度:
*/

//13. 尾插法建表
template<typename T>
LinkList<T> LinkList<T>::List_TailInsert()
{
    //初始化链表
    InitList();

    LNode* rear = head;
    int pos = 1;
    int x = 0;
    scanf("%d", &x);
    while(x != 999)
    {
        //ListInsert(L, pos++, x); //每次都从头遍历，效率较低
        if(InsertNextNode(rear, x)) //记录最后一个结点位置 rear,直接在 rear 后插操作，效率高
        {
            rear = rear->next;
        }
        PrintList();
        scanf("%d", &x);
    }

    return *this;
}

//14.销毁单链表
template<typename T>
void LinkList<T>::DestoryList()
{
    cout << "DestoryList:销毁单链表" << endl;
    if(head == nullptr)
    {
        cout << "未构造的单链表" << endl;
        return;
    }
    LNode* tmp = head;
    LNode* rear;
    while(tmp)
    {
        rear = tmp->next;
        free(tmp);
        tmp = rear;
    }
    head = nullptr;
    cout << "销毁单链表成功" << endl;
    return;
}
#endif  //LIST_H