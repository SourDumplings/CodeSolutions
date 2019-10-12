/*
 @Date    : 2018-03-06 08:51:32
 @Author  : Ëá½È×Ó (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1131
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

static const int INF = 999999;

struct Line
{
    Line(): dist(INF) {}
    Line(int lineNo_, int sId_, int dId_, int dist_):
        lineNo(lineNo_), sId(sId_), dId(dId_), dist(dist_) {}
    int lineNo;
    int sId, dId;
    int dist;
};

struct Station
{
    int id;
    vector<Line> nextLines; // 记录以该站为起点的边
    vector<Line> lastLines; // 记录以该站为终点的边
};

static const int MAXM = 10001;
static Station G[MAXM];

void read_line_data(int lineNo)
{
    int M;
    scanf("%d", &M);
    int lastS, S;
    for (int i = 0; i != M; ++i)
    {
        scanf("%d", &S);
        if (i != 0)
        {
            G[S].nextLines.push_back(Line(lineNo, S, lastS, 1));
            G[lastS].nextLines.push_back(Line(lineNo, lastS, S, 1));
            G[S].lastLines.push_back(Line(lineNo, lastS, S, 1));
            G[lastS].lastLines.push_back(Line(lineNo, S, lastS, 1));
        }
        lastS = S;
    }
    return;
}

static bool checked[MAXM];
static int dist[MAXM];

int find_min_dist()
{
    int min_v = -1, min_d = INF;
    for (int i = 0; i != MAXM; ++i)
    {
        if (!checked[i] && dist[i] < min_d)
        {
            min_d = dist[i];
            min_v = i;
        }
    }
    return min_v;
}

void Dijkstra(int s)
{
    fill(checked, checked + MAXM, false);
    fill(dist, dist + MAXM, INF);
    dist[s] = 0;
    while (true)
    {
        int v = find_min_dist();
        checked[v] = true;
        if (v == -1)
            break;
        for (auto &line : G[v].nextLines)
        {
            int w = line.dId;
            if (dist[v] + line.dist < dist[w])
                dist[w] = dist[v] + line.dist;
        }
    }
    return;
}

static vector<Line> thisPath, resPath;
static set<int> linesThisPath;
static int minTransfer = INF;

void get_path(int s, int d)
{
    if (d == s)
    {
        if (linesThisPath.size() < minTransfer)
        {
            minTransfer = linesThisPath.size();
            resPath = thisPath;
        }
    }
    else if (linesThisPath.size() < minTransfer)
    {
        for (Line &lineId : G[d].lastLines)
        {
            if (lineId.dist + dist[lineId.sId] == dist[d])
            {
                bool transfer = false;
                if (linesThisPath.find(lineId.lineNo) == linesThisPath.end())
                {
                    transfer = true;
                    linesThisPath.insert(lineId.lineNo);
                }
                thisPath.push_back(lineId);
                get_path(s, lineId.sId);
                thisPath.pop_back();
                if (transfer) linesThisPath.erase(lineId.lineNo);
            }
        }
    }
    return;
}

void output_path()
{
    reverse(resPath.begin(), resPath.end());
    int sumStop = resPath.size();
    printf("%d\n", sumStop);
    Line lastLine = resPath.front();
    for (int i = 0; i != sumStop; ++i)
    {
        if (resPath[i].lineNo != lastLine.lineNo)
        {
            printf("Take Line#%d from %04d to %04d.\n",
                lastLine.lineNo, lastLine.sId, resPath[i].sId);
            lastLine = resPath[i];
        }
        if (i == sumStop - 1)
        {
            printf("Take Line#%d from %04d to %04d.\n",
                lastLine.lineNo, lastLine.sId, resPath[i].dId);
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
        read_line_data(i + 1);
    int K, s, d;
    scanf("%d", &K);
    for (int i = 0; i != K; ++i)
    {
        scanf("%d %d", &s, &d);
        Dijkstra(s);
        minTransfer = INF;
        get_path(s, d);
        output_path();
    }
    return 0;
}


