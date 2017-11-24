/*
 @Date    : 2017-11-23 20:37:12
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.nowcoder.com/pat/6/problem/4064
 */

#include <stdio.h>

int main()
{
    int data[101] = {0};
    int N;
    int i;
    scanf("%d", &N);
    int grade;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &grade);
        data[grade]++;
    }
    scanf("%d", &N);
    int result[N];
    int r = 0;
    for (r = 0; r < N; r++)
    {
        scanf("%d", &grade);
        result[r] = data[grade];
    }
    int output = 0;
    for (i = 0; i < N; i++)
    {
        if (output++)
        {
            putchar(' ');
        }
        printf("%d", result[i]);
    }
    putchar('\n');
    return 0;
}

