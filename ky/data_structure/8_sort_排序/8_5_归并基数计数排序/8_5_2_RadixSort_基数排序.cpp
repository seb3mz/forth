#include <iostream>
using namespace std;

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
}LinkNode, *LinkList;

typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

LinkQueue Q[10];

int main()
{
    return 0;
}