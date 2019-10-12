/*
 @Date    : 2018-08-30 23:40:12
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805396953219072
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int N, M, K, Ds;
const int MAXN = 1150, INF = 99999;
int G[MAXN][MAXN], dist[MAXN];
bool visited[MAXN];

int my_stoi(char s[], int b, int e)
{
    int res = 0, l = e - b;
    for (int i = e - 1; i != b - 1; --i)
        res += (s[i] - '0') * (int)pow(10, e - i - 1);
    return res;
}

int process(char s[])
{
    int l = strlen(s), no;
    if (s[0] == 'G')
    {
        no = my_stoi(s, 1, l) + N;
    }
    else
        no = my_stoi(s, 0, l);
    return no;
}

int find_min_dist()
{
    int minD = INF, minV = -1;
    for (int i = 1; i != N + M + 1; ++i)
    {
        if (!visited[i] && dist[i] < minD)
        {
            minD = dist[i];
            minV = i;
        }
    }
    return minV;
}

void Dijkstra(int s)
{

    for (int i = 1; i != N + M + 1; ++i)
    {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[s] = 0;
    while (true)
    {
        int v = find_min_dist();
        if (v == -1)
            break;
        visited[v] = true;
        for (int w = 1; w != N + M + 1; ++w)
        {
            if (!visited[w] && G[v][w] != INF && dist[v] + G[v][w] < dist[w])
                dist[w] = dist[v] + G[v][w];
        }
    }
    return;

}

int main()
{
    scanf("%d %d %d %d", &N, &M, &K, &Ds);
    for (int i = 1; i != N + M + 1; ++i)
    {
        for (int j = 1; j != N + M + 1; ++j)
        {
            G[i][j] = INF;
        }
    }
    for (int i = 0; i != K; ++i)
    {
        char vs[10], ws[10];
        int d;
        scanf("%s %s %d", vs, ws, &d);
        int v = process(vs), w = process(ws);
        if (d <= Ds)
            G[v][w] = G[w][v] = d;
    }

    int resS = -1, maxMinD = 0, resTotalD;
    for (int stat = N + 1; stat != N + M + 1; ++stat)
    {
        Dijkstra(stat);
        int minD = INF, totalD = 0;
        for (int i = 1; i != N + 1; ++i)
        {
            if (dist[i] > Ds)
            {
                minD = INF;
                break;
            }
            else
                totalD += dist[i];

            if (dist[i] < minD)
                minD = dist[i];
        }
        if (minD < INF &&
            (minD > maxMinD || (minD == maxMinD && totalD < resTotalD)))
        {
            maxMinD = minD;
            resS = stat;
            resTotalD = totalD;
        }
    }

    if (resS == -1)
        printf("No Solution\n");
    else
    {
        printf("G%d\n", resS - N);
        printf("%.1f %.1f\n", (double)maxMinD, (double)resTotalD / N);
    }
    return 0;
}
