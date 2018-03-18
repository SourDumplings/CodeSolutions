/*
 @Date    : 2018-02-16 20:12:09
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1087
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <memory>
#include <cstring>

using namespace std;

struct City
{
    int id;
    char name[4];
    int hap;
    vector<int> lastCityId;
};

static const int MAXN = 201;
static int N, K;
static int G[MAXN][MAXN];
static const int INF = 999999;
static map<string, shared_ptr<City>> cityNameTable;
static map<int, shared_ptr<City>> cityIdTable;

static int dist[MAXN];
static bool set[MAXN];

int find_min_dist()
{
    int min_v = -1, min_dist = INF;
    for (int i = 0; i != N; ++i)
    {
        if (!set[i] && dist[i] < min_dist)
        {
            min_dist = dist[i];
            min_v = i;
        }
    }
    return min_v;
}

void Dijkstra(int s)
{
    for (int i = 0; i != N; ++i)
        dist[i] = INF;
    fill(set, set+N, false);
    dist[s] = 0;
    while (true)
    {
        int v = find_min_dist();
        if (v == -1)
            break;
        set[v] = true;
        for (int w = 0; w != N; ++w)
        {
            if (!set[w] && G[v][w] != INF && dist[v] + G[v][w] < dist[w])
                dist[w] = dist[v] + G[v][w];
        }
    }
    return;
}

static int pathNo = 0;
static int thisHap = 0;
static int maxHap = 0;
static vector<int> path, finalPath;
static int avgHap = 0;

void get_path(int d)
{
    thisHap += cityIdTable[d]->hap;
    path.push_back(d);
    if (d == 0)
    {
        ++pathNo;
        if (thisHap > maxHap ||
            ((thisHap == maxHap) && (thisHap / (path.size() - 1) > avgHap)))
        {
            maxHap = thisHap;
            avgHap = maxHap / (path.size() - 1);
            finalPath = path;
        }
    }
    else
    {
        for (int s = 0; s != N; ++s)
        {
            if (s != d && G[s][d] + dist[s] == dist[d])
            {
                cityIdTable[d]->lastCityId.push_back(s);
                get_path(s);
            }
        }
    }
    thisHap -= cityIdTable[d]->hap;
    path.pop_back();
    return;
}

int main(int argc, char const *argv[])
{
    char startName[4];
    scanf("%d %d %s", &N, &K, startName);
    for (int i = 0; i != N; ++i)
    {
        for (int j = 0; j != N; ++j)
            G[i][j] = INF;
    }
    int id = 0;
    shared_ptr<City> startCity(new City);
    startCity->id = id;
    strcpy(startCity->name, startName);
    cityNameTable.insert(make_pair(startName, startCity));
    cityIdTable.insert(make_pair(id++, startCity));
    for (int i = 1; i != N; ++i)
    {
        shared_ptr<City> pc(new City);
        scanf("%s %d", pc->name, &pc->hap);
        pc->id = id;
        cityNameTable.insert(make_pair(pc->name, pc));
        cityIdTable.insert(make_pair(id++, pc));
    }
    for (int i = 0; i != K; ++i)
    {
        string name1, name2;
        int cost;
        cin >> name1 >> name2 >> cost;
        G[cityNameTable[name1]->id][cityNameTable[name2]->id] = cost;
        G[cityNameTable[name2]->id][cityNameTable[name1]->id] = cost;
    }
    Dijkstra(0);
    int d = cityNameTable["ROM"]->id;
    get_path(d);
    printf("%d %d %d %d\n", pathNo, dist[d], maxHap, avgHap);
    int output = 0;
    for (auto it = finalPath.rbegin(); it != finalPath.rend(); ++it)
    {
        if (output++)
            printf("->");
        cout << cityIdTable[*it]->name;
    }
    putchar('\n');
    return 0;
}
