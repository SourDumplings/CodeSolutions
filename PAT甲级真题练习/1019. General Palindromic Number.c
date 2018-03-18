/*
 @Date    : 2017-12-01 11:12:53
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1019
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, b;
    scanf("%d %d", &N, &b);
    int num[200];
    int i;
    if (N == 0)
    {
        printf("Yes\n");
        printf("0\n");
        return 0;
    }
    for (i = 0; N; i++)
    {
        num[i] = N % b;
        N = (N - num[i]) / b;
        // printf("N = %d\n", N);
    }
    // printf("%d\n", i);
    int j;
    int flag = 1;
    for (j = 0; j < i / 2; j++)
    {
        if (num[j] != num[i-j-1])
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    int output = 0;
    for (j = i - 1; j >= 0; j--)
    {
        if (output++)
        {
            putchar(' ');
        }
        printf("%d", num[j]);
    }
    putchar('\n');
    return 0;
}

