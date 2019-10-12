/*
 @Date    : 2018-03-15 12:35:59
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/863
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

static const int MAXN = 1001, INF = 999999;
static bool G[MAXN][MAXN];
static int N, M;
static int dist[MAXN];
static bool checked[MAXN];

void BFS(int s)
{
    fill(dist, dist+N, INF);
    fill(checked, checked+N, false);
    queue<int> Q;
    dist[s] = 0;
    Q.push(s);
    checked[s] = true;
    while (!Q.empty())
    {
        int v = Q.front(); Q.pop();
        // printf("dist[%d] = %d\n", v, dist[v]);
        for (unsigned w = 0; w < N; ++w)
        {
            if (!checked[w] && G[v][w])
            {
                dist[w] = dist[v] + 1;
                Q.push(w);
                checked[w] = true;
            }
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    for (unsigned i = 0; i < N; ++i)
    {
        for (unsigned j = 0; j < N; ++j)
        {
            G[i][j] = false;
        }
    }
    for (unsigned i = 0; i < M; ++i)
    {
        int v, w;
        scanf("%d %d", &v, &w);
        G[v-1][w-1] = G[w-1][v-1] = true;
    }
    int K;
    bool connected = true;
    scanf("%d", &K);
    for (unsigned i = 0; i < K; ++i)
    {
        int s;
        scanf("%d", &s);
        BFS(s-1);
        int sum = 0;
        if (connected)
        {
            for (int d = 0; d < N; ++d)
            {
                if (dist[d] == INF)
                {
                    connected = false;
                    sum = 0;
                    goto FLAG;
                }
                sum += dist[d];
            }
            printf("Cc(%d)=%.2f\n", s, static_cast<double>(N - 1) / sum);
        }
        else
FLAG:
            printf("Cc(%d)=0.00\n", s);
    }
    return 0;
}

