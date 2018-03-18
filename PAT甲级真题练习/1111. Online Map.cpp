/*
 @Date    : 2018-02-27 13:37:57
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1111
注意在计算距离最短路径中时间最短路径时，时间需要重新设变量存储
因为时间最短的路径并非与距离最短路径重合
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

static const int MAXN = 501;
static int Gd[MAXN][MAXN];
static int Gt[MAXN][MAXN];
static int N, M;
static int dist[MAXN];
static int time_data[MAXN];
static const int INF = 999999;
static bool checked[MAXN];
static vector<int> thisPath, resDPath, resTPath;
static int minRecord, thisRecord;

int get_min(int record[])
{
    int minR = INF, minRV = -1;
    for (int i = 0; i != N; ++i)
    {
        if (!checked[i] && record[i] < minR)
        {
            minR = record[i];
            minRV = i;
        }
    }
    return minRV;
}

void Dijkstra(int so, int de, int G[][MAXN], int record[])
{
    fill(checked, checked+N, false);
    record[so] = 0;
    while (true)
    {
        int v = get_min(record);
        checked[v] = true;
        if (v == -1)
            break;
        for (int w = 0; w != N; ++w)
        {
            if (!checked[w] && record[v] + G[v][w] < record[w] )
                record[w] = record[v] + G[v][w];
        }
    }
    return;
}

void DFS(int so, int de, int G[][MAXN], int record[MAXN], vector<int> &resPath, char c)
{
    thisPath.push_back(de);
    if (de == so)
    {
        if (thisRecord < minRecord)
        {
            minRecord = thisRecord;
            resPath = thisPath;
        }
    }
    else
    {
        for (int s = 0; s != N; ++s)
        {
            if (record[s] + G[s][de] == record[de])
            {
                if (c == 'd') thisRecord += Gt[s][de];
                else ++thisRecord;
                if (thisRecord <= minRecord)
                    DFS(so, s, G, record, resPath, c);
                if (c == 'd') thisRecord -= Gt[s][de];
                else --thisRecord;
            }
        }
    }
    thisPath.pop_back();
    return;
}

void get_path(int so, int de, int G[][MAXN], vector<int> &resPath,
    char c)
{
    minRecord = INF;
    thisRecord = 0;
    int *record = nullptr;
    if (c == 'd') record = dist;
    else record = time_data;
    DFS(so, de, G, record, resPath, c);
    return;
}

void output_path(const vector<int> &resPath)
{
    int output = 0;
    for (auto it = resPath.rbegin(); it != resPath.rend(); ++it)
    {
        if (output++) printf(" -> ");
        printf("%d", *it);
    }
    putchar('\n');
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    int oneWay, d, t;
    int v1, v2;
    for (int i = 0; i != N; ++i)
    {
        for (int j = 0; j != N; ++j)
            Gd[i][j] = Gt[i][j] = INF;
        dist[i] = time_data[i] = INF;
    }
    for (int i = 0; i != M; ++i)
    {
        scanf("%d %d %d %d %d", &v1, &v2, &oneWay, &d, &t);
        Gd[v1][v2] = d;
        Gt[v1][v2] = t;
        if (oneWay == 0)
        {
            Gd[v2][v1] = d;
            Gt[v2][v1] = t;
        }
    }
    int so, de;
    scanf("%d %d", &so, &de);
    Dijkstra(so, de, Gd, dist);
    Dijkstra(so, de, Gt, time_data);
    get_path(so, de, Gd, resDPath, 'd');
    get_path(so, de, Gt, resTPath, 't');
    if (resDPath == resTPath)
    {
        printf("Distance = %d; Time = %d: ", dist[de], time_data[de]);
        output_path(resDPath);
    }
    else
    {
        printf("Distance = %d: ", dist[de]);
        output_path(resDPath);
        printf("Time = %d: ", time_data[de]);
        output_path(resTPath);
    }
    return 0;
}
