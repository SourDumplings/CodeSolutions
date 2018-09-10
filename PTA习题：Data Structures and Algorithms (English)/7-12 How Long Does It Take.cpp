/*
 @Date    : 2018-09-08 09:18:30
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/16/problems/674
 */

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int N, M;
const int MAXN = 105, INF = 9999999;
int earliestStart[MAXN];
int G[MAXN][MAXN], inDegree[MAXN];

bool top_sort()
{
    queue<int> q;
    int finishNum = 0;
    for (int i = 0; i != N; ++i)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
            earliestStart[i] = 0;
        }
    }
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        ++finishNum;
        for (int w = 0; w != N; ++w)
        {
            if (G[v][w] != INF)
            {
                if (earliestStart[w] < earliestStart[v] + G[v][w])
                    earliestStart[w] = earliestStart[v] + G[v][w];
                if (--inDegree[w] == 0)
                    q.push(w);
            }
        }
    }
    if (finishNum == N)
        return true;
    return false;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i != N; ++i)
    {
        earliestStart[i] = inDegree[i] = 0;
        for (int j = 0; j != N; ++j)
            G[i][j] = INF;
    }
    for (int i = 0; i != M; ++i)
    {
        int v, w, l;
        scanf("%d %d %d", &v, &w, &l);
        G[v][w] = l;
        ++inDegree[w];
    }
    if (top_sort())
    {
        int finishTime = 0;
        for (int i = 0; i != N; ++i)
        {
            if (earliestStart[i] > finishTime)
                finishTime = earliestStart[i];
        }
        printf("%d\n", finishTime);
    }
    else
        printf("Impossible\n");
    return 0;
}
