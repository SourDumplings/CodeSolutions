/*
 @Date    : 2017-12-05 21:16:51
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1037
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100001

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int NC, NP;
    int C[MAXN], P[MAXN];
    int i, j;
    scanf("%d", &NC);
    for (i = 0; i < NC; i++)
    {
        scanf("%d", &C[i]);
    }
    scanf("%d", &NP);
    for (i = 0; i < NP; i++)
    {
        scanf("%d", &P[i]);
    }

    qsort(C, NC, sizeof(C[0]), compare);
    qsort(P, NP, sizeof(P[0]), compare);

    int lastnegC, lastnegP;
    for (i = 0; i < NP && P[i] < 0; i++);
    lastnegP = i - 1;
    for (i = 0; i < NP && C[i] < 0; i++);
    lastnegC = i - 1;

    long long result = 0;
    for (i = 0; i <= lastnegC && i <= lastnegP; i++)
    {
        result += C[i] * P[i];
    }

    for (i = NC - 1, j = NP - 1; i > lastnegC && j > lastnegP; i--, j--)
    {
        if (C[i] > 0 && P[j] > 0)
        {
            result += C[i] * P[j];
        }
    }

    printf("%lld\n", result);

    return 0;
}

