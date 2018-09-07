/*
 @Date    : 2018-03-13 12:30:44
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/820
对于0多项式输出0 0
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

static const int MAXN = 1001;
static int P[MAXN];

int main(int argc, char const *argv[])
{
    fill(P, P+MAXN, 0);
    int c, e;
    while (cin >> c >> e)
        P[e] = c;
    P[0] = 0;
    for (int i = 1; i != MAXN; ++i)
    {
        if (P[i] != 0)
            P[i-1] = P[i] * i;
        P[i] = 0;
    }
    int output = 0;
    for (int i = MAXN - 1; i != -1; --i)
    {
        if (P[i] != 0)
        {
            if (output++) putchar(' ');
            printf("%d %d", P[i], i);
        }
    }
    if (output == 0)
        printf("0 0");
    putchar('\n');
    return 0;
}

