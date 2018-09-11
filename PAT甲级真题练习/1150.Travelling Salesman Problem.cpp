/*
 @Date    : 2018-09-11 09:04:28
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/1038430013544464384
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 210, INF = 9999999;
int N, M, K;
bool visited[MAXN];
int G[MAXN][MAXN];

bool simple = true, ts = true;
int thisVNum = 0, thisD = 0, minD = INF, minP = -1;

bool go()
{
    thisD = 0;
    fill(visited + 1, visited + N + 1, false);
    simple = ts = true;
    int n;
    cin >> n;
    int last;
    cin >> last;
    int first = last;
    thisVNum = 1;
    visited[last] = true;
    bool ret = true;
    for (int i = 1; i != n; ++i)
    {
        int c;
        cin >> c;
        if (ret)
        {
            if (i == n - 1)
            {
                if (c != first)
                {
                    ts = false;
                }
            }
            if (G[last][c] == INF)
            {
                ret = false;
            }
            if (ret)
            {
                thisD += G[last][c];
                if (!visited[c])
                {
                    visited[c] = true;
                    ++thisVNum;
                }
                else if (i < n - 1)
                {
                    simple = false;
                }
            }
            last = c;
        }
    }
    for (int i = 1; i != N + 1; ++i)
    {
        if (!visited[i])
        {
            ts = false;
            break;
        }
    }
    return ret;
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i != N + 1; ++i)
        for (int j = 1; j != N + 1; ++j)
            G[i][j] = INF;
    for (int i = 0; i != M; ++i)
    {
        int v, w, d;
        scanf("%d %d %d", &v, &w, &d);
        G[v][w] = G[w][v] = d;
    }
    cin >> K;
    for (int i = 1; i != K + 1; ++i)
    {
        if (go())
        {
            if (thisVNum == N && ts)
            {
                if (simple)
                {
                    printf("Path %d: %d (TS simple cycle)\n", i, thisD);
                }
                else
                    printf("Path %d: %d (TS cycle)\n", i, thisD);
                if (thisD < minD)
                {
                    minP = i;
                    minD = thisD;
                }
            }
            else
                printf("Path %d: %d (Not a TS cycle)\n", i, thisD);
        }
        else
            printf("Path %d: NA (Not a TS cycle)\n", i);
    }
    printf("Shortest Dist(%d) = %d\n", minP, minD);
    return 0;
}


