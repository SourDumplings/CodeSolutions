/*
 @Date    : 2017-12-08 09:18:55
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1046
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000
#define MAXM 10000
#define min(x, y) (x) < (y) ? (x) : (y)

int main()
{
    int N, i;
    int D[MAXN], sdist[MAXN], edist[MAXN];
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &D[i]);
        if (i == 0)
        {
            sdist[i] = 0;
        }
        else
        {
            sdist[i] = sdist[i-1] + D[i-1];
        }
    }
    for (i = N - 1; i >= 0; i--)
    {
        if (i == N - 1)
        {
            edist[i] = 0;
        }
        else
        {
            edist[i] = edist[i+1] + D[i];
        }
    }

    int f, b, s, e;
    int M;
    int result[MAXM];
    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d %d", &s, &e);
        s -= 1;
        e -= 1;
        if (s <= e)
        {
            f = sdist[e] - sdist[s];
            b = edist[e] + D[N-1] + sdist[s];
        }
        else
        {
            f = edist[s] + D[N-1] + sdist[e];
            b = sdist[s] - sdist[e];
        }
        result[i] = min(f, b);
    }

    for (i = 0; i < M; i++)
    {
        printf("%d\n", result[i]);
    }

    return 0;
}

