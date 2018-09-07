/*
 @Date    : 2018-03-15 10:50:02
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/861
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

static const int MAXN = 101;
static bool G[MAXN][MAXN];
static int N;
static int indegree[MAXN];

bool top_sort()
{
    queue<int> Q;
    int finished = 0;
    for (unsigned i = 0; i < N; ++i)
    {
        if (indegree[i] == 0)
        {
            Q.push(i);
        }
    }
    while (!Q.empty())
    {
        int v = Q.front(); Q.pop();
        ++finished;
        for (unsigned w = 0; w < N; ++w)
        {
            if (G[v][w])
            {
                if (--indegree[w] == 0)
                {
                    Q.push(w);
                }
            }
        }
    }
    if (finished == N)
    {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
    {
        indegree[i] = 0;
        for (int j = 0; j != N; ++j)
            G[i][j] = false;
    }
    for (int i = 0; i != N; ++i)
    {
        int K;
        scanf("%d", &K);
        indegree[i] = K;
        for (int j = 0; j != K; ++j)
        {
            int v;
            scanf("%d", &v);
            G[v-1][i] = true;
        }
    }
    if (top_sort())
        printf("1\n");
    else
        printf("0\n");
    return 0;
}

