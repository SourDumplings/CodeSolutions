/*
 @Date    : 2018-08-08 20:54:44
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805343043829760
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1005;
int N, M;
bool G[MAXN][MAXN];
vector<int> indegree(MAXN);

int main(int argc, char const *argv[])
{
    for (int i = 0; i < MAXN; ++i)
    {
        for (int j = 0; j < MAXN; ++j)
        {
            G[i][j] = false;
        }
        indegree[i] = 0;
    }

    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i)
    {
        int v, w;
        scanf("%d %d", &v, &w);
        G[v][w] = true;
        ++indegree[w];
    }

    int K;
    vector<int> ret;
    scanf("%d", &K);
    for (int i = 0; i < K; ++i)
    {
        bool top = true;
        vector<int> tempIndegree(indegree);
        for (int j = 0; j < N; ++j)
        {
            int v;
            scanf("%d", &v);
            if (top)
            {
                if (tempIndegree[v] == 0)
                {
                    for (int k = 1; k <= N; ++k)
                    {
                        if (G[v][k])
                        {
                            --tempIndegree[k];
                        }
                    }
                }
                else
                    top = false;
            }
        }
        if (!top)
        {
            ret.push_back(i);
        }
    }

    int output = 0;
    for (auto &i : ret)
    {
        if (output++)
        {
            putchar(' ');
        }
        printf("%d", i);
    }
    putchar('\n');
    return 0;
}

