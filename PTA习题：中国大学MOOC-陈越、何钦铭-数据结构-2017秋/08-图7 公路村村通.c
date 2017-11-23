#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000
#define INFINITY 999999
#define ERROR -1

int N, M;
int Graph[MAXN][MAXN];

void BuildGraph()
{
    int i, j;
    int V, W, c;
    int flag = 1;
    if (M < N - 1)
    {
        flag = 0;
    }
    if (flag)
    {
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
    }
    for (i = 0; i < M; i++)
    {
        scanf("%d %d %d", &V, &W, &c);
        if (flag)
        {
            Graph[V-1][W-1] = Graph[W-1][V-1] = c;
        }
    }
    return;
}


int FindMinDist(int dist[])
{
    int MinV, V;
    int MinDist = INFINITY;
    for (V = 0; V < N; V++)
    {
        if (dist[V] && dist[V] < MinDist)
        {
            MinDist = dist[V];
            MinV = V;
        }
    }
    if (MinDist < INFINITY) // 若是找到最小的dist
    {
        return MinV;
    }
    else // 若是这样的顶点不存在，返回ERROR
    {
        return ERROR;
    }
}

void Prim()
{
    int dist[N];
    int V, W;
    int totalweight;
    int Vcount;

    // MST = {s}, 即初始化
    for (V = 0; V < N; V++)
    {
        dist[V] = Graph[0][V];
    }

    // 初始化权重和
    totalweight = 0;

    // 初始化收录的顶点数
    Vcount = 0;

    // 将初始点0收录进MST
    dist[0] = 0;
    Vcount++;

    while (1)
    {
        V = FindMinDist(dist);
        if (V == ERROR)
        {
            break;
        }
        // 将V收录进MST
        totalweight += dist[V];
        dist[V] = 0;
        Vcount++;

        for (W = 0; W < N; W++)
        {
            if (dist[W] != 0)
            {
                if (Graph[V][W] < dist[W])
                {
                    dist[W] = Graph[V][W];
                }
            }
        }
    }
    if (Vcount < N)
    {
        printf("%d\n", ERROR);
    }
    else
    {
        printf("%d\n", totalweight);
    }
    return;
}

int main()
{
    scanf("%d %d", &N, &M);
    BuildGraph();
    Prim();
    return 0;
}
