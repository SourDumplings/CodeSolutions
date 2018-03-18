/*
 @Date    : 2018-03-02 09:44:15
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1122
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

static int N, M;
static const int MAXN = 201;
static bool G[MAXN][MAXN];
static bool checked[MAXN];

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    int v, w;
    for (int i = 0; i != N; ++i)
        for (int j = 0; j != N; ++j)
            G[i][j] = false;
    while (M--)
    {
        scanf("%d %d", &v, &w);
        G[v-1][w-1] = G[w-1][v-1] = true;
    }
    int K;
    scanf("%d", &K);
    while (K--)
    {
        int n;
        scanf("%d", &n);
        int path[n];
        for (int i = 0; i != n; ++i)
            scanf("%d", &path[i]);
        bool ok = false;
        if (n == N + 1 && path[N] == path[0])
        {
            ok = true;
            fill(checked, checked+N, false);
            for (int i = 0; i != N; ++i)
            {
                if (!G[path[i]-1][path[i+1]-1] || checked[path[i]-1])
                {
                    ok = false;
                    break;
                }
                checked[path[i]-1] = true;
            }
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
