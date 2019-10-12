/*
 @Date    : 2017-11-20 16:42:40
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/900290821590183936/problems/926663572338114560
 */

#include <stdio.h>
#include <stdlib.h>

# define MAX 100000


int A[MAX], T[MAX];
int count = 0; // 计算所需交换的次数

void Table_Sort(int N)
{
    int i = 0;
    // 根本不需要表排序，就可以建立出排序表
    for (i = 0; i < N; i++)
    {
        T[A[i]] = i;
    }
    return;
}

void CalcRing(int N)
{
    int i, j = 0;
    int start, temp;
    int flag = 0; // 标记多元环内是否含有0
    int n = 0; // 统计每个多元环内元素个数
    for (i = 0; i < N; i++)
    {
        if (T[i] != i)
        {
            start = A[i];
            j = i;
            while (1)
            {
                if (j == 0)
                {
                    flag = 1;
                }
                if (j == start)
                {
                    // 完成了一个环
                    // A[j] = start;
                    T[j] = j;
                    n++;
                    if (flag)
                    {
                        count += n - 1;
                    }
                    else
                    {
                        count += n + 1;
                    }
                    n = 0;
                    flag = 0;
                    break;
                }
                // A[j] = A[T[j]];
                temp = T[j];
                T[j] = j; // 意味着这个位置的元素已经通过调整到该在的位置了
                j = temp;
                n++;
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
    printf("%d\n", count);

    return 0;
}

