/*
 @Date    : 2017-12-08 15:13:47
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
    int id;
    Student next;
};

typedef struct COURSE *Course;
struct COURSE
{
    int c;
    Student head;
    int pickednum;
};

int Name2Id(char name[])
{
    int id;
    id = (name[0] - 'A') * 6760 + (name[1] - 'A') * 260 + (name[2] - 'A') * 10 + name[3] - '0';
    return id;
}

void Id2Name(char name[], int id)
{
    name[3] = id % 10 + '0';
    id /= 10;
    name[2] = id % 26 + 'A';
    id /= 26;
    name[1] = id % 26 + 'A';
    id /= 26;
    name[0] = id + 'A';
    return;
}

int main()
{
    int N, C, K, c;
    scanf("%d %d", &N, &K);
    int i, j, id;
    Course P[MAXK];
    Student S, last;
    char name[5];
    for (i = 0; i < K; i++)
    {
        P[i] = (Course)malloc(sizeof(struct COURSE));
        P[i]->c = i;
        P[i]->head = (Student)malloc(sizeof(struct STUDENT));
        P[i]->head->next = NULL;
        P[i]->head->id = -1;
        P[i]->pickednum = 0;
    }

    for (i = 0; i < N; i++)
    {
        scanf("%s %d", name, &C);
        id = Name2Id(name);
        for (j = 0; j < C; j++)
        {
            scanf("%d", &c);
            for (last = P[c-1]->head; last->next && last->next->id < id; last = last->next);
            S = (Student)malloc(sizeof(struct STUDENT));
            S->id = id;
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
                Id2Name(name, last->id);
                printf("%s\n", name);
            }
        }
    }
    return 0;
}

