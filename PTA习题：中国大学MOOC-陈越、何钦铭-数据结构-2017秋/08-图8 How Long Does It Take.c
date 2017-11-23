#include <stdio.h>
#include <stdlib.h>

#define MAXN 100
#define INFINITY 999999
#define ERROR -1

int N, M;
int earliest[MAXN] = {0};
int Graph[MAXN][MAXN];
int flag = 1;
int indegree[MAXN] = {0};
int finish[MAXN]; // 用来存储已经得到最早完工时间的结点
int count = 0; // 用来记录已经得到最早完工时间的结点的个数
int outdegree[MAXN] = {0};


typedef struct QUEUE *Queue;
struct QUEUE
{
    int *data;
    int maxsize;
    int front;
    int rear;
};

void Enqueue(Queue Q, int X)
{
    if (Q->front == (Q->rear+1) % Q->maxsize)
    {
        // 队列满
        return;
    }
    Q->rear = (Q->rear + 1) % Q->maxsize;
    Q->data[Q->rear] = X;
    return;
}

int IsEmpty(Queue Q)
{
    return Q->rear == Q->front;
}

int Dequeue(Queue Q)
{
    if (IsEmpty(Q))
    {
        return ERROR;
    }
    Q->front = (Q->front + 1) % Q->maxsize;
    return Q->data[Q->front];
}

void TopSort()
{
    int i;
    int V, W;
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QUEUE));
    Q->maxsize = N;
    Q->front = Q->rear = -1;
    Q->data = (int *)malloc((Q->maxsize)*sizeof(int));
    for (V = 0; V < N; V++)
    {
        if (!indegree[V])
        {
            Enqueue(Q, V);
        }
    }
    while (!IsEmpty(Q))
    {
        V = Dequeue(Q);

        for (i = 0; i < count; i++)
        {
            if (Graph[finish[i]][V] != INFINITY && Graph[finish[i]][V] + earliest[finish[i]] > earliest[V])
            {
                earliest[V] = Graph[finish[i]][V] + earliest[finish[i]];
            }
        }

        finish[count++] = V;

        for (W = 0; W < N; W++)
        {
            if (W == V || Graph[V][W] == INFINITY)
            {
                // W不是V的邻接点
                continue;
            }
            if (--indegree[W] == 0)
            {
                Enqueue(Q, W);
            }
        }
    }
    if (count != N)
    {
        // 说明有回路
        flag = 0;
    }
    return;
}

void BuildGraph()
{
    int i, j;
    int v, w, t;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == j)
            {
                Graph[i][j] = 0;
            }
            else
            {
                Graph[i][j] = INFINITY;
            }
        }
    }
    for (i = 0; i < M; i++)
    {
        scanf("%d %d %d", &v, &w, &t);
        Graph[v][w] = t;
        indegree[w]++;
        outdegree[v]++;
    }

    return;
}

void PrintSumTime()
{
    int V, finishtime = 0;
    for (V = 0; V < N; V++)
    {
        if (!outdegree[V] && earliest[V] > finishtime)
        {
            finishtime = earliest[V];
        }
    }
    printf("%d\n", finishtime);
    return;
}

int main()
{
    scanf("%d %d", &N, &M);

    BuildGraph();

    // 进行一次拓扑排序，顺便检查是否有回路
    TopSort();

    if (flag)
    {
        PrintSumTime();
    }
    else
    {
        printf("Impossible\n");
    }

    return 0;
}
