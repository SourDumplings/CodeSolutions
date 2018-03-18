/*
 @Date    : 2017-12-06 21:03:16
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1041
 */

#include <stdio.h>
#include <stdlib.h>

int IsUnique(int bet, int num[], int N, int this_i)
{
    int i;
    int flag = 1;
    for (i = 0; i < N; i++)
    {
        if (i != this_i && num[i] == bet)
        {
            num[i] = -1;
            flag = 0;
        }
    }
    return flag;
}

int main()
{
    int N;
    scanf("%d", &N);
    int num[N];
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }
    for (i = 0; i < N; i++)
    {
        if (num[i] != -1 && IsUnique(num[i], num, N, i))
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

