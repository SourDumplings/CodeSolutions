/*
 @Date    : 2018-08-26 20:53:16
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805464397627392
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N, M, S, D;
const int MAXN = 505, INF = 999999;
int Gd[MAXN][MAXN], Gc[MAXN][MAXN];
int dist[MAXN];
bool visited[MAXN];

int find_min_dist()
{
    int minV = -1, minD = INF;
    for (int i = 0; i != N; ++i)
    {
        if (!visited[i] && dist[i] < minD)
        {
            minD = dist[i];
            minV = i;
        }
    }
    return minV;
}

void Dijkstra(int s)
{
    dist[s] = 0;
    while (true)
    {
        int v = find_min_dist();
        if (v == -1)
            break;
        visited[v] = true;
        for (int w = 0; w != N; ++w)
        {
            if (!visited[w] && Gd[v][w] != INF && dist[v] + Gd[v][w] < dist[w])
            {
                dist[w] = dist[v] + Gd[v][w];
            }
        }
    }
    return;
}

vector<int> thisPath, resPath;
int thisCost = 0, minCost = INF;

void dfs(int d)
{
    thisPath.push_back(d);
    if (d == S)
    {
        if (thisCost < minCost)
        {
            minCost = thisCost;
            resPath = thisPath;
        }
        thisPath.pop_back();
        return;
    }
    else
    {
        for (int s = 0; s != N; ++s)
        {
            if (Gd[s][d] != INF && dist[s] + Gd[s][d] == dist[d])
            {
                thisCost += Gc[s][d];
                dfs(s);
                thisCost -= Gc[s][d];
            }
        }
    }
    thisPath.pop_back();
    return;
}

int main()
{
    scanf("%d %d %d %d", &N, &M, &S, &D);
    for (int i = 0; i != N; ++i)
    {
        dist[i] = INF;
        visited[i] = false;
        for (int j = 0; j != N; ++j)
            Gd[i][j] = Gc[i][j] =  INF;
    }

    for (int i = 0; i != M; ++i)
    {
        int c1, c2, d, c;
        scanf("%d %d %d %d", &c1, &c2, &d, &c);
        Gd[c1][c2] = Gd[c2][c1] = d;
        Gc[c1][c2] = Gc[c2][c1] = c;
    }

    Dijkstra(S);

    dfs(D);

    int output = 0;
    for (auto it = resPath.rbegin(); it != resPath.rend(); ++it)
    {
        if (output++)
            putchar(' ');
        printf("%d", *it);
    }
    printf(" %d %d\n", dist[D], minCost);

    return 0;
}
