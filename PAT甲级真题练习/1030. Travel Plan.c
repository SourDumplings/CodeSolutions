/*
 @Date    : 2017-12-03 12:09:31
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1030
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 500
#define INFINITY 99999
#define ERROR -1

int D[MAXN][MAXN];
int C[MAXN][MAXN];
int dist[MAXN];
int path[MAXN];
int temppath[MAXN];
int mincost = INFINITY, thiscost = 0;
int visited[MAXN];

void InitializedVisit(int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        visited[i] = 0;
    }
    return;
}

int FindMinDist(int N)
{
    int i, mindist = INFINITY, min_V;
    for (i = 0; i < N; i++)
    {
        if (!visited[i] && dist[i] < mindist)
        {
            mindist = dist[i];
            min_V = i;
        }
    }
    if (mindist == INFINITY)
    {
        min_V = ERROR;
    }
    return min_V;
}

void Dijkstra(int s, int N)
{
    visited[s] = 0;
    int i;
    for (i = 0; i < N; i++)
    {
        dist[i] = INFINITY;
    }
    dist[s] = 0;

    int V, W;
    while (1)
    {
        V = FindMinDist(N);
        if (V == ERROR)
        {
            break;
        }
        visited[V] = 1;
        for (W = 0; W < N; W++)
        {
            if (!visited[W] && D[V][W] + dist[V] < dist[W])
            {
                dist[W] = D[V][W] + dist[V];
            }
        }
    }
    return;
}

void RecordPath(int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        path[i] = temppath[i];
    }
    return;
}

void DFS(int d, int s, int N)
{
    if (d == s)
    {
        if (thiscost < mincost)
        {
            mincost = thiscost;
            RecordPath(N);
        }
        return;
    }
    int V;
    visited[d] = 1;
    int tempcost = thiscost;
    for (V = 0; V < N; V++)
    {
        thiscost = tempcost;
        if (!visited[V] && dist[V] + D[V][d] == dist[d])
        {
            thiscost += C[V][d];
            temppath[V] = d;
            DFS(V, s, N);
            InitializedVisit(N);
            visited[d] = visited[V] = 1;
        }
    }
}

int main()
{
    int N, M, s, d;
    scanf("%d %d %d %d", &N, &M, &s, &d);
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            D[i][j] = C[i][j] = INFINITY;
        }
    }
    int V, W, tempd, cost;
    for (i = 0; i < M; i++)
    {
        scanf("%d %d %d %d", &V, &W, &tempd, &cost);
        D[V][W] = D[W][V] = tempd;
        C[V][W] = C[W][V] = cost;
    }

    InitializedVisit(N);
    Dijkstra(s, N);

    InitializedVisit(N);
    DFS(d, s, N);

    int output = 0;
    while (1)
    {
        if (output++)
        {
            putchar(' ');
        }
        printf("%d", s);
        if (s == d)
        {
            break;
        }
        s = path[s];
    }
    printf(" %d %d\n", dist[d], mincost);
    return 0;
}

