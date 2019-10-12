/*
 @Date    : 2018-09-07 11:39:14
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/719
每个交接点对应着一个图节点
每个交接点记录最早开始时间和最晚完成时间
两次拓扑排序得到两个值
两个值相等的交接点即为关键路径上的点
这道题的输入顺序就是按照编号从小到大输入的
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 105, INF = 999999;
int N, M;
int G[MAXN][MAXN];
int inDegree[MAXN], outDegree[MAXN];

struct Point
{
    int earliestStart = 0, latestFinish = INF;
};

Point data[MAXN];
int finishTime;

bool top_sort()
{
    vector<int> tempIndegree(inDegree, inDegree+N);
    queue<int> q;
    int finishedNum = 0;
    for (int i = 0; i != N; ++i)
    {
        if (tempIndegree[i] == 0)
        {
            q.push(i);
            data[i].earliestStart = 0;
        }
    }
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        ++finishedNum;
        for (int w = 0; w != N; ++w)
        {
            if (G[v][w] != INF)
            {
                if (data[w].earliestStart < G[v][w] + data[v].earliestStart)
                    data[w].earliestStart = G[v][w] + data[v].earliestStart;
                if (--tempIndegree[w] == 0)
                    q.push(w);
            }
        }
    }
    bool ret = false;
    if (finishedNum == N)
        ret = true;
    return ret;
}

void re_top_sort()
{
    vector<int> tempOutDegree(outDegree, outDegree+N);
    queue<int> q;
    for (int i = 0; i != N; ++i)
    {
        if (tempOutDegree[i] == 0)
        {
            q.push(i);
            data[i].latestFinish = finishTime;
        }
    }
    while (!q.empty())
    {
        int w = q.front(); q.pop();
        for (int v = 0; v != N; ++v)
        {
            if (G[v][w] != INF)
            {
                if (data[w].latestFinish - G[v][w] < data[v].latestFinish)
                    data[v].latestFinish = data[w].latestFinish - G[v][w];
                if (--tempOutDegree[v] == 0)
                    q.push(v);
            }
        }
    }
    return;
}

void print_key_activity()
{
    for (int v = 0; v != N; ++v)
    {
        if (data[v].earliestStart == data[v].latestFinish)
        {
            for (int w = N - 1; w != -1; --w)
            {
                if (G[v][w] != INF && data[w].earliestStart == data[w].latestFinish &&
                    data[v].latestFinish + G[v][w] == data[w].latestFinish)
                    printf("%d->%d\n", v+1, w+1);
            }
        }
    }
    return;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i != N; ++i)
    {
        inDegree[i] = outDegree[i] = 0;
        for (int j = 0; j != N; ++j)
            G[i][j] = INF;
    }
    for (int i = 0; i != M; ++i)
    {
        int v, w, t;
        scanf("%d %d %d", &v, &w, &t);
        G[v-1][w-1] = t;
        ++inDegree[w-1];
        ++outDegree[v-1];
    }
    if (top_sort())
    {
        finishTime = max_element(data, data+N, [] (const Point &p1, const Point &p2)
                                 {
                                     return p1.earliestStart < p2.earliestStart;
                                 })->earliestStart;
        printf("%d\n", finishTime);
        re_top_sort();
        print_key_activity();
    }
    else
        printf("0\n");
    return 0;
}
