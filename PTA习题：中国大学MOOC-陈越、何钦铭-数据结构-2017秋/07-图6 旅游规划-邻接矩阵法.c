#include <stdio.h>

#define INFINITY 999999
#define MAXN 500

int dist[MAXN];
int cost[MAXN];
int collected[MAXN] = {0};
int Graph[MAXN][MAXN];
int Price[MAXN][MAXN];

void BuildGraph(int N, int M)
{
    int i, j;
    int V, W, d, c;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == j)
            {
                Graph[i][j] = Price[i][j] = 0;
            }
            else
            {
                Graph[i][j] = Price[i][j] = INFINITY;
            }
        }
    }

    for (i = 0; i < M; i++)
    {
        scanf("%d %d %d %d", &V, &W, &d, &c);
        Graph[V][W] = Graph[W][V] = d;
        Price[V][W] = Price[W][V] = c;
    }
    return;
}

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

void Dijkstra(int N, int S)
{
    int V, W;
    dist[S] = cost[S] = 0;
    while (1)
    {
        V = FindMinDist(N);
        if (V == -1)
        {
            break;
        }
        collected[V] = 1;
        for (W = 0; W < N; W++)
        {
            if (dist[V] + Graph[V][W] < dist[W])
            {
                dist[W] = dist[V] + Graph[V][W];
                cost[W] = cost[V] + Price[V][W];
            }
            else if ((dist[V] + Graph[V][W] == dist[W]) &&
                (cost[V] + Price[V][W] < cost[W]))
            {
                cost[W] = cost[V] + Price[V][W];
            }
        }
    }
    return;
}


int main()
{
    int N, M, S, D;
    int i;
    scanf("%d %d %d %d", &N, &M, &S, &D);
    for (i = 0; i < N; i++)
    {
        dist[i] = cost[i] = INFINITY;
    }
    BuildGraph(N, M);
    Dijkstra(N, S);
    printf("%d %d\n", dist[D], cost[D]);
    return 0;
}
