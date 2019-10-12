/*
 @Date    : 2018-03-17 15:52:06
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1018
注意自行车只能从前一个站点送到下一个或者直接送回PBMC，而不能往上一个站点输送。
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

static const int MAXN = 501, INF = 999999;
static int C, N, S, M;
static int G[MAXN][MAXN], bikeNum[MAXN];
static int distForTime[MAXN];

void Dijkstra(int s)
{
    fill(distForTime, distForTime + N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    distForTime[s] = 0;
    Q.push(make_pair(distForTime[0], 0));
    while (!Q.empty())
    {
        auto pV = Q.top(); Q.pop();
        if (pV.first == distForTime[pV.second])
        {
            for (unsigned w = 1; w < N + 1; ++w)
            {
                if (distForTime[w] > distForTime[pV.second] + G[pV.second][w])
                {
                    distForTime[w] = distForTime[pV.second] + G[pV.second][w];
                    Q.push(make_pair(distForTime[w], w));
                }
            }
        }
    }
    return;
}

static vector<int> thisPath, resPath;
static int thisRequireBikes = 0, minRequireBikes = INF;
static int thisReturnBikes = 0, resReturnBikes = 0;

static bool checked[MAXN];

void DFS(int d)
{
    thisPath.push_back(d);
    checked[d] = true;
    // printf("entered %d\n", d);
    if (d == 0)
    {
        if (thisRequireBikes < minRequireBikes ||
            (thisRequireBikes == minRequireBikes && thisReturnBikes < resReturnBikes))
        {
            resPath = thisPath;
            minRequireBikes = thisRequireBikes;
            resReturnBikes = thisReturnBikes;
        }
    }
    else
    {
        if (bikeNum[d] <= C / 2)
        {
            thisRequireBikes += C / 2 - bikeNum[d];
        }
        else
        {
            if (thisRequireBikes - (bikeNum[d] - C / 2) < 0)
            {
                thisReturnBikes += (bikeNum[d] - C / 2 - thisRequireBikes);
                thisRequireBikes = 0;
            }
            else
            {
                thisRequireBikes -= bikeNum[d] - C / 2;
            }
        }
        // printf("thisRequireBikes = %d, thisReturnBikes = %d\n",
               // thisRequireBikes, thisReturnBikes);
        for (unsigned s = 0; s < N + 1; ++s)
        {
            if (!checked[s] && distForTime[s] == distForTime[d] - G[s][d])
            {
                // printf("from %d\n", d);
                int tempRequireBikes = thisRequireBikes, tempReturenBikes = thisReturnBikes;
                DFS(s);
                thisRequireBikes = tempRequireBikes;
                thisReturnBikes = tempReturenBikes;
            }
        }
    }
    thisPath.pop_back();
    checked[d] = false;
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d %d", &C, &N, &S, &M);
    for (unsigned i = 1; i < N + 1; ++i)
    {
        scanf("%d", &bikeNum[i]);
    }
    for (unsigned i = 0; i < N + 1; ++i)
    {
        for (unsigned j = 0; j < N + 1; ++j)
        {
            G[i][j] = INF;
        }
    }
    for (unsigned i = 0; i < M; ++i)
    {
        int v, w, t;
        scanf("%d %d %d", &v, &w, &t);
        G[v][w] = G[w][v] = t;
    }
    Dijkstra(0);
    fill(checked, checked + N + 1, false);
    DFS(S);
    printf("%d ", minRequireBikes);
    int output = 0;
    for (auto it = resPath.rbegin(); it != resPath.rend(); ++it)
    {
        if (output++)
        {
            printf("->");
        }
        printf("%d", *it);
    }
    printf(" %d\n", resReturnBikes);
    return 0;
}

