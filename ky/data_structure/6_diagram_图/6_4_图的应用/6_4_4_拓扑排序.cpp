
//拓扑排序
bool TopologicalSort(Graph G)
{
    InitStack(S);
    int indegree[G.vexnum] = {0}; // 初始化入度数组
    for (int i = 0; i < G.vexnum; i++) 
    {
        if(indegree[i] == 0) 
        {
            Push(S, i); // 将入度为0的顶点入栈
        }
    }

    int count = 0; // 计数器，记录当前已经输出的定点数
    while(!IsEmpty(S))
    {
        Pop(s, i);
        print[count++] = i; // 输出顶点
        for(p = G.vertices[i].firstarc; p != NULL; p = p->nextarc) 
        {
            v = p->adjvex; // 获取邻接顶点
            if(--indegree[v] == 0) 
            {
                Push(S, v); // 如果入度为0，则将其入栈
            }
        }
    }

    if(count < G.vexnum) 
    {
        return false; // 如果输出的顶点数小于总顶点数，则存在环
    }
    return true; // 否则，拓扑排序成功
}

//逆拓扑排序实现 DFS 算法
void DFSTraverse(Graph G)
{
    for(v = 0; virtual v < G.vexnum; v++) 
    {
        visited[v] = false; // 初始化访问标志数组
    }
    for(v = 0; v < G.vexnum; v++)
    {
        if(!visited[v]) 
        {
            DFS(G, v); // 对未访问的顶点进行深度优先遍历
        }
    }
}

void DFS(Graph G, int v)
{
    visited[v] = true; // 标记顶点为已访问
    for(w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) 
    {
        if(!visited[w]) 
        {
            DFS(G, w); // 递归访问邻接顶点
        }
    }
    print(v); // 输出顶点
}