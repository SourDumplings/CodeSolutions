/*
 @Date    : 2017-12-08 09:18:55
 @Author  : Ëá½È×Ó (changzheng300@foxmail.com)
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
    int N, i, j;
    int D[MAXN];
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &D[i]);
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
        f = b = 0;
        for (j = s;; j = (j + 1) % N)
        {
            f += D[j];
            if (j == e)
            {
                f -= D[j];
                break;
            }
        }
        for (j = e;; j = (j + 1) % N)
        {
            b += D[j];
            if (j == s)
            {
                b -= D[j];
                break;
            }
            if (b > f)
            {
                break;
            }
        }
        result[i] = min(f, b);
    }

    for (i = 0; i < M; i++)
    {
        printf("%d\n", result[i]);
    }

    return 0;
}

