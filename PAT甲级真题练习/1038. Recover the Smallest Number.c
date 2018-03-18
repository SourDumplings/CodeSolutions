/*
 @Date    : 2017-12-06 10:20:43
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1038
这个题目想到了应该不难, 无非是排序再加上贪心. 排序的规则要是想明白了代码非常精简.
两个片段字符串a, b 按照字典序如果a + b < b + a, 那么a应该排在前面, 否则b排在前面, 按照这样的排序然后按照顺序拼接即可.
第一, 注意前置000的判断. 特例是所有都是0的时候还是要输出一个0.
第二, 考虑这个例子的拼接3, 3330, 结果应该是33303而不是33330。对于2 026 029，结果应该是26029。对于2 00000 0000，结果应该是0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10001
#define INFINITY 99999999

int compare(const void *a, const void *b)
{
    char s1[18], s2[18];
    strcpy(s1, (char *)a);
    strcpy(s2, (char *)b);
    return strcmp(strcat(s1, (char *)b), strcat(s2, (char *)a));
}

int main()
{
    int N;
    char num[MAXN][9];
    int i, j;
    scanf("%d\n", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%s", num[i]);
    }

    // 输出第一位
    int minfirst = 9, first_i = 0;
    char firstnum[N][9];
    int f = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; num[i][j] != '\0' && num[i][j] == 0; j++);
        if (num[i][j] - '0' < minfirst && atoi(num[i]) != 0)
        {
            minfirst = num[i][j] - '0';
        }
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; num[i][j] != '\0' && num[i][j] == 0; j++);
        if (num[i][j] - '0' == minfirst && atoi(num[i]) != 0)
        {
            strcpy(firstnum[f++], num[i]);
        }
    }

    if (f)
    {
        qsort(firstnum, f, sizeof(firstnum[0]), compare);
        printf("%d", atoi(firstnum[0]));
    }
    else
    {
        // 说明是全0
        printf("0\n");
        return 0;
    }

    for (i = 0; i < N; i++)
    {
        // 懒惰删掉第一个元素
        if (strcmp(num[i], firstnum[0]) == 0)
        {
            first_i = i;
            break;
        }
    }


    char resnum[N-1][9];
    int r = 0;
    for (i = 0; i < N; i++)
    {
        // 懒惰删掉第一个元素
        if (i != first_i)
        {
            strcpy(resnum[r++], num[i]);
        }
    }
    qsort(resnum, N-1, sizeof(resnum[0]), compare);
    for (i = 0; i < N - 1; i++)
    {
        printf("%s", resnum[i]);
    }
    putchar('\n');

    return 0;
}

