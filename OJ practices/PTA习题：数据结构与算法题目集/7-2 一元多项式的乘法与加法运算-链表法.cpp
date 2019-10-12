/*
 @Date    : 2018-03-10 15:09:29
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/710
 */

#include <iostream>
#include <cstdio>

using namespace std;

typedef struct PolyNode *Poly;
struct PolyNode
{
    int c, e;
    Poly next = nullptr;
};

Poly read()
{
    int N;
    scanf("%d", &N);
    Poly P = new PolyNode;
    Poly rear = P;
    for (int i = 0; i != N; ++i)
    {
        Poly temp = new PolyNode;
        scanf("%d %d", &temp->c, &temp->e);
        rear->next = temp;
        rear = temp;
    }
    return P;
}

Poly add(Poly P1, Poly P2)
{
    Poly P = new PolyNode;
    Poly r1 = P1->next, r2 = P2->next, r, rear = P;
    while (r1 && r2)
    {
        r = new PolyNode;
        if (r1->e > r2->e)
        {
            r->e = r1->e;
            r->c = r1->c;
            r1 = r1->next;
        }
        else if (r1->e < r2->e)
        {
            r->e = r2->e;
            r->c = r2->c;
            r2 = r2->next;
        }
        else
        {
            r->e = r1->e;
            r->c = r1->c + r2->c;
            r1 = r1->next;
            r2 = r2->next;
        }
        rear->next = r;
        rear = r;
    }
    while (r1)
    {
        r = new PolyNode;
        r->c = r1->c;
        r->e = r1->e;
        r1 = r1->next;
        rear->next = r;
        rear = r;
    }
    while (r2)
    {
        r = new PolyNode;
        r->c = r2->c;
        r->e = r2->e;
        r2 = r2->next;
        rear->next = r;
        rear = r;
    }
    return P;
}

Poly mult(Poly P1, Poly P2)
{
    Poly P = new PolyNode;
    Poly r1 = P1->next;
    Poly r;
    while (r1)
    {
        Poly r2 = P2->next;
        Poly tempSum = new PolyNode;
        Poly rear = tempSum;
        while (r2)
        {
            r = new PolyNode;
            r->e = r1->e + r2->e;
            r->c = r1->c * r2->c;
            rear->next = r;
            rear = r;
            r2 = r2->next;
        }
        P = add(P, tempSum);
        r1 = r1->next;
    }
    return P;
}

void print(Poly P)
{
    int output = 0;
    for (Poly p = P->next; p; p = p->next)
    {
        if (p->c)
        {
            if (output++) putchar(' ');
            printf("%d %d", p->c, p->e);
        }
    }
    if (output == 0)
        printf("0 0");
    putchar('\n');
    return;
}

void free_space(Poly P)
{
    Poly f = P;
    while (f)
    {
        Poly next = f->next;
        delete f;
        f = next;
    }
    return;
}

int main(int argc, char const *argv[])
{
    Poly P1 = read();
    Poly P2 = read();
    Poly Pa = add(P1, P2);
    Poly Pm = mult(P1, P2);
    print(Pm);
    print(Pa);
    free_space(P1);
    free_space(P2);
    free_space(Pa);
    free_space(Pm);
    return 0;
}

