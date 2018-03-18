/*
 @Date    : 2017-11-27 19:04:00
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1006
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct PERSON *Person;
struct PERSON
{
    char id[16];
    int inh, inm, ins;
    int outh, outm, outs;
};

int comparein(const void *a, const void *b)
{
    int k;
    if ((*(Person *)a)->inh < (*(Person *)b)->inh)
    {
        k = -1;
    }
    else if ((*(Person *)a)->inh > (*(Person *)b)->inh)
    {
        k = 1;
    }
    else
    {
        if ((*(Person *)a)->inm < (*(Person *)b)->inm)
        {
            k = -1;
        }
        else if ((*(Person *)a)->inm > (*(Person *)b)->inm)
        {
            k = 1;
        }
        else
        {
            if ((*(Person *)a)->ins < (*(Person *)b)->ins)
            {
                k = -1;
            }
            else if ((*(Person *)a)->ins > (*(Person *)b)->ins)
            {
                k = 1;
            }
            else
            {
                k = 0;
            }
        }
    }
    return k;
}
int compareout(const void *a, const void *b)
{
    int k;
    if ((*(Person *)a)->outh < (*(Person *)b)->outh)
    {
        k = -1;
    }
    else if ((*(Person *)a)->outh > (*(Person *)b)->outh)
    {
        k = 1;
    }
    else
    {
        if ((*(Person *)a)->outm < (*(Person *)b)->outm)
        {
            k = -1;
        }
        else if ((*(Person *)a)->outm > (*(Person *)b)->outm)
        {
            k = 1;
        }
        else
        {
            if ((*(Person *)a)->outs < (*(Person *)b)->outs)
            {
                k = -1;
            }
            else if ((*(Person *)a)->outs > (*(Person *)b)->outs)
            {
                k = 1;
            }
            else
            {
                k = 0;
            }
        }
    }
    return k;
}

int main()
{
    int M;
    scanf("%d", &M);
    int i;
    Person P[M];
    for (i = 0; i < M; i++)
    {
        P[i] = (Person)malloc(sizeof(struct PERSON));
        scanf("%s %d:%d:%d %d:%d:%d",
            P[i]->id, &P[i]->inh, &P[i]->inm, &P[i]->ins, &P[i]->outh, &P[i]->outm, &P[i]->outs);
    }
    qsort(P, M, sizeof(P[0]), comparein);
    printf("%s ", P[0]->id);
    qsort(P, M, sizeof(P[0]), compareout);
    printf("%s\n", P[M-1]->id);
    return 0;
}

