/*
 @Date    : 2018-03-15 12:10:00
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/862
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

static const int MAXN = 501, INF = 999999;
static int G[MAXN][MAXN];
static int N, M, S, D;
static int secureNum[MAXN];
static int dist[MAXN];
static bool checked[MAXN];

int find_min_dist()
{
    int minV = -1, minD = INF;
    for (unsigned i = 0; i < N; ++i)
    {
        if (!checked[i] && dist[i] < minD)
        {
            minD = dist[i];
            minV = i;
        }
    }
    return minV;
}

void Dijkstra()
{
    fill(dist, dist + N, INF);
    fill(checked, checked + N, false);
    dist[S] = 0;
    while (true)
    {
        int v = find_min_dist();
        if (v == -1)
        {
            break;
        }
        checked[v] = true;
        for (unsigned w = 0; w < N; ++w)
        {
            if (!checked[w] && G[v][w] != INF && dist[w] > dist[v] + G[v][w])
                dist[w] = dist[v] + G[v][w];
        }
    }
    return;
}

static vector<int> thisPath, resPath;
static int thisSecureNum = 0, maxSecureNum = 0, shortestPathNum = 0;

void DFS(int d)
{
    checked[d] = true;
    thisSecureNum += secureNum[d];
    thisPath.push_back(d);
    if (d == S)
    {
        if (thisSecureNum > maxSecureNum)
        {
            maxSecureNum = thisSecureNum;
            resPath = thisPath;
        }
        ++shortestPathNum;
    }
    else
    {
        for (unsigned s = 0; s < N; ++s)
        {
            if (!checked[s] && G[s][d] != INF && dist[s] == dist[d] - G[s][d])
                DFS(s);
        }
    }
    checked[d] = false;
    thisSecureNum -= secureNum[d];
    thisPath.pop_back();
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d %d", &N, &M, &S, &D);
    for (int i = 0; i != N; ++i)
        for (int j = 0; j != N; ++j)
            G[i][j] = INF;
    for (unsigned i = 0; i < N; ++i)
    {
        scanf("%d", &secureNum[i]);
    }
    for (unsigned i = 0; i < M; ++i)
    {
        int v, w, d;
        scanf("%d %d %d", &v, &w, &d);
        G[v][w] = G[w][v] = d;
    }
    Dijkstra();
    fill(checked, checked + N, false);
    DFS(D);
    printf("%d %d\n", shortestPathNum, maxSecureNum);
    int output = 0;
    for (int i = resPath.size() - 1; i != -1; --i)
    {
        if (output++)
        {
            putchar(' ');
        }
        cout << resPath[i];
    }
    cout << endl;
    return 0;
}

