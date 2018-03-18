/*
 @Date    : 2017-11-28 09:50:01
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1009
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TOF 1E-5

typedef struct PNODE *Poly;
typedef struct PNODE *Pnode;
struct PNODE
{
    int e;
    double c;
    Pnode next;
};

Poly ReadPoly(Poly P)
{
    int N;
    scanf("%d", &N);
    int i;
    Pnode temp, rear = P;
    for (i = 0; i < N; i++)
    {
        temp = (Pnode)malloc(sizeof(struct PNODE));
        scanf("%d %lf", &temp->e, &temp->c);
        temp->next = NULL;
        rear->next = temp;
        rear = temp;
    }
    return P;
}

Poly Add(Poly P1, Poly P2)
{
    Poly P;
    P = (Poly)malloc(sizeof(struct PNODE));
    P->next = NULL;
    Pnode r1 = P1->next, r2 = P2->next, r = P;
    Pnode temp;
    int e;
    double c;
    while (r1 && r2)
    {
        if (r1->e > r2->e)
        {
            e = r1->e;
            c = r1->c;
            r1 = r1->next;
        }
        else if (r2->e > r1->e)
        {
            e = r2->e;
            c = r2->c;
            r2 = r2->next;
        }
        else
        {
            e = r2->e;
            c = r2->c + r1->c;
            r1 = r1->next;
            r2 = r2->next;
        }
        if (fabs(c) > TOF)
        {
            temp = (Pnode)malloc(sizeof(struct PNODE));
            temp->c = c;
            temp->e = e;
            temp->next = NULL;
            r->next = temp;
            r = temp;
        }
    }
    while (r1)
    {
        temp = (Pnode)malloc(sizeof(struct PNODE));
        temp->c = r1->c;
        temp->e = r1->e;
        temp->next = NULL;
        r->next = temp;
        r = temp;
        r1 = r1->next;
    }
    while (r2)
    {
        temp = (Pnode)malloc(sizeof(struct PNODE));
        temp->c = r2->c;
        temp->e = r2->e;
        temp->next = NULL;
        r->next = temp;
        r = temp;
        r2 = r2->next;
    }
    return P;
}

Poly Mult(Poly P1, Poly P2)
{
    Poly Result, P;
    Result = (Poly)malloc(sizeof(struct PNODE));
    Result->next = NULL;
    Pnode rp, r1, r2;
    int e;
    double c;
    Pnode temp;
    for (r1 = P1->next; r1; r1 = r1->next)
    {
        P = (Poly)malloc(sizeof(struct PNODE));
        P->next = NULL;
        rp = P;
        for (r2 = P2->next; r2; r2 = r2->next)
        {
            c = r1->c * r2->c;
            e = r1->e + r2->e;
            temp = (Pnode)malloc(sizeof(struct PNODE));
            temp->c = c;
            temp->e = e;
            temp->next = NULL;
            rp->next = temp;
            rp = temp;
        }
        Result = Add(Result, P);
    }
    return Result;
}

void PrintAndFreePoly(Poly P)
{
    int N = 0;
    Pnode r = P->next;
    while (r)
    {
        N++;
        r = r->next;
    }
    printf("%d", N);

    r = P->next;
    free(P);
    Pnode temp;
    while (r)
    {
        printf(" %d %.1f", r->e, r->c);
        temp = r;
        r = r->next;
        free(temp);
    }
    putchar('\n');
    return;
}

int main()
{
    Poly P1, P2;
    P1 = (Poly)malloc(sizeof(struct PNODE));
    P1->next = NULL;
    P2 = (Poly)malloc(sizeof(struct PNODE));
    P2->next = NULL;
    P1 = ReadPoly(P1);
    P2 = ReadPoly(P2);
    Poly Result;
    Result = Mult(P1, P2);
    PrintAndFreePoly(Result);
    return 0;
}

