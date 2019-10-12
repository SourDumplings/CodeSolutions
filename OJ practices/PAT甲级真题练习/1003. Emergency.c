/*
 @Date    : 2017-11-27 09:16:33
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1003
 */

#include <stdio.h>

#define MAXN 500
#define INFINITY 99999
#define ERROR -1

int G[MAXN][MAXN];
int teamnum[MAXN];
int N, M, C1, C2;
int dist[MAXN];
int collected[MAXN];
int path[MAXN];
int shortest_dist = INFINITY;
int shortest_num = 0;
int max_carry = 0;
int flag = 1;

void InitializeAndBuildGraph(void)
{
    int i, j;
    int c1, c2, L;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == j)
            {
                G[i][j] = 0;
            }
            else
            {
                G[i][j] = INFINITY;
            }
        }
        collected[i] = 0;
        path[i] = -1;
    }
    for (i = 0; i < M; i++)
    {
        scanf("%d %d %d", &c1, &c2, &L);
        G[c1][c2] = L;
        G[c2][c1] = L;
    }
    return;
}

int FindMinDist(void)
{
    int V, min = INFINITY, min_V;
    for (V = 0; V < N; V++)
    {
        if (collected[V] == 0 && dist[V] < min)
        {
            min = dist[V];
            min_V = V;
        }
    }
    if (min == INFINITY)
    {
        min_V = ERROR;
    }
    return min_V;
}

void Dijkistra(void)
{
    int V, W;
    dist[C1] = 0;
    collected[C1] = 1;
    for (V = 0; V < N; V++)
    {
        dist[V] = G[C1][V];
    }
    while (1)
    {
        V = FindMinDist();
        // printf("$$Uncollected city with the shortest_dist is %d.$$\n", V);
        if (V == ERROR)
        {
            break;
        }
        collected[V] = 1;
        for (W = 0; W < N; W++)
        {
            if (collected[W] == 0 && G[V][W] < INFINITY)
            {
                if (G[V][W] < 0)
                {
                    // 有负边，无法正确解决
                    flag = 0;
                    return;
                }
                if (dist[V] + G[V][W] < dist[W])
                {
                    dist[W] = dist[V] + G[V][W];
                    path[W] = V;
                }
            }
        }
    }
    return;
}

void GetNumMinDistPathsAndCarryMaxTeams(int D, int last_carry)
{
    int S;
    int now_carry = last_carry + teamnum[D];
    if (now_carry > max_carry)
    {
        max_carry = now_carry;
    }
    if (D == C1)
    {
        shortest_num++;
        return;
    }

    for (S = 0; S < N; S++)
    {
        if (S != D && G[S][D] + dist[S] == dist[D])
        {
            GetNumMinDistPathsAndCarryMaxTeams(S, now_carry);
        }
    }
}

int main()
{
    scanf("%d %d %d %d", &N, &M, &C1, &C2);
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &teamnum[i]);
    }
    InitializeAndBuildGraph();
    // printf("$$InitializeAndBuildGraph finished!$$\n");
    Dijkistra();
    // printf("$$Dijkistra finished!$$\n");
    shortest_dist = dist[C2];
    // printf("$$After Dijkistra, the shortest_dist = %d.$$\n", shortest_dist);
    GetNumMinDistPathsAndCarryMaxTeams(C2, 0);
    printf("%d %d\n", shortest_num, max_carry);
    return 0;
}

