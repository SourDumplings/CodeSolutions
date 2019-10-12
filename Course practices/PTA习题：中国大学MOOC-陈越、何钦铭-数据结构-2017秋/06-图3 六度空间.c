#include <stdio.h>
#include <stdlib.h>

#define MAXN 10000

typedef struct QUEUE *Queue;
struct QUEUE
{
    int *data;
    int front;
    int rear;
    int maxsize;
};

typedef int Vertex;

typedef struct AdjVNode *pAdjVNode;
struct AdjVNode
{
    Vertex V;
    pAdjVNode next;
};

typedef struct Vnode
{
    pAdjVNode firstedge;
} AdjList[MAXN];

typedef struct LGRAPH *LGraph;
struct LGRAPH
{
    int Ne;
    int Nv;
    AdjList G;
};

int IsFull(Queue Q)
{
    return (Q->rear+1)%Q->maxsize == Q->front;
}

void Enqueue(int x, Queue Q)
{
    if (IsFull(Q))
    {
        printf("队列满\n");
    }
    else
    {
        Q->data[++(Q->rear)] = x;
    }
    return;
}

int Dequeue(Queue Q)
{
    return Q->data[++(Q->front)];
}

int visited[MAXN] = {0};

int IsEmpty(Queue Q)
{
    return Q->rear == Q->front;
}

int BFS(LGraph Graph, Vertex V)
{
    visited[V] = 1;
    int count = 1;
    int level = 0; // 当前这个顶点所在的层数，即初始的节点在第0层
    Vertex last = V; // 当前这一层我访问的最后一个节点是谁
    Queue Q;

    Q = (Queue)malloc(sizeof(struct QUEUE));
    Q->front = Q->rear = -1;
    Q->data = (int *)malloc(Graph->Nv * sizeof(int));
    Q->maxsize = Graph->Nv;

    Vertex W;
    Vertex tail;

    Enqueue(V, Q);
    pAdjVNode node;
    while (!IsEmpty(Q))
    {
        V = Dequeue(Q);
        for (node = Graph->G[V].firstedge; node; node = node->next)
        {
            W = node->V;
            if (!visited[W])
            {
                visited[W] = 1;
                Enqueue(W, Q);
                count++;
                tail = W; // 下一层的最后一个节点是谁
            }
        }
        if (V == last)
        {
            level++;
            last = tail;
        }
        if (level == 6)
        {
            break;
        }
    }
    return count;
}

void Output(Vertex V, float ratio)
{
    printf("%d: %.2f%%\n", V+1, ratio * 100);
    return;
}

void InitializeVisit(LGraph Graph)
{
    int i;
    for (i = 0; i < Graph->Nv; i++)
    {
        visited[i] = 0;
    }
    return;
}

void SDS(LGraph Graph)
{
    Vertex V;
    int count;
    for (V = 0; V < Graph->Nv; V++)
    {
        InitializeVisit(Graph);
        count = BFS(Graph, V);
        Output(V, ((float)count/Graph->Nv));
    }
}

LGraph CreateGraph(int Nv)
{
    Vertex V;
    LGraph Graph;

    Graph = (LGraph)malloc(sizeof(struct LGRAPH));
    Graph->Nv = Nv;
    Graph->Ne = 0;

    for (V = 0; V < Graph->Nv - 1; V++)
    {
        Graph->G[V].firstedge = NULL;
    }

    return Graph;
}

typedef struct EDGE *Edge;
struct EDGE
{
    Vertex V1;
    Vertex V2;
};

void InsertEdge(LGraph Graph, Edge E)
{
    pAdjVNode NewNode;

    // V2插在V1的表头
    NewNode = (pAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->V = E->V2;
    NewNode->next = Graph->G[E->V1].firstedge;
    Graph->G[E->V1].firstedge = NewNode;

    // V1插在V2的表头
    NewNode = (pAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->V = E->V1;
    NewNode->next = Graph->G[E->V2].firstedge;
    Graph->G[E->V2].firstedge = NewNode;
    return;
}

int main()
{
    int N, M;
    LGraph Graph;
    int i;
    Edge E;

    scanf("%d %d", &N, &M);

    Graph = CreateGraph(N);
    Graph->Ne = M;

    Vertex V1, V2;

    for (i = 0; i < M; i++)
    {
        E = (Edge)malloc(sizeof(struct EDGE));
        scanf("%d %d", &V1, &V2);
        E->V1 = V1 - 1;
        E->V2 = V2 - 1;
        InsertEdge(Graph, E);
    }

    SDS(Graph);

    return 0;
}
