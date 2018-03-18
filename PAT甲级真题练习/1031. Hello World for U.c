/*
 @Date    : 2017-12-03 13:05:59
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1031
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n1, n2;
    char s[81];
    gets(s);
    int N = strlen(s);
    for (n2 = 3; n2 <= N; n2++)
    {
        n1 = (N + 2 - n2) / 2;
        // printf("$$n1 = %d, n2 = %d$$\n", n1, n2);
        if (n1 <= n2 && 2 * n1 + n2 == N + 2)
        {
            break;
        }
    }
    int i, j, k = 0;
    for (i = 0; i < n1 - 1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            if (j == 0)
            {
                printf("%c", s[k]);
            }
            else if (j == n2 - 1)
            {
                printf("%c\n", s[N - 1 - k]);
                k++;
            }
            else
            {
                putchar(' ');
            }
        }
    }
    for (i = 0; i < n2; i++)
    {
        printf("%c", s[k++]);
    }
    putchar('\n');
    return 0;
}

