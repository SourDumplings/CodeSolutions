/*
 @Date    : 2017-11-29 09:41:49
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

int DFS(int S, int D, int N, int occupied)
{
    if (G_temp[S][D])
    {
        return 0;
    }
    int i;
    int needrepair = 1;
    for (i = 0; i < N; i++)
    {
        if (i == occupied || visited[i])
        {
            continue;
        }
        if (G_temp[S][i])
        {
            visited[i] = 1;
            needrepair = DFS(i, D, N, occupied);
        }
        if (needrepair == 0)
        {
            break;
        }
    }
    return needrepair;
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
    int repair;
    int flag = 0;
    for (i = 0; i < K; i++)
    {
        occupied = checklist[i] - 1;
        repair = 0;
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
        // 考察需要修建的道路的条数
        for (j = 0; j < N; j++)
        {
            if (j == occupied)
            {
                continue;
            }
            for (k = j + 1; k < N; k++)
            {
                if (k == occupied)
                {
                    continue;
                }
                else
                {
                    InitializeVisit(N);
                    visited[j] = 1;
                    flag = DFS(j, k, N, occupied);
                    repair += flag;
                    if (flag)
                    {
                        G_temp[j][k] = G_temp[k][j] = 1;
                    }
                }
            }
        }
        printf("%d\n", repair);
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
    SolveAndOutPut(N, checklist, K);
    return 0;
}

