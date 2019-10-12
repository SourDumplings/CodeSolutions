/*
 @Date    : 2017-11-12 13:36:14
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
PAT习题：https://pintia.cn/problem-sets/434/problems/5653
 */

#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    // 有可能m > n
    m %= n;
    int i;
    int A[n];
    for (i = 0; i < m; i++)
    {
        scanf("%d", &A[n-m+i]);
    }
    for (i = 0; i < n - m; i++)
    {
        scanf("%d", &A[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d", A[i]);
        if (i < n - 1)
        {
            putchar(' ');
        }
        else
        {
            putchar('\n');
        }
    }

    return 0;
}

