#define SIZE 13
int UFSets[SIZE];

void Initial(int S[])
{
    for(int i = 0; i < SIZE; i++)
        S[i] = -1;
}

int Find(int S[], int x)
{
    while (S[x] >= 0)
        x = S[x];
    return x;
}

//将查找路径上所有结点都挂到根结点下
int Find_B(int S[], int x)
{
    int root = x;
    while (S[root] >= 0)
        root = S[root];
    while(x != root)
    {
        int t = S[x];
        S[x] = root;
        x = t;
    }
    return root;
}

void Union(int S[], int Root1, int Root2)
{
    if(Root1 == Root2)
        return;
    S[Root2] = Root1;
}

//小树挂到大树上
void Union_B(int S[], int Root1, int Root2)
{
    if(Root1 == Root2)
        return;
    if(S[Root2] > S[Root1])
    {
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    }
    else
    {
        S[Root2] += S[Root2];
        S[Root1] = Root2;
    }
}