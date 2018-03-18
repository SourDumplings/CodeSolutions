/*
 @Date    : 2017-12-03 10:44:38
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1029
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N1;
    scanf("%d", &N1);
    int L1[N1];
    int i;
    for (i = 0; i < N1; i++)
    {
        scanf("%d", &L1[i]);
    }
    int N2;
    scanf("%d", &N2);
    int L2[N2];
    for (i = 0; i < N2; i++)
    {
        scanf("%d", &L2[i]);
    }
    int median;
    int m = (N1 + N2) % 2 ? (N1 + N2) / 2 : (N1 + N2) / 2 - 1;
    int i1 = 0, i2 = 0;
    i = 0;
    while (i < m && i1 < N1 && i2 < N2)
    {
        if (L1[i1] < L2[i2])
        {
            i1++;
        }
        else if (L1[i1] > L2[i2])
        {
            i2++;
        }
        else
        {
            i1++;
            i2++;
        }
        i++;
    }
    while (i < m && i1 < N1)
    {
        i1++;
        i++;
    }
    while (i < m && i2 < N2)
    {
        i2++;
        i++;
    }
    if (i1 < N1 && i2 < N2)
    {
        if (L1[i1] <= L2[i2])
        {
            median = L1[i1];
        }
        else
        {
            median = L2[i2];
        }
    }
    else if (i1 < N1)
    {
        median = L1[i1];
    }
    else if (i2 < N2)
    {
        median = L2[i2];
    }
    printf("%d\n", median);
    return 0;
}
