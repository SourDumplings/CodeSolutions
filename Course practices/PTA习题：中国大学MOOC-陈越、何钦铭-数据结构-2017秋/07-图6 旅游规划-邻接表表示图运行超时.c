#include <stdio.h>
#include <stdlib.h>

#define MAXN 501

#define INFINITY 9999999

typedef struct AdjVNode *PtrtoAdjVNode;
struct AdjVNode
{
    int V;
    int d;
    int c;
    PtrtoAdjVNode Next;
};

typedef struct Vnode
{
    PtrtoAdjVNode FirstEdge;
} AdjList[MAXN];

typedef struct GNode
{
    int N;
    int M;
    AdjList G;
} *LGraph;

typedef struct EDGE
{
    int V1, V2;
    int d, c;
} *Edge;

int dist[MAXN];
int cost[MAXN];
int collected[MAXN] = {0};

// 未收录顶点中dist最小者
int FindMinDist(int N)
{
    int i;
    int mindist = INFINITY;
    int mindist_i = -1;
    for (i = 0; i < N; i++)
    {
        if (!collected[i] && dist[i] < mindist)
        {
            mindist = dist[i];
            mindist_i = i;
        }
    }
    return mindist_i;
}

int Distance(LGraph Graph, int V, int W)
{
    int d;
    PtrtoAdjVNode Node;
    for (Node = Graph->G[V].FirstEdge; Node; Node = Node->Next)
    {
        if (Node->V == W)
        {
            d = Node->d;
        }
    }
    return d;
}

int Cost(LGraph Graph, int V, int W)
{
    int c;
    PtrtoAdjVNode Node;
    for (Node = Graph->G[V].FirstEdge; Node; Node = Node->Next)
    {
        if (Node->V == W)
        {
            c = Node->c;
        }
    }
    return c;
}

void Dijkstra(LGraph Graph, int s)
{
    int V, W;
    PtrtoAdjVNode Node;
    cost[s] = 0;
    dist[s] = 0;
    while (1)
    {
        V = FindMinDist(Graph->N);
        if (V == -1) // 表示这样的V不存在
        {
            break;
        }
        collected[V] = 1;
        // 扫描V的每一个邻接点
        for (Node = Graph->G[V].FirstEdge; Node; Node = Node->Next)
        {
            W = Node->V;
            if (!collected[W])
            {
                if (dist[V] + Distance(Graph, V, W) < dist[W])
                {
                    dist[W] = dist[V] + Distance(Graph, V, W);
                    cost[W] = cost[V] + Cost(Graph, V, W);
                }
                else if ((dist[V] + Distance(Graph, V, W) == dist[W]) &&
                    (cost[V] + Cost(Graph, V, W) < cost[W]))
                {
                    cost[W] = cost[V] + Cost(Graph, V, W);
                }
            }
        }
    }
    return;
}

LGraph CreateGraph(int N)
{
    int V;
    LGraph Graph;
    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->N = N;
    Graph->M = 0;

    for (V = 0; V < N; V++)
    {
        Graph->G[V].FirstEdge = NULL;
    }
    return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
    PtrtoAdjVNode NewNode;
    NewNode = (PtrtoAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->V = E->V2;
    NewNode->d = E->d;
    NewNode->c = E->c;
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;

    NewNode = (PtrtoAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->V = E->V1;
    NewNode->d = E->d;
    NewNode->c = E->c;
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
    return;
}

LGraph BuildGraph(int N, int M)
{
    LGraph Graph;
    int i;
    Graph = CreateGraph(N);
    Graph->M = M;
    Edge E;
    if (Graph->M)
    {
        E = (Edge)malloc(sizeof(struct EDGE));
        for (i = 0; i < M; i++)
        {
            scanf("%d %d %d %d", &E->V1, &E->V2, &E->d, &E->c);
            InsertEdge(Graph, E);
        }
    }
    return Graph;
}

int main()
{
    LGraph Graph;
    int N, M, S, D;
    scanf("%d %d %d %d", &N, &M, &S, &D);
    int i;
    for (i = 0; i < N; i++)
    {
        cost[i] = INFINITY;
        dist[i] = INFINITY;
    }
    Graph = BuildGraph(N, M);
    Dijkstra(Graph, S);
    printf("%d %d\n", dist[D], cost[D]);
    return 0;
}
