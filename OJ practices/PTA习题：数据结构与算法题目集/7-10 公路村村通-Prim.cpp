/*
 @Date    : 2018-03-12 10:03:03
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/718
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

static int N, M;
static const int MAXN = 1001, INF = 999999;
static int G[MAXN][MAXN];

static int minC = 0;
static int cost[MAXN];

int find_min_cost()
{
    int minD = INF, minV = -1;
    for (int v = 0; v != N; ++v)
    {
        if (cost[v] != 0 && cost[v] < minD)
        {
            minD = cost[v];
            minV = v;
        }
    }
    return minV;
}

bool Prim()
{
    fill(cost, cost+N, INF);
    cost[0] = 0;
    bool first = true;
    while (true)
    {
        int v;
        if (first)
        {
            v = 0;
            first = false;
        }
        else v = find_min_cost();
        if (v == -1) break;
        minC += cost[v];
        cost[v] = 0;
        for (int w = 0; w != N; ++w)
        {
            if (cost[w] != 0 && G[v][w] < cost[w])
                cost[w] = G[v][w];
        }
    }
    if (count(cost, cost+N, 0) != N)
        return false;
    return true;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i != N; ++i)
        for (int j = 0; j != N; ++j)
            G[i][j] = INF;
    for (int i = 0; i != M; ++i)
    {
        int v, w, c;
        scanf("%d %d %d", &v, &w, &c);
        G[v-1][w-1] = G[w-1][v-1] = c;
    }
    bool ok = Prim();
    if (ok)
        printf("%d\n", minC);
    else
        printf("-1\n");
    return 0;
}

