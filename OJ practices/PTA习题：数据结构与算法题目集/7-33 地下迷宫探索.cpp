/*
 @Date    : 2018-03-15 09:58:10
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/860
此题就是简单的DFS，没有说一条通道只走一次
对于任何结点都是进去时输出一次，出来时输出一次
故在DFS过程中输出
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

static const int MAXN = 1001;
static bool G[MAXN][MAXN];
static int N, M, S;
static bool checked[MAXN];
static bool finishDFS = false;
static int output = 0;

void DFS(int s)
{
    checked[s] = true;
    if (output++)
    {
        putchar(' ');
    }
    cout << s + 1;
    // printf("%d is visited\n", s + 1);
    for (int w = 0; w != N; ++w)
    {
        if (!checked[w] && G[s][w])
        {
            DFS(w);
            if (output++)
            {
                putchar(' ');
            }
            cout << s + 1;
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &N, &M, &S);
    for (int i = 0; i != N; ++i)
        for (int j = 0; j != N; ++j)
            G[i][j] = false;
    for (unsigned i = 0; i < M; ++i)
    {
        int v, w;
        scanf("%d %d", &v, &w);
        G[v-1][w-1] = G[w-1][v-1] = true;
    }
    fill(checked, checked+N, false);
    DFS(S-1);
    int visitedNum = count(checked, checked+N, true);
    if (visitedNum != N)
        printf(" 0");
    putchar('\n');
    return 0;
}

