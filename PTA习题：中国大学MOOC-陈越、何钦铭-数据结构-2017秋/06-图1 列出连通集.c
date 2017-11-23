#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 11

typedef struct GNode *MGraph;
struct GNode
{
    int Nv; // 顶点数
    int Ne; // 边数
    int G[MaxVertexNum][MaxVertexNum]; // 邻接矩阵
};

typedef struct ENode *Edge;
struct ENode
{
    int v1, v2; // 有向边<v1, v2>
};

MGraph CreateGraph(int VertexNum)
{
    int V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for (V = 0; V < Graph->Nv; V++)
    {
        for (W = 0; W < Graph->Nv; W++)
        {
            Graph->G[V][W] = 0;
        }
    }

    return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
    Graph->G[E->v1][E->v2] = 1;
    Graph->G[E->v2][E->v1] = 1;
    return;
}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    int Nv, i, Ne;

    scanf("%d %d", &Nv, &Ne);
    Graph = CreateGraph(Nv);
    Graph->Ne = Ne;
    if (Graph->Ne != 0)
    {
        E = (Edge)malloc(sizeof(struct ENode));
        for(i = 0; i < Graph->Ne; i++)
        {
            scanf("%d %d",
                &E->v1, &E->v2);
            InsertEdge(Graph, E);
        }
    }

    return Graph;
}

void Visit(int v)
{
    printf("%d ", v);
    return;
}

int visited[MaxVertexNum];

void Initializev(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    return;
}

void DFS(MGraph Graph, int v, void (*Visit)(int))
{
    int i;

    Visit(v);
    visited[v] = 1;

    for (i = 0; i < Graph->Nv; i++)
    {
        if (Graph->G[v][i] && !(visited[i]))
        {
            DFS(Graph, i, Visit);
        }
    }

    return;
}

int IsEdge(MGraph Graph, int V, int W)
{
    return Graph->G[V][W];
}

typedef struct QUEUE *Queue;
struct QUEUE
{
    int *data;
    int front, rear;
    int maxsize;
};

Queue CreateQueue(int maxsize)
{
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QUEUE));
    Q->data = (int *)malloc(maxsize * sizeof(int));
    Q->front = Q->rear = 0;
    Q->maxsize = maxsize;
    return Q;
}

int IsFull(Queue Q)
{
    return (Q->rear+1)%Q->maxsize == Q->front;
}

int AddQ(Queue Q, int X)
{
    if (IsFull(Q))
    {
        printf("队列满\n");
        return 0;
    }
    else
    {
        Q->rear = (Q->rear+1) % Q->maxsize;
        Q->data[Q->rear] = X;
        return 1;
    }
}

int IsEmpty(Queue Q)
{
    return (Q->front == Q->rear);
}

int DeleteQ(Queue Q)
{
    if (IsEmpty(Q))
    {
        printf("队列空\n");
        return -1;
    }
    else
    {
        Q->front = (Q->front+1) % Q->maxsize;
        return Q->data[Q->front];
    }
}

void BFS(MGraph Graph, int s, void (*Visit)(int))
{
    Queue Q;
    int V, W;

    Q = CreateQueue(Graph->Nv+1);

    Visit(s);
    visited[s] = 1;
    AddQ(Q, s);

    while (!IsEmpty(Q))
    {
        V = DeleteQ(Q);
        for (W = 0; W < Graph->Nv; W++)
        {
            if (Graph->G[V][W] && !(visited[W]))
            {
                Visit(W);
                visited[W] = 1;
                AddQ(Q, W);
            }
        }
    }

    return;
}

int main()
{
    MGraph Graph;
    int v = 0;
    Graph = BuildGraph();

    Initializev(Graph->Nv);

    for (v = 0; v < Graph->Nv; v++)
    {
        if (!visited[v])
        {
            printf("{ ");
            DFS(Graph, v, Visit);
            printf("}\n");
        }
    }

    Initializev(Graph->Nv);

    for (v = 0; v < Graph->Nv; v++)
    {
        if (!visited[v])
        {
            printf("{ ");
            BFS(Graph, v, Visit);
            printf("}\n");
        }
    }

    return 0;
}
