/*
 @Date    : 2017-11-18 10:37:29
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/6104
 */

#include <stdio.h>
#include <stdlib.h>

#define INFINISMALL -10001

void Insert(int H[], int X, int *pHsize)
{
    int i;
    i = ++(*pHsize);
    for (; H[i/2] > X; i /= 2)
    {
        H[i] = H[i/2];
    }
    H[i] = X;
    return;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int H[N+1];
    H[0] = INFINISMALL;
    int i;
    int X;
    int output = 0;
    int H_size = 0;
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &X);
        Insert(H, X, &H_size);
    }
    int data_i;
    for (i = 0; i < M; i++)
    {
        scanf("%d", &data_i);
        do
        {
            if (output++)
            {
                putchar(' ');
            }
            printf("%d", H[data_i]);
            data_i /= 2;
        } while (data_i > 0);
        putchar('\n');
        output = 0;
    }

    return 0;
}

