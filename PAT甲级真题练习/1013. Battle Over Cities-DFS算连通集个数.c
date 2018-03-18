/*
 @Date    : 2017-11-29 11:07:53
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1013
 */

#include <stdio.h>

#define MAXN 1000

int G[MAXN][MAXN];
int G_temp[MAXN][MAXN];
int visited[MAXN];

void DFS(int S, int N)
{
    visited[S] = 1;
    int D;
    for (D = 0; D < N; D++)
    {
        if (!visited[D] && G_temp[S][D])
        {
            DFS(D, N);
        }
    }
    return;
}

void InitializeVisit(int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        visited[i] = 0;
    }
    return;
}

void SolveAndOutPut(int N, int checklist[], int K)
{
    int i, j, k;
    int occupied;
    int connectingset = 0;
    for (i = 0; i < K; i++)
    {
        occupied = checklist[i] - 1;
        connectingset = 0;
        // 初始化临时图
        for (j = 0; j < N; j++)
        {
            for (k = 0; k < N; k++)
            {
                G_temp[j][k] = G[j][k];
            }
        }
        // 被占据的城市所有出入边都为0
        for (j = 0; j < N; j++)
        {
            G_temp[occupied][j] = 0;
            G_temp[j][occupied] = 0;
        }
        // 考察需要修建的道路的条数，即为连通集的个数-1
        InitializeVisit(N);
        for (j = 0; j < N; j++)
        {
            if (visited[j] || j == occupied)
            {
                continue;
            }
            connectingset++;
            DFS(j, N);
        }
        printf("%d\n", connectingset-1);
    }
    return;
}

int main()
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            G[i][j] = 0;
        }
    }
    int V, W;
    for (i = 0; i < M; i++)
    {
        scanf("%d %d", &V, &W);
        G[V-1][W-1] = G[W-1][V-1] = 1;
    }
    int checklist[K];
    for (i = 0; i < K; i++)
    {
        scanf("%d", &checklist[i]);
    }
    if (N == 1)
    {
        printf("0\n");
    }
    else
    {
        SolveAndOutPut(N, checklist, K);
    }
    return 0;
}

