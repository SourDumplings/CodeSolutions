/*
 @Date    : 2018-03-12 09:18:08
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/717
 */

#include <iostream>
#include <cstdio>

using namespace std;

static int N, M, S, D;
static const int MAXN = 501, INF = 999999;
static int Gd[MAXN][MAXN], Gp[MAXN][MAXN];

static int dist[MAXN];
static bool visited[MAXN];

int find_min_dist()
{
    int minV = -1, minD = INF;
    for (int v = 0; v != N; ++v)
    {
        if (!visited[v] && dist[v] < minD)
        {
            minD = dist[v];
            minV = v;
        }
    }
    return minV;
}

void Dijstra()
{
    fill(dist, dist+N, INF);
    fill(visited, visited+N, false);
    dist[S] = 0;
    while (true)
    {
        int v = find_min_dist();
        if (v == -1) break;
        visited[v] = true;
        for (int w = 0; w != N; ++w)
        {
            if (!visited[w] && Gd[v][w] != INF && Gd[v][w] + dist[v] < dist[w])
                dist[w] = Gd[v][w] + dist[v];
        }
    }
    return;
}

static int minP = INF, thisP = 0;

void DFS(int d)
{
    if (d == S)
    {
        if (thisP < minP)
            minP = thisP;
        return;
    }
    for (int s = 0; s != N; ++s)
    {
        if (!visited[s] && Gd[s][d] != INF && dist[s] + Gd[s][d] == dist[d] &&
            Gp[s][d] + thisP <= minP)
        {
            thisP += Gp[s][d];
            DFS(s);
            thisP -= Gp[s][d];
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d %d", &N, &M, &S, &D);
    for (int i = 0; i != N; ++i)
        for (int j = 0; j != N; ++j)
            Gd[i][j] = Gp[i][j] = INF;
    for (int i = 0; i != M; ++i)
    {
        int v, w, d, p;
        scanf("%d %d %d %d", &v, &w, &d, &p);
        Gd[v][w] = Gd[w][v] = d;
        Gp[v][w] = Gp[w][v] = p;
    }
    Dijstra();
    fill(visited, visited+N, false);
    DFS(D);
    printf("%d %d\n", dist[D], minP);
    return 0;
}

