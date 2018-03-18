/*
 @Date    : 2017-12-08 15:31:51
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
1.用桶排序的方式来存放输入的数。
2.遍历时从最小数v1开始，然后检查v2 = M - v1是否存在，没有则继续遍历直到nums[v2]存在.
这时就得到满足题目要求的最小数v1,且v1 + v2 = M。
 */

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, M;
    int i;
    int flag = 0, minV1, V2;
    scanf("%d %d", &N, &M);
    int coin[501];
    int value;

    for (i = 0; i < 501; i++)
    {
        coin[i] = 0;
    }

    for (i = 0; i < N; i++)
    {
        scanf("%d", &value);
        coin[value]++;
    }

    for (minV1 = 1; minV1 <= 500; minV1++)
    {
        if (coin[minV1] > 0)
        {
            coin[minV1]--;
            V2 = M - minV1;
            if (V2 <= 500 && V2 >= 1)
            {
                if (coin[V2] >= 1)
                {
                    flag = 1;
                    break;
                }
            }
        }
    }

    if (flag)
    {
        printf("%d %d\n", minV1, V2);
    }
    else
    {
        printf("No Solution\n");
    }
    return 0;
}

