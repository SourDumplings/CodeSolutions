/*
 @Date    : 2018-02-14 16:12:47
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1076
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

static const int MAXN = 1001;
static int N, L;
static int G[MAXN][MAXN];
static int dist[MAXN];
static const int INF = 999999;
static bool set[MAXN];

int get_min_dist()
{
    int min_dist = INF, min_dist_v = -1;
    for (int v = 0; v != N; ++v)
    {
        if (!set[v] && dist[v] < min_dist)
        {
            min_dist = dist[v];
            min_dist_v = v;
        }
    }
    return min_dist_v;
}

void Dijkstra(int s)
{
    dist[s] = 0;
    while (true)
    {
        int v = get_min_dist();
        if (v == -1)
            break;
        set[v] = true;
        for (int w = 0; w != N; ++w)
        {
            if (G[v][w] != INF && G[v][w] + dist[v] < dist[w])
                dist[w] = G[v][w] + dist[v];
        }
    }
    return;
}

int get_follower_num()
{
    int res = 0;
    for (int i = 0; i != N; ++i)
    {
        if (dist[i] <= L)
            ++res;
    }
    return res > 0 ? res - 1 : 0;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &L);
    for (int i = 0; i != MAXN; i++)
    {
        for (int j = 0; j != MAXN; j++)
            G[i][j] = INF;
    }
    for (int i = 0; i != N; ++i)
    {
        int M, u;
        scanf("%d", &M);
        while (M--)
        {
            scanf("%d", &u);
            G[u-1][i] = 1;
        }
    }
    int Q;
    scanf("%d", &Q);
    int poster;
    while (Q--)
    {
        scanf("%d", &poster);
        fill(dist, dist+N, INF);
        fill(set, set+N, false);
        Dijkstra(poster-1);
        int res = get_follower_num();
        printf("%d\n", res);
    }
    return 0;
}
