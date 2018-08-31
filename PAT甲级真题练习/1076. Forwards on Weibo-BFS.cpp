/*
 @Date    : 2018-08-31 22:41:48
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805392092020736
注意不能使用dfs，因为若是dfs的话，假设用户0发微博，要计算L = 3的情况：
      0
     / \
    1   3
   /   / \
  2   2   4
 /
3
在dfs的过程中，为避免重复则必须将计算过的进行标记，否则会在走右边路径时再通过一次2
沿着左路径走到3即为第三层，便将3计算在内，这将导致4不能被计算
如果不标记只按层数算的话就会超时，用Dijkstra也会超时
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 1005;
int N, L;
vector<int> fans[MAXN];
int effectedNum;
bool effected[MAXN];

void bfs(int q)
{
    queue<pair<int, int>> Q;
    Q.push(pair<int, int>(q, 0));
    while (!Q.empty())
    {
        auto pv = Q.front(); Q.pop();
        if (!effected[pv.first])
        {
            effected[pv.first] = true;
            if (pv.second > 0)
                ++effectedNum;

            if (pv.second < L)
            {
                for (int f : fans[pv.first])
                {
                    if (!effected[f])
                        Q.push(pair<int, int>(f, pv.second + 1));
                }
            }
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
        fill(effected, effected + N + 1, false);
        effectedNum = 0;
        bfs(q);
        printf("%d\n", effectedNum);
    }
    return 0;
}
