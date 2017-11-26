/*
 @Date    : 2017-11-12 14:13:37
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/5811
 */

#include <stdio.h>

int result[10] = {0}, visited[10] = {0}, n;

void DFS(int d)
{
    int i;
    if (d == n + 1)
    {
        // 已经到了第n+1位，即n位结果已经读入完毕，输出结果
        for (i = 1; i <= n; i++)
        {
            printf("%d", result[i]);
        }
        putchar('\n');
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                result[d] = i;
                visited[i] = 1;
                DFS(d+1);
                visited[i] = 0;
            }
        }
    }
    return;
}

int main()
{
    scanf("%d", &n);
    DFS(1); // 从第一位开始
    return 0;
}

