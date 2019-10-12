/*
 @Date    : 2017-12-06 16:37:09
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1039
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXH 200000

typedef struct COURSE *Course;
struct COURSE
{
    int c;
    Course next;
};

typedef struct STUDENT *Student;
struct STUDENT
{
    char name[5];
    Course head;
    int cn;
};

int HashTable[MAXH];

int Hash(char name[])
{
    int h;
    h = (name[0] - 'A') * 6760 + (name[1] - 'A') * 260 + (name[2] - 'A') * 10 + (name[3] - '0');
    return h;
}

int Find(Student S[], char name[])
{
    int h;
    h = Hash(name);
    int i;
    for (i = h; HashTable[i] != -1 && strcmp(S[HashTable[i]]->name, name); i++);
    return HashTable[i];
}

void Insert(char name[], int p)
{
    int h;
    int i;
    h = Hash(name);
    // printf("$$The hash of name %s is %d$$\n", name, h);
    for (i = h; HashTable[i] != -1; i++);
    HashTable[i] = p;
    return;
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    int i, j;
    int c, n;
    char name[5];
    int snum = 0;
    int p;
    Course temp, last;
    Student S[N];
    for (i = 0; i < MAXH; i++)
    {
        HashTable[i] = -1;
    }
    if (N)
    {
        for (i = 0; i < N; i++)
        {
            S[i] = NULL;
        }
        for (i = 0; i < K; i++)
        {
            scanf("%d %d\n", &c, &n);
            for (j = 0; j < n; j++)
            {
                scanf("%s", name);
                p = Find(S, name);
                if (p == -1)
                {
                    S[snum] = (Student)malloc(sizeof(struct STUDENT));
                    strcpy(S[snum]->name, name);
                    S[snum]->head = (Course)malloc(sizeof(struct COURSE));
                    S[snum]->head->c = 0;
                    S[snum]->head->next = NULL;
                    temp = (Course)malloc(sizeof(struct COURSE));
                    temp->c = c;
                    temp->next = NULL;
                    S[snum]->cn = 1;
                    S[snum]->head->next = temp;
                    Insert(name, snum);
                    snum++;
                }
                else
                {
                    S[p]->cn++;
                    temp = (Course)malloc(sizeof(struct COURSE));
                    temp->c = c;
                    for (last = S[p]->head; last->next && last->next->c < c; last = last->next);
                    temp->next = last->next;
                    last->next = temp;
                }
            }
        }
        for (i = 0; i < N; i++)
        {
            scanf("%s", name);
            p = Find(S, name);
            if (p != -1)
            {
                printf("%s %d", S[p]->name, S[p]->cn);
                for (temp = S[p]->head->next; temp; temp = temp->next)
                {
                    printf(" %d", temp->c);
                }
                putchar('\n');
            }
            else
            {
                printf("%s 0\n", name);
            }
        }
    }
    return 0;
}

