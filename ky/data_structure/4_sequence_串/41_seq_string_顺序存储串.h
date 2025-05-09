#ifndef SEQ_STRING_H
#define SEQ_STRING_H

#define MAXLEN 255

// class SString {
// public:
//     SString();
//     ~SString();
//     bool SubString(SString &sub, int pos);
//     int StrCompare(const SString &str);
//     int Index_SimpleCode(const SString &sub);
//     int Index_KMP(const SString &sub);
//     void StrAssign(const char *chars);
//     void StrCopy(const SString &src);
//     //判空操作
//     bool StrEmpty();
//     //求长度操作
//     int StrLength();
//     //清空操作
//     void ClearString();
//     //销毁操作
//     void DestroyString();
//     //串连接操作
//     void Concat(const SString &str1, const SString &str2);

// private:
//     char ch[MAXLEN + 1];
//     int length;
// };

//静态分配
typedef struct {
    char ch[MAXLEN + 1]; // 0th index is not used
    int length;
}SString;

//动态分配
typedef struct {
    char *ch;
    int length;;
}HString;

//初始化 String
bool InitString(SString &str);

//求字串，用 sub 返回
bool SubString(SString &sub, SString &str, int pos);

//比较
int StrCompare(const SString &str1, const SString &str2);

//定位操作, 在 str 中返回 sub 的位置
int Index_SimpleCode(const SString &str, const SString &sub);
int Index_KMP(const SString &str, const SString &sub);

//赋值操作
bool StrAssign(SString &str, const char *chars);

//复制操作
void StrCopy(SString &str, const SString &src);

//判空操作
bool StrEmpty(const SString &str);
//求长度操作
int StrLength(const SString &str);
//清空操作
void ClearString(SString &str);
//销毁操作
void DestroyString(SString &str);
//串连接操作
void Concat(SString &str, const SString &str1, const SString &str2);
//打印串
void PrintStr(const SString &str);

#endif //SEQ_STRING_H