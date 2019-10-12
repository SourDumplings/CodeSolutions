/*
 @Date    : 2018-08-31 23:22:19
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805392092020736
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1005;
int N, L;
vector<int> fans[MAXN];
bool effectedFans[MAXN];

void dfs(int v, int l)
{
    if (l == L)
    {
        effectedFans[v] = true;
    }
    else if (l < L)
    {
        if (0 < l)
        {
            effectedFans[v] = true;
        }

        for (int f : fans[v])
        {
            dfs(f, l + 1);
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &L);
    for (int i = 0; i != N; ++i)
    {
        int m;
        scanf("%d", &m);
        for (int j = 0; j != m; ++j)
        {
            int v;
            scanf("%d", &v);
            fans[v].push_back(i+1);
        }
    }
    int k;
    scanf("%d", &k);

    for (int i = 0; i != k; ++i)
    {
        int q;
        scanf("%d", &q);
        fill(effectedFans, effectedFans + 1 + N, false);
        dfs(q, 0);
        effectedFans[q] = false;
        printf("%d\n", count(effectedFans, effectedFans+N+1, true));
    }
    return 0;
}


