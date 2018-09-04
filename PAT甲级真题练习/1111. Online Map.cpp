/*
 @Date    : 2018-09-04 23:41:58
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805358663417856
注意在计算距离最短路径中时间最短路径时，时间需要重新设变量存储
因为时间最短的路径并非与距离最短路径重合
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
const int MAXN = 510, INF = 999999;
int D[MAXN][MAXN], T[MAXN][MAXN];
int dists[MAXN], times[MAXN];
int s, d;
bool checked[MAXN];

int find_min(int data[])
{
    int minV = -1, minD = INF;
    for (int i = 0; i != N; ++i)
    {
        if (!checked[i] && data[i] < minD)
        {
            minD = data[i];
            minV = i;
        }
    }
    return minV;
}

void Dijkstra(int G[][MAXN], int data[])
{
    data[s] = 0;
    fill(checked, checked+N, false);
    while (true)
    {
        int v = find_min(data);
        if (v == -1)
            break;
        checked[v] = true;
        for (int w = 0; w != N; ++w)
        {
            if (!checked[w] && G[v][w] != INF && data[v] + G[v][w] < data[w])
                data[w] = data[v] + G[v][w];
        }
    }
    return;
}

vector<int> thisDPath, resDPath, thisTPath, resTPath;
int thisTime = 0, minTime = INF;

void dfs_D(int w)
{
    thisDPath.push_back(w);
    if (w == s)
    {
        if (thisTime < minTime)
        {
            minTime = thisTime;
            resDPath = thisDPath;
        }
    }
    else
    {
        for (int v = 0; v != N; ++v)
        {
            if (D[v][w] != INF && dists[w] == D[v][w] + dists[v])
            {
                thisTime += T[v][w];
                dfs_D(v);
                thisTime -= T[v][w];
            }
        }
    }
    thisDPath.pop_back();
    return;
}

void dfs_T(int w)
{
    thisTPath.push_back(w);
    if (w == s)
    {
        if (resTPath.empty() || thisTPath.size() < resTPath.size())
            resTPath = thisTPath;
    }
    else
    {
        for (int v = 0; v != N; ++v)
        {
            if (T[v][w] != INF && T[v][w] + times[v] == times[w])
                dfs_T(v);
        }
    }
    thisTPath.pop_back();
    return;
}

void output_path(vector<int> &path)
{
    int output = 0;
    for (auto it = path.rbegin(); it != path.rend(); ++it)
    {
        if (output++)
            printf(" -> ");
        printf("%d", *it);
    }
    return;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i != N; ++i)
    {
        times[i] = dists[i] = INF;
        for (int j = 0; j != N; ++j)
            D[i][j] = T[i][j] = INF;
    }
    for (int i = 0; i != M; ++i)
    {
        int v1, v2, o, l, t;
        scanf("%d %d %d %d %d", &v1, &v2, &o, &l, &t);
        D[v1][v2] = l;
        T[v1][v2] = t;
        if (o == 0)
        {
            D[v2][v1] = l;
            T[v2][v1] = t;
        }
    }
    scanf("%d %d", &s, &d);
    Dijkstra(D, dists);
    Dijkstra(T, times);
    dfs_D(d);
    dfs_T(d);
    if (resDPath == resTPath)
    {
        printf("Distance = %d; Time = %d: ", dists[d], times[d]);
        output_path(resDPath);
    }
    else
    {
        printf("Distance = %d: ", dists[d]);
        output_path(resDPath);
        putchar('\n');
        printf("Time = %d: ", times[d]);
        output_path(resTPath);
    }
    putchar('\n');

    return 0;
}

