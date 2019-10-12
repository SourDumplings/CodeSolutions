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

#define MAXH 40001
#define MAXK 2501

typedef struct STUDENT *Student;
struct STUDENT
{
    char name[5];
    int course[MAXK];
    int cn;
};

int HashTable[MAXH];

int Hash(char name[])
{
    int h;
    h = (name[0] - 'A') * 676 * 2 + (name[1] - 'A') * 26 * 2 + (name[2] - 'A');
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

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
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
            scanf("%d %d", &c, &n);
            for (j = 0; j < n; j++)
            {
                scanf("%s", name);
                p = Find(S, name);
                if (p == -1)
                {
                    S[snum] = (Student)malloc(sizeof(struct STUDENT));
                    strcpy(S[snum]->name, name);
                    S[snum]->course[0] = c;
                    S[snum]->cn = 1;
                    Insert(name, snum);
                    snum++;
                }
                else
                {
                    S[p]->course[S[p]->cn++] = c;
                }
            }
        }
        for (i = 0; i < snum; i++)
        {
            qsort(S[i]->course, S[i]->cn, sizeof(S[i]->course[0]), compare);
        }
        for (i = 0; i < N; i++)
        {
            scanf("%s", name);
            p = Find(S, name);
            if (p != -1)
            {
                printf("%s %d", S[p]->name, S[p]->cn);
                for (j = 0; j < S[p]->cn; j++)
                {
                    printf(" %d", S[p]->course[j]);
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
