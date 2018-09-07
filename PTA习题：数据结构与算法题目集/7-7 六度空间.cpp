/*
 @Date    : 2018-03-11 11:31:30
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/715
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

static const int MAXN = 10001;
static vector<vector<int>> G(MAXN);
static int N, M;

int BFS(int s, bool checked[])
{
    int dist[MAXN];
    int res = 0;
    queue<int> Q;
    Q.push(s);
    checked[s] = true;
    dist[s] = 0;
    while (!Q.empty())
    {
        int v = Q.front(); Q.pop();
        if (dist[v] > 6) break;
        ++res;
        for (int w : G[v])
        {
            if (!checked[w])
            {
                Q.push(w);
                checked[w] = true;
                dist[w] = dist[v] + 1;
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i != M; ++i)
    {
        int v, w;
        scanf("%d %d", &v, &w);
        G[v - 1].push_back(w - 1);
        G[w - 1].push_back(v - 1);
    }
    for (int i = 0; i != N; ++i)
    {
        bool checked[N];
        fill(checked, checked+N, false);
        int num = BFS(i, checked);
        printf("%d: %.2f%%\n", i + 1,
            static_cast<double>(num) * 100 / static_cast<double>(N));
    }
    return 0;
}

