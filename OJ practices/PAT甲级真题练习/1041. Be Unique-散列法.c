/*
 @Date    : 2017-12-06 21:16:13
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1041
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 10001

int H[MAXN];

int main()
{
    int N;
    scanf("%d", &N);
    int num[N];
    int i, h;
    for (i = 0; i < MAXN; i++)
    {
        H[i] = 0;
    }
    for (i = 0; i < N; i++)
    {
        scanf("%d", &h);
        num[i] = h;
        H[h]++;
    }
    for (i = 0; i < N; i++)
    {
        if (H[num[i]] == 1)
        {
            printf("%d\n", num[i]);
            break;
        }
    }
    if (i == N)
    {
        printf("None\n");
    }
    return 0;
}
