/*
 @Date    : 2018-03-10 15:58:05
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/710
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

static const int MAXN = 5000;

static int P1[MAXN], P2[MAXN], Pa[MAXN], Pm[MAXN];

void read(int P[])
{
    int N;
    scanf("%d", &N);
    int c, e;
    for (int i = 0; i != N; ++i)
    {
        scanf("%d %d", &c, &e);
        P[e+1000] = c;
    }
    return;
}

void print(int P[])
{
    int output = 0;
    for (int i = MAXN - 1; i != -1; --i)
    {
        if (P[i])
        {
            if (output++) putchar(' ');
            printf("%d %d", P[i], i - 1000);
        }
    }
    if (output == 0) printf("0 0");
    putchar('\n');
    return;
}

void add(int Pa[], int P1[], int P2[])
{
    for (int i = 0; i != MAXN; ++i)
        Pa[i] = P1[i] + P2[i];
    return;
}

void mult(int Pm[], int P1[], int P2[])
{
    for (int i = 0; i != MAXN; ++i)
    {
        for (int j = 0; j != MAXN; ++j)
        {
            if (P1[i] && P2[j])
                Pm[i+j-1000] += P1[i] * P2[j];
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    memset(P1, 0, sizeof(P1));
    memset(P2, 0, sizeof(P2));
    memset(Pa, 0, sizeof(Pa));
    memset(Pm, 0, sizeof(Pm));
    read(P1);
    read(P2);
    add(Pa, P1, P2);
    mult(Pm, P1, P2);
    print(Pm);
    print(Pa);
    return 0;
}

