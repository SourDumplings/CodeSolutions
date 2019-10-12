#include <stdio.h>
#include <stdlib.h>

#define MAXN 100
#define INFINITY 999999
#define ERROR -1

int N, M, Graph[MAXN][MAXN];
int earliest[MAXN] = {0};
int latest[MAXN];
int indegree[MAXN] = {0};
int outdegree[MAXN] = {0};
int count = 0;
int finished[MAXN]; // 已经完成的结点，即其按照拓扑顺序存储的

typedef struct QUEUE *Queue;
struct QUEUE
{
    int maxsize;
    int data[MAXN];
    int front, rear;
};

int IsFull(Queue Q)
{
    return (Q->rear + 1) % Q->maxsize == Q->front;
}

int IsEmpty(Queue Q)
{
    return Q->rear == Q->front;
}

void AddQ(Queue Q, int X)
{
    if (!IsFull(Q))
    {
        Q->rear = (Q->rear + 1) % Q->maxsize;
        Q->data[Q->rear] = X;
    }
    return;
}

int DeleteQ(Queue Q)
{
    if (!IsEmpty(Q))
    {
        Q->front = (Q->front + 1) % Q->maxsize;
        return Q->data[Q->front];
    }
    else
    {
        return ERROR;
    }
}

void BuildGraph()
{
    int V, W;
    int i, t;
    for (V = 0; V < N; V++)
    {
        for (W = 0; W < N; W++)
        {
            if (V == W)
            {
                Graph[V][W] = 0;
            }
            else
            {
                Graph[V][W] = INFINITY;
            }
        }
    }

    for (i = 0; i < M; i++)
    {
        scanf("%d %d %d", &V, &W, &t);
        Graph[V-1][W-1] = t;
        indegree[W-1]++;
        outdegree[V-1]++;
    }
    return;
}

void TopSort()
{
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QUEUE));
    Q->maxsize = N;
    Q->rear = Q->front = -1;

    int indegree_temp[N];

    int i, j, V, W;
    for (i = 0; i < N; i++)
    {
        indegree_temp[i] = indegree[i];
    }

    for (V = 0; V < N; V++)
    {
        if (!indegree_temp[V])
        {
            AddQ(Q, V);
        }
    }
    while (!IsEmpty(Q))
    {
        V = DeleteQ(Q);
        for (W = 0; W < N; W++)
        {
            if (W == V || Graph[V][W] == INFINITY)
            {
                // W不是V的下一个邻接点
                continue;
            }
            if (--indegree_temp[W] == 0)
            {
                AddQ(Q, W);
            }
        }
        for (i = 0; i < count; i++)
        {
            if (Graph[finished[i]][V] != INFINITY && Graph[finished[i]][V] + earliest[finished[i]] > earliest[V])
            {
                earliest[V] = Graph[finished[i]][V] + earliest[finished[i]];
            }
        }
        finished[count++] = V;
    }

    if (count != N)
    {
        // 说明有回路
        printf("0\n");
        return;
    }

    // 计算整个工程的最早完成时间并打印
    int maxearliest = 0;
    for (i = 0; i < N; i++)
    {
        if (!outdegree[i] && earliest[i] > maxearliest)
        {
            maxearliest = earliest[i];
        }
    }
    printf("%d\n", maxearliest);

    // 得到最晚开始时间
    // 边的指向为j到i
    for (i = N - 1; i >= 0; i--)
    {
        // 将所有的终止点的最晚完成时间都设置为整个工程的最早结束时间
        if (!outdegree[finished[i]])
        {
            latest[finished[i]] = maxearliest;
        }
        // 得到其他的点的最晚完成时间
        for (j = i - 1; j >= 0; j--)
        {
            if (Graph[finished[j]][finished[i]] != INFINITY &&
                latest[finished[i]] - Graph[finished[j]][finished[i]] < latest[finished[j]])
            {
                latest[finished[j]] = latest[finished[i]] - Graph[finished[j]][finished[i]];
            }
        }
    }
    return;
}

void PrintKeyActivity()
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        if (earliest[i] == latest[i])
        {
            // 关键路径上的点的最早开始时间和最晚开始时间肯定是相等的
            // 找到每一条关键路径的开始结点，打印下一个结点就可以了
            for (j = N - 1; j >= 0; j--)
            {
                if (j != i && Graph[i][j] != INFINITY && earliest[j] == latest[j] && (latest[j] - earliest[i] == Graph[i][j]))
                {
                    printf("%d->%d\n", i+1, j+1);
                }
            }
        }
    }
    return;
}

int main()
{
    int i;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
    {
        latest[i] = INFINITY;
    }
    BuildGraph();
    TopSort();
    // 打印关键活动
    PrintKeyActivity();
    return 0;
}
