/*
 @Date    : 2017-11-26 18:07:18
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1002
 */

#include <stdio.h>

#define MAXK 10

typedef struct PNODE Poly;
struct PNODE
{
    double c;
    int e;
};

void Initialize(Poly P[])
{
    int i;
    for (i = 0; i < MAXK; i++)
    {
        P[i].e = -1;
        P[i].c = -1;
    }
    return;
}

void ReadPoly(Poly P[])
{
    int K;
    scanf("%d", &K);
    int i;
    for (i = 0; i < K; i++)
    {
        scanf("%d %lf", &P[i].e, &P[i].c);
    }
    return;
}

int Add(Poly Sum[], Poly P1[], Poly P2[])
{
    int i, p1, p2;
    p1 = p2 = 0;
    int e;
    double c;
    for (i = 0; p1 < MAXK && p2 < MAXK && P1[p1].e != -1 && P2[p2].e != -1;)
    {
        if (P1[p1].e > P2[p2].e)
        {
            e = P1[p1].e;
            c = P1[p1].c;
            p1++;
        }
        else if (P2[p2].e > P1[p1].e)
        {
            e = P2[p2].e;
            c = P2[p2].c;
            p2++;
        }
        else
        {
            e = P1[p1].e;
            c = P1[p1].c + P2[p2].c;
            p1++;
            p2++;
        }
        if (c)
        {
            Sum[i].c = c;
            Sum[i].e = e;
            i++;
        }
    }
    while (p1 < MAXK && P1[p1].e != -1)
    {
        Sum[i].c = P1[p1].c;
        Sum[i].e = P1[p1].e;
        p1++;
        i++;
    }
    while (p2 < MAXK && P2[p2].e != -1)
    {
        Sum[i].c = P2[p2].c;
        Sum[i].e = P2[p2].e;
        p2++;
        i++;
    }
    return i;
}

void PrintPoly(Poly P[], int n)
{
    printf("%d", n);
    int i;
    // int output = 0;
    for (i = 0; i < n; i++)
    {
        printf(" %d %.1f", P[i].e, P[i].c);
        // if (!output)
        // {
        //     output = 1;
        // }
    }
    // if (!output)
    // {
    //     printf("0 0");
    // }
    putchar('\n');
    return;
}

int main()
{
    Poly P1[MAXK], P2[MAXK];
    Initialize(P1);
    Initialize(P2);
    ReadPoly(P1);
    ReadPoly(P2);
    Poly Sum[2*MAXK];
    Initialize(Sum);
    int n;
    n = Add(Sum, P1, P2);
    PrintPoly(Sum, n);
    return 0;
}

