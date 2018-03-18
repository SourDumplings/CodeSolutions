/*
 @Date    : 2017-12-02 12:36:15
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1025
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXK 300
#define MAXN 100

typedef struct STUDENT *Student;
struct STUDENT
{
    char id[14];
    int grade;
    int lr, fr;
    int ln;
};

int compare(const void *a, const void *b)
{
    int k;
    if ((*(Student *)a)->grade > (*(Student *)b)->grade)
    {
        k = -1;
    }
    else if ((*(Student *)a)->grade < (*(Student *)b)->grade)
    {
        k = 1;
    }
    else
    {
        k = strcmp((*(Student *)a)->id, (*(Student *)b)->id);
    }
    return k;
}

void ReadRank(Student set[], int n, int loacal_num)
{
    int count = 1, r = 1;
    int i;
    for (i = 0; i < n; i++)
    {
        if (loacal_num)
        {
            set[i]->lr = r;
        }
        else
        {
            set[i]->fr = r;
        }
        if (i < n - 1 && set[i]->grade > set[i+1]->grade)
        {
            r += count;
            count = 1;
        }
        else
        {
            count++;
        }
    }
    return;
}

void FreeTable(Student set[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        free(set[i]);
    }
    return;
}

int main()
{
    int N, K;
    int i, j;
    scanf("%d", &N);
    Student S;
    int f = 0, l = 0;
    int sum = 0;
    Student final[MAXN*MAXK];
    Student local[MAXK];
    for (i = 0; i < N; i++)
    {
        l = 0;
        scanf("%d", &K);
        for (j = 0; j < K; j++)
        {
            S = (Student)malloc(sizeof(struct STUDENT));
            scanf("%s %d", S->id, &S->grade);
            S->ln = i + 1;
            local[l++] = S;
            final[f++] = S;
        }
        qsort(local, K, sizeof(local[0]), compare);
        ReadRank(local, K, i+1);
        sum += K;
    }
    qsort(final, sum, sizeof(final[0]), compare);
    ReadRank(final, sum, 0);
    printf("%d\n", sum);
    for (i = 0; i < sum; i++)
    {
        printf("%s %d %d %d\n", final[i]->id, final[i]->fr, final[i]->ln, final[i]->lr);
    }
    FreeTable(final, sum);
    return 0;
}

