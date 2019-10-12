/*
 @Date    : 2017-11-13 15:59:24
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/5865
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct ITEM *Poly;
struct ITEM
{
    int coef;
    int expo;
    Poly next;
};

Poly Read(int n)
{
    Poly P, rear, temp;
    int i;
    P = (Poly)malloc(sizeof(struct ITEM));
    P->next = NULL;
    rear = P;
    for (i = 0; i < n; i++)
    {
        temp = (Poly)malloc(sizeof(struct ITEM));
        temp->next = NULL;
        scanf("%d %d", &temp->coef, &temp->expo);
        rear->next = temp;
        rear = temp;
    }
    return P;
}

void Print(Poly P)
{
    Poly rear;
    rear = P->next;
    int output = 0, first = 1;
    while (rear)
    {
        if (rear->coef)
        {
            if (!first)
            {
                putchar(' ');
            }
            printf("%d %d", rear->coef, rear->expo);
            first = 0;
            output = 1;
        }
        rear = rear->next;
    }
    if (!output)
    {
        printf("0 0");
    }
    putchar('\n');
    return;
}

Poly Add(Poly P1, Poly P2)
{
    Poly SumP, temp, rp;
    Poly r1, r2;
    r1 = P1->next;
    r2 = P2->next;
    SumP = (Poly)malloc(sizeof(struct ITEM));
    SumP->next = NULL;
    rp = SumP;
    while (r1 && r2)
    {
        temp = (Poly)malloc(sizeof(struct ITEM));
        temp->next = NULL;
        if (r1->expo > r2->expo)
        {
            temp->coef = r1->coef;
            temp->expo = r1->expo;
            r1 = r1->next;
        }
        else if (r1->expo < r2->expo)
        {
            temp->coef = r2->coef;
            temp->expo = r2->expo;
            r2 = r2->next;
        }
        else
        {
            temp->coef = r1->coef + r2->coef;
            temp->expo = r1->expo;
            r1 = r1->next;
            r2 = r2->next;
        }
        rp->next = temp;
        rp = temp;
    }
    while(r1)
    {
        temp = (Poly)malloc(sizeof(struct ITEM));
        temp->next = NULL;
        temp->coef = r1->coef;
        temp->expo = r1->expo;
        r1 = r1->next;
        rp->next = temp;
        rp = temp;
    }
    while(r2)
    {
        temp = (Poly)malloc(sizeof(struct ITEM));
        temp->next = NULL;
        temp->coef = r2->coef;
        temp->expo = r2->expo;
        r2 = r2->next;
        rp->next = temp;
        rp = temp;
    }
    return SumP;
}

void Free(Poly P)
{
    Poly front, temp;
    front = P;
    while (front)
    {
        temp = front->next;
        free(front);
        front = temp;
    }
    return;
}

Poly Mult(Poly P1, Poly P2)
{
    Poly ProdP;
    Poly r1, r2;
    ProdP = (Poly)malloc(sizeof(struct ITEM));
    ProdP->next = NULL;
    r1 = P1->next;
    r2 = P2->next;
    Poly temp, P, r;
    // 用将P1中的每一项乘以P2得到的子多项式相加就是ProP
    while (r1)
    {
        P = (Poly)malloc(sizeof(struct ITEM));
        P->next = NULL;
        r = P;
        while (r2)
        {
            temp = (Poly)malloc(sizeof(struct ITEM));
            temp->coef = r1->coef * r2->coef;
            temp->expo = r1->expo + r2->expo;
            temp->next = NULL;
            r2 = r2->next;
            r->next = temp;
            r = temp;
        }
        ProdP = Add(P, ProdP);
        Free(P);
        r1 = r1->next;
        r2 = P2->next;
    }
    return ProdP;
}

int main()
{
    int n1, n2;
    Poly P1, P2;
    scanf("%d", &n1);
    P1 = Read(n1);
    scanf("%d", &n2);
    P2 = Read(n2);
    Poly ProdP;
    Poly SumP;
    ProdP = Mult(P1, P2);
    Print(ProdP);
    SumP = Add(P1, P2);
    Print(SumP);
    return 0;
}

