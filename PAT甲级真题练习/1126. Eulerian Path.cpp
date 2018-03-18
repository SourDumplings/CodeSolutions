/*
 @Date    : 2018-03-03 20:35:11
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1126
注意要先判断是否连通，不连通的图就是非欧拉图
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

static const int MAXN = 502;
static int degree[MAXN];
static bool G[MAXN][MAXN];
static bool visited[MAXN];

void BFS(int start, int N)
{
    queue<int> Q;
    Q.push(start);
    while (!Q.empty())
    {
        int v = Q.front(); Q.pop();
        visited[v] = true;
        for (int w = 0; w != N; ++w)
        {
            if (!visited[w] && G[v][w]) Q.push(w);
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i != N; ++i)
    {
        degree[i] = 0;
        visited[i] = false;
        for (int j = 0; j != N; ++j)
            G[i][j] = false;
    }
    int v, w;
    while (M--)
    {
        scanf("%d %d", &v, &w);
        G[v - 1][w - 1] = G[w - 1][v - 1] = true;
        ++degree[v - 1];
        ++degree[w - 1];
    }
    int connectedGraphNum = 0;
    for (int i = 0; i != N; ++i)
    {
        if (!visited[i])
        {
            ++connectedGraphNum;
            BFS(i, N);
        }
    }
    int output = 0;
    for (int i = 0; i != N; ++i)
    {
        if (output++) putchar(' ');
        printf("%d", degree[i]);
    }
    putchar('\n');

    if (connectedGraphNum > 1) printf("Non-Eulerian\n");
    else
    {
        int oddDegreeVerticesNum = count_if(degree, degree + N,
        [] (int d) { return (d & 1); });
        if (oddDegreeVerticesNum == 0)
            printf("Eulerian\n");
        else if (oddDegreeVerticesNum == 2)
            printf("Semi-Eulerian\n");
        else
            printf("Non-Eulerian\n");
    }
    return 0;
}
