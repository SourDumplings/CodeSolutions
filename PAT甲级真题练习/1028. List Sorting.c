/*
 @Date    : 2017-12-03 10:28:58
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1028
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STUDENT *Student;
struct STUDENT
{
    int id;
    char name[9];
    int grade;
};

int compareid(const void *a, const void *b)
{
    return (*(Student *)a)->id - (*(Student *)b)->id;
}

int comparename(const void *a, const void *b)
{
    int k;
    if (strcmp((*(Student *)a)->name, (*(Student *)b)->name) == 0)
    {
        k = (*(Student *)a)->id - (*(Student *)b)->id;
    }
    else
    {
        k = strcmp((*(Student *)a)->name, (*(Student *)b)->name);
    }
    return k;
}
int comparegrade(const void *a, const void *b)
{
    int k;
    if ((*(Student *)a)->grade == (*(Student *)b)->grade)
    {
        k = (*(Student *)a)->id - (*(Student *)b)->id;
    }
    else
    {
        k = (*(Student *)a)->grade - (*(Student *)b)->grade;
    }
    return k;
}

int main()
{
    int N, C;
    scanf("%d %d", &N, &C);
    Student S[N];
    int i;
    for (i = 0; i < N; i++)
    {
        S[i] = (Student)malloc(sizeof(struct STUDENT));
        scanf("%d %s %d", &S[i]->id, S[i]->name, &S[i]->grade);
    }
    int (*compare)(const void *, const void *);
    switch (C)
    {
        case 1 : compare = compareid; break;
        case 2 : compare = comparename; break;
        case 3 : compare = comparegrade; break;
    }
    qsort(S, N, sizeof(S[0]), compare);
    for (i = 0; i < N; i++)
    {
        printf("%06d %s %d\n", S[i]->id, S[i]->name, S[i]->grade);
    }
    return 0;
}

