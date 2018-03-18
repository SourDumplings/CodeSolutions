/*
 @Date    : 2018-03-01 10:04:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1116
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define EMPTY -1
#define CHECKED -2

static int N;
static const int MAXN = 10001;
static int rankData[MAXN];

bool is_prime(int n)
{
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n) + 1; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    fill(rankData, rankData+MAXN, EMPTY);
    scanf("%d", &N);
    int id;
    for (int i = 0; i != N; ++i)
    {
        scanf("%d", &id);
        rankData[id] = i + 1;
    }
    int K;
    scanf("%d", &K);
    while (K--)
    {
        scanf("%d", &id);
        if (rankData[id] == EMPTY)
            printf("%04d: Are you kidding?\n", id);
        else if (rankData[id] == CHECKED)
            printf("%04d: Checked\n", id);
        else if (rankData[id] == 1)
        {
            printf("%04d: Mystery Award\n", id);
            rankData[id] = CHECKED;
        }
        else if (is_prime(rankData[id]))
        {
            printf("%04d: Minion\n", id);
            rankData[id] = CHECKED;
        }
        else
        {
            printf("%04d: Chocolate\n", id);
            rankData[id] = CHECKED;
        }
    }
    return 0;
}
