/*
 @Date    : 2017-11-13 15:18:56
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/5860
 */

#include <stdio.h>

void Read(int L[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &L[i]);
    }
    return;
}

void MaxUpL(int L[], int n)
{
    int first, last;
    int thislength, maxlength;
    int maxfirst, maxlast;
    thislength = maxlength = 1;
    maxfirst = maxlast = 0;
    for (first = 0; first < n; first = last)
    {
        for (last = first + 1; last < n && L[last] > L[last-1]; last++)
        {
            thislength++;
            if (thislength > maxlength)
            {
                maxlength = thislength;
                maxfirst = first;
                maxlast = last;
            }
        }
        thislength = 1;
    }
    while (maxfirst != maxlast)
    {
        printf("%d ", L[maxfirst]);
        maxfirst++;
    }
    printf("%d\n", L[maxfirst]);
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    int L[n];
    Read(L, n);
    MaxUpL(L, n);
    return 0;
}

