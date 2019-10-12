/*
 @Date    : 2017-12-08 10:38:29
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1047
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 40001
#define MAXK 2501

typedef struct STUDENT *Student;
struct STUDENT
{
    char name[5];
    Student next;
};

typedef struct COURSE *Course;
struct COURSE
{
    int c;
    Student head;
    int pickednum;
};

int main()
{
    int N, C, K, c;
    scanf("%d %d", &N, &K);
    int i, j;
    Course P[MAXK];
    Student S, last;
    char name[5];
    for (i = 0; i < K; i++)
    {
        P[i] = (Course)malloc(sizeof(struct COURSE));
        P[i]->c = i;
        P[i]->head = (Student)malloc(sizeof(struct STUDENT));
        P[i]->head->next = NULL;
        strcpy(P[i]->head->name, "head");
        P[i]->pickednum = 0;
    }

    for (i = 0; i < N; i++)
    {
        scanf("%s %d", name, &C);
        for (j = 0; j < C; j++)
        {
            scanf("%d", &c);
            for (last = P[c-1]->head; last->next && strcmp(last->next->name, name) < 0; last = last->next);
            S = (Student)malloc(sizeof(struct STUDENT));
            strcpy(S->name, name);
            S->next = last->next;
            last->next = S;
            P[c-1]->pickednum++;
        }
    }

    for (i = 0; i < K; i++)
    {
        printf("%d %d\n", i+1, P[i]->pickednum);
        if (P[i]->pickednum)
        {
            for (last = P[i]->head->next; last; last = last->next)
            {
                printf("%s\n", last->name);
            }
        }
    }
    return 0;
}

