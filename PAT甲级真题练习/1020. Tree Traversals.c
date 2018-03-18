/*
 @Date    : 2017-12-01 12:59:48
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1020
 */

#include <stdio.h>
#include <stdlib.h>

const int maxn = 30;

void Solve(int T[], int r, int p[], int ps, int pe, int in[], int ins, int ine)
{
    int n = pe - ps + 1;
    if (n >= 1)
    {
        T[r] = p[pe];
        if (n == 1)
        {
            return;
        }
        else
        {
            int i;
            for (i = ins; i <= ine; i++)
            {
                if (in[i] == p[pe])
                {
                    break;
                }
            }
            Solve(T, 2*r, p, ps, ps+i-ins-1, in, ins, i-1);
            Solve(T, 2*r+1, p, ps+i-ins, pe-1, in, i+1, ine);
        }
    }
    else
    {
        return;
    }
}

int main()
{
    int p[maxn], in[maxn];
    int N;
    scanf("%d", &N);
    int i;
    int T[10001] = {0};
    for (i = 0; i < N; i++)
    {
        scanf("%d", &p[i]);
    }
    for (i = 0; i < N; i++)
    {
        scanf("%d", &in[i]);
    }
    Solve(T, 1, p, 0, N-1, in, 0, N-1);
    int output = 0;
    for (i = 1; i <= 10000 && output <= N; i++)
    {
        if (T[i])
        {
            if (output++)
            {
                putchar(' ');
            }
            printf("%d", T[i]);
        }
    }
    putchar('\n');
    return 0;
}

