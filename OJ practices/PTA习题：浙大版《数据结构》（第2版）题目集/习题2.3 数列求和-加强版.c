/*
 @Date    : 2017-11-12 14:01:56
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/5654
 */

#include <stdio.h>

#define MAX 100002

int main()
{
    int A, N;
    scanf("%d %d", &A, &N);
    int result[MAX] = {0}; // 倒序存放结果
    int i;
    int effnum = 0; // 记录是否遇到了有效数字
    for (i = 0; i < N; i++)
    {
        result[i] = A * (N - i);
    }
    // 进位
    for (i = 0; i < MAX; i++)
    {
        if (result[i] > 9)
        {
            result[i+1] += result[i] / 10;
            result[i] %= 10;
        }
    }
    // 输出
    for (i = MAX - 1; i >= 0; i--)
    {
        if (result[i] && !effnum)
        {
            effnum = 1;
        }
        if (effnum)
        {
            printf("%d", result[i]);
        }
    }
    if (!effnum)
    {
        printf("0");
    }
    putchar('\n');
    return 0;
}

