/*
 @Date    : 2018-03-11 11:13:55
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/714
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

static const int MAXN = 11;
static bool G[MAXN][MAXN];
static int N, E;
static bool checked[MAXN];

void print_result(const vector<int> &v)
{
    putchar('{');
    for (int i : v)
        printf(" %d", i);
    printf(" }\n");
    return;
}

void DFS(int s, vector<int> &v)
{
    v.push_back(s);
    checked[s] = true;
    for (int i = 0; i != N; ++i)
    {
        if (!checked[i] && G[s][i])
            DFS(i, v);
    }
    return;
}

void BFS(int s, vector<int> &v)
{
    queue<int> Q;
    Q.push(s);
    checked[s] = true;
    while (!Q.empty())
    {
        int u = Q.front(); Q.pop();
        v.push_back(u);
        for (int i = 0; i != N; ++i)
        {
            if (!checked[i] && G[u][i])
            {
                Q.push(i);
                checked[i] = true;
            }
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &E);
    for (int i = 0; i != N; ++i)
        for (int j = 0; j != N; ++j)
            G[i][j] = false;
    for (int i = 0; i != E; ++i)
    {
        int v, w;
        scanf("%d %d", &v, &w);
        G[v][w] = G[w][v] = true;
    }
    memset(checked, false, sizeof(checked));
    for (int i = 0; i != N; ++i)
    {
        if (!checked[i])
        {
            vector<int> v;
            DFS(i, v);
            print_result(v);
        }
    }
    memset(checked, false, sizeof(checked));
    for (int i = 0; i != N; ++i)
    {
        if (!checked[i])
        {
            vector<int> v;
            BFS(i, v);
            print_result(v);
        }
    }
    return 0;
}

