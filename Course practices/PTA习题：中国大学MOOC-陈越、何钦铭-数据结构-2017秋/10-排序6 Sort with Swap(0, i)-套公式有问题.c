/*
 @Date    : 2017-11-20 16:42:40
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/900290821590183936/problems/926663572338114560
注意该代码只适用于0不是单元环并且多元环的个数K大于1的情况
 */

#include <stdio.h>
#include <stdlib.h>

# define MAX 100000


int A[MAX], T[MAX];
int S = 0, K = 0; // 分别为单环和多环的个数

// int compare(const void *a, const void *b)
// {
//     int k;
//     if (A[*(int *)a] - A[*(int *)b] < 0)
//     {
//         k = -1;
//     }
//     else if (A[*(int *)a] - A[*(int *)b] > 0)
//     {
//         k = 1;
//     }
//     else
//     {
//         k = 0;
//     }
//     return k;
// }

void Table_Sort(int N)
{
    int i = 0;
    // 根本不需要表排序，就可以建立出排序表
    for (i = 0; i < N; i++)
    {
        // T[i] = i;
        T[A[i]] = i;
    }
    // qsort(T, N, sizeof(T[0]), compare);
    return;
}

void CalcRing(int N)
{
    int i, j = 0;
    int temp, start;
    for (i = 0; i < N; i++)
    {
        if (T[i] == i)
        {
            S++;
        }
        else if (T[i] == -1)
        {
            continue;
        }
        else
        {
            start = A[i];
            j = i;
            while (1)
            {
                if (j == start)
                {
                    // 完成了一个环
                    // A[j] = start;
                    K++;
                    T[j] = -1;
                    break;
                }
                // A[j] = A[T[j]];
                temp = T[j];
                T[j] = -1; // 意味着这个位置的元素已经通过调整到该在的位置了
                j = temp;
            }
        }
    }
    return;
}

int main()
{
    int N, i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    Table_Sort(N);

    // printf("\n$$");
    // for (i = 0; i < N; i++)
    // {
    //     printf("%d ", A[T[i]]);
    // }
    // printf("$$\n");

    CalcRing(N);

    // printf("\n$$K = %d, S = %d\n", K, S);
    printf("%d\n", N-S+K-2); // 注意该公式只适用于0不是单元环并且多元环的个数K大于1

    return 0;
}

