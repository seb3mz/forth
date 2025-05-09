typedef struct StringNode {
    char ch;
    struct StringNode *next;
}StringNode, *String;

typedef struct StringSNode {
    char ch[4];
    struct StringSNode *next;
}StringSNode, *SString;