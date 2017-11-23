#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 101
#define MAX 999999999

typedef struct GRAPH *Graph;
struct GRAPH
{
    int *x;
    int *y;
};

int visit[MAXN]; // 记录每次跳跃所经过的前一个鳄鱼的下标, visit[0]代表对岸, 0代表小岛
int N, D;
int minnum = MAX; // 记录最小跳跃次数
int firstjump; // 记录第一跳的值
int minfirstjump = MAX; // 记录最小跳跃次数的逃离路径中的第一跳的最小值
int path[MAXN]; // 记录逃跑经过的鳄鱼的编号
int j = 0;
int num = 0; // 记录本次路径所需的跳跃次数

void InputPosition(Graph G, int N)
{
    int i;
    for (i = 1; i <= N; i++)
    {
        scanf("%d %d", &G->x[i], &G->y[i]);
    }
    return;
}

int Jump(Graph G, int v, int w)
{
    double d;
    d = sqrt(pow((G->x[v] - G->x[w]), 2) + pow((G->y[v] - G->y[w]), 2));
    if (!v)
    {
            firstjump = d - 7.5;
            int first_D = D + 7.5;
            if (first_D >= d)
            {
                return 1;
            }
            else
            {
                return 0;
            }
    }
    if (d <= D)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Escape(Graph G, int v)
{
    int x = G->x[v];
    int y = G->y[v];
    if (!v && D >= 42.5)
    {
        return 1;
    }
    if ((50 - x) <= D || (50 - y) <= D
        || (x + 50) <= D || (y + 50) <= D)
        return 1;
    else
        return 0;
}

void ReadPath(int i)
{
    if (visit[i])
    {
        path[j++] = visit[i];
        ReadPath(visit[i]);
    }
    return;
}

void InitializeV(int v)
{
    if (v == -1)
    {
        int i;
        for (i = 0; i <= N; i++)
        {
            visit[i] = -1;
        }
        num = 0;
    }
    else
    {
        visit[v] = -1;
        num--;
    }
    return;
}

void DFS(Graph G, int v)
{
    int w;

    // 表示最后一个踩了鳄鱼v然后逃离
    if (Escape(G, v))
        {
            num++;
            visit[0] = v;
            if (num < minnum)
            {
                minnum = num;
                minfirstjump = firstjump;
                j = 0;
                ReadPath(0);
            }
            if (num == minnum && firstjump < minfirstjump)
            {
                minfirstjump = firstjump;
                j = 0;
                ReadPath(0);
            }
            InitializeV(0);
            InitializeV(v);
            return;
        }

    for (w = 1; w <= N; w++)
    {
        if (visit[w] != -1 || w == v)
        {
            continue;
        }
        if (Jump(G, v, w))
        {
            visit[w] = v;
            num++;
            DFS(G, w);
        }
    }
    InitializeV(v);
    return;
}

void PrintPath(Graph G)
{
    int i;
    if (minnum == 1)
    {
        return;
    }
    for (i = minnum - 2; i >= 0; i--)
    {
        printf("%d %d\n", G->x[path[i]], G->y[path[i]]);
    }
    return;
}

int main()
{
    Graph G;
    int i;

    scanf("%d %d", &N, &D);

    G = (Graph)malloc(sizeof(struct GRAPH));
    G->x = (int *)malloc((N+1) * sizeof(int));
    G->y = (int *)malloc((N+1) * sizeof(int));
    G->x[0] = G->y[0] = 0;

    InputPosition(G, N);

    InitializeV(-1);

    if (Escape(G, 0))
    {
        minnum = 1;
        visit[0] = 0;
    }
    else
    {
        for (i = 1; i <= N; i++)
        {
            if (Jump(G, 0, i))
            {
                visit[i] = 0;
                num = 1;
                DFS(G, i);
            }
            InitializeV(-1);
        }
    }

    if (minnum == MAX)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n", minnum);
        PrintPath(G);
    }


    return 0;
}
