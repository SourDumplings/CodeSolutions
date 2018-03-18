/*
 @Date    : 2017-12-05 16:08:37
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1045
借助记忆矩阵， 例如对于题目中的例子：
                 0  2  2  4  1  5  5  6  3  1  1  5  6

                 0  0  0  0  0  0  0  0  0  0  0  0  0
2           2    0  1  2  2  2  2  2  2  2  2  2  2  2
2 3         3    0  1  2  2  2  2  2  2  3  3  3  3  3
2 3 1       1    0  1  2  2  3  3  3  3  3  4  5  5  5
2 3 1 5     5    0  1  2  2  3  4  5  5  5  5  5  6  6
2 3 1 5 6   6    0  1  2  2  3  4  5  6  6  6  6  6  7
可以发现，对于该矩阵每一行每一列的元素都是当前子列的长度最大值
并且每个元素都是其左边元素和上边元素的较大值，如果所在行列的对应的元素相等，则再加一
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 201
#define MAXL 10001

int N;
int M;
int L;
int colors[MAXL];
int favorite[MAXN];
int maxlength = 0;
int result[MAXN][MAXL];

int Solve(void)
{
    int i, j;
    int max;
    for (i = 0; i <= M; i++)
    {
        for (j = 0; j <= L; j++)
        {
            result[i][j] = 0;
        }
    }
    for (i = 1; i <= M; i++)
    {
        for (j = 1; j <= L; j++)
        {
            max = result[i-1][j-1];
            if (result[i-1][j] > max)
            {
                max = result[i-1][j];
            }
            if (result[i][j-1] > max)
            {
                max = result[i][j-1];
            }

            if (favorite[i] == colors[j])
            {
                result[i][j] = max + 1;
            }
            else
            {
                result[i][j] = max;
            }

            // int k;
            // printf("$$max = %d\n", max);
            // for (k = 1; k < L; k++)
            // {
            //     printf("%d ", result[i][k]);
            // }
            // printf("$$\n");
        }
    }
    return result[M][L];
}

int main()
{
    scanf("%d", &N);
    scanf("%d", &M);
    int i;
    for (i = 1; i <= M; i++)
    {
        scanf("%d", &favorite[i]);
    }

    scanf("%d", &L);
    for (i = 1; i <= L; i++)
    {
        scanf("%d", &colors[i]);
    }

    maxlength = Solve();

    // int j;
    // for (i = 1; i <= M; i++)
    // {
    //     for (j = 1; j <= L; j++)
    //     {
    //         printf("%d ", result[i][j]);
    //     }
    //     putchar('\n');
    // }

    printf("%d\n", maxlength);
    return 0;
}

