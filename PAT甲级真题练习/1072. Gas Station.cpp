/*
 @Date    : 2018-02-08 15:09:12
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1072
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 99999;

int process(const string &s, int N)
{
    if (s[0] == 'G')
        return stoi(s.substr(1)) + N;
    else
        return stoi(s);
}

int find_min_dist(bool checked[], int dist[], int n)
{
    int minDist = INF, minV;
    bool found = false;
    for (int i = 0; i != n; ++i)
    {
        if (!checked[i] && dist[i] < minDist)
        {
            minDist = dist[i];
            minV = i;
            found = true;
        }
    }
    if (found)
        return minV;
    else
        return -1;
}

void Dijkstra(int *tempG, int s, int dist[], int n)
{
    bool checked[n];
    fill(checked, checked + n, false);
    dist[s] = 0;
    checked[s] = true;
    for (int i = 0; i != n; ++i)
    {
        if (i != s && tempG[n * s + i] != INF)
            dist[i] = tempG[n * s + i];
    }
    while (true)
    {
        int v = find_min_dist(checked, dist, n);
        if (v == -1) break;
        checked[v] = true;
        for (int w = 0; w != n; ++w)
        {
            if (!checked[w] && dist[v] + tempG[v * n + w] < dist[w])
                dist[w] = dist[v] + tempG[v * n + w];
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    int N, M, K, Ds;
    scanf("%d %d %d %d", &N, &M, &K, &Ds);
    int G[N + M][N + M];
    for (int i = 0; i != N + M; ++i)
    {
        for (int j = 0; j != N + M; ++j)
        {
            G[i][j] = INF;
        }
    }
    string s, d;
    int dis;
    for (int i = 0; i != K; ++i)
    {
        cin >> s >> d >> dis;
        G[process(s, N) - 1][process(d, N) - 1] = dis;
        G[process(d, N) - 1][process(s, N) - 1] = dis;
    }
    int *tempG = new int[(N + M) * (N + M)];

    double maxMinDist = 0;
    int resultG = -1;
    double smallestMeanDist;
    for (int i = N; i != N + M; ++i)
    {
        int minDist = INF;
        double sumDist = 0;
        bool feasible = true;
        memcpy(tempG, G, sizeof(G));
        int dist[N + M];
        fill(dist, dist + N + M, INF);
        Dijkstra(tempG, i, dist, N + M);
        for (int j = 0; j != N; ++j)
        {
            if (j == i) continue;
            int distance = dist[j];
            if (distance > Ds)
            {
                feasible = false;
                break;
            }
            else
            {
                if (distance < minDist)
                    minDist = distance;
                sumDist += distance;
            }
        }
        if (feasible)
        {
            if (minDist > maxMinDist)
            {
                maxMinDist = minDist;
                resultG = i;
                smallestMeanDist = sumDist / N;
            }
            else if (minDist == maxMinDist && sumDist / N < smallestMeanDist)
            {
                maxMinDist = minDist;
                resultG = i;
                smallestMeanDist = sumDist / N;
            }
        }
    }
    if (resultG == -1)
        printf("No Solution\n");
    else
    {
        printf("G%d\n", resultG - N + 1);
        printf("%.1f %.1f\n", maxMinDist, smallestMeanDist);
    }
    return 0;
}
