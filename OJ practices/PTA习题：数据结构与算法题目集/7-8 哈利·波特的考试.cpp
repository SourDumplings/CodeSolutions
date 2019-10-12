/*
 @Date    : 2018-03-11 11:43:30
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/716
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

static const int MAXN = 101;
static int G[MAXN][MAXN];
static const int INF = 999999;
static int N, M;
static int dist[MAXN];
static bool checked[MAXN];

int find_min_dist()
{
    int minDist = INF, minV = -1;
    for (int i = 0; i != N; ++i)
    {
        if (!checked[i] && dist[i] < minDist)
        {
            minDist = dist[i];
            minV = i;
        }
    }
    return minV;
}

void Dijkstra(int s)
{
    fill(checked, checked+N, false);
    dist[s] = 0;
    while (true)
    {
        int v = find_min_dist();
        checked[v] = true;
        if (v == -1)
            break;
        for (int w = 0; w != N; ++w)
        {
            if (!checked[w] && G[v][w] != INF && dist[v] + G[v][w] < dist[w])
                dist[w] = dist[v] + G[v][w];
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i != N; ++i)
        for (int j = 0; j != N; ++j)
            G[i][j] = INF;
    for (int i = 0; i != M; ++i)
    {
        int v, w, d;
        scanf("%d %d %d", &v, &w, &d);
        G[v-1][w-1] = G[w-1][v-1] = d;
    }
    int minMaxD = INF, animal = 0;
    for (int s = 0; s != N; ++s)
    {
        fill(dist, dist+N, INF);
        Dijkstra(s);
        int maxD = *max_element(dist, dist+N);
        if (maxD < minMaxD)
        {
            minMaxD = maxD;
            animal = s + 1;
        }
    }
    if (animal != 0)
        printf("%d %d\n", animal, minMaxD);
    else
        printf("0\n");
    return 0;
}

