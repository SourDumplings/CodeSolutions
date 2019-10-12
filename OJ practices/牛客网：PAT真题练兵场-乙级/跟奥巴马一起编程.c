/*
 @Date    : 2017-11-23 18:07:35
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.nowcoder.com/pat/6/problem/4062
 */

#include <stdio.h>

int main()
{
    int N;
    char c;
    scanf("%d %c", &N, &c);
    int i, j;
    int r;
    r = (int) ((double)N/2 + 0.5);
    for (i = 0; i < N; i++)
    {
        putchar(c);
    }
    putchar('\n');
    for (i = 0; i < r - 2; i++)
    {
        putchar(c);
        for (j = 1; j < N - 1; j++)
        {
            putchar(' ');
        }
        putchar(c);
        putchar('\n');
    }
    for (i = 0; i < N; i++)
    {
        putchar(c);
    }
    putchar('\n');

    return 0;
}

