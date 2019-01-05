/*
 @Date    : 2018-08-03 22:11:04
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805343979159552
 */

#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

const int MAXN = 203;

bool G[MAXN][MAXN];

int main(int argc, char const *argv[])
{
    for (int i = 0; i < MAXN; ++i)
    {
        for (int j = 0; j < MAXN; ++j)
        {
            G[i][j] = false;
        }
    }
    int Nv, Ne;
    scanf("%d %d", &Nv, &Ne);
    for (int i = 0; i < Ne; ++i)
    {
        int v, w;
        scanf("%d %d", &v, &w);
        G[v][w] = G[w][v] = true;
    }

    int W;
    scanf("%d", &W);
    for (int i = 0; i < W; ++i)
    {
        int K;
        scanf("%d", &K);

        set<int> c;
        bool isC = true;
        for (int j = 0; j < K; ++j)
        {
            int m;
            scanf("%d", &m);
            if (j && isC)
            {
                for (auto &cMember : c)
                {
                    if (!G[cMember][m])
                    {
                        isC = false;
                        break;
                    }
                }
            }
            c.insert(m);
        }

        if (isC)
        {
            bool isM = true;
            for (int j = 1; j <= Nv; ++j)
            {
                if (c.find(j) == c.end())
                {
                    bool flag = false;
                    for (auto &cMember : c)
                    {
                        if (!G[cMember][j])
                        {
                            flag = true;
                            break;
                        }
                    }
                    if (!flag)
                    {
                        isM = false;
                        break;
                    }
                }
            }

            if (isM)
            {
                printf("Yes\n");
            }
            else
                printf("Not Maximal\n");
        }
        else
            printf("Not a Clique\n");
    }
    return 0;
}

