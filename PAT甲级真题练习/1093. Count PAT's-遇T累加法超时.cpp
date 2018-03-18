/*
 @Date    : 2018-02-18 18:14:10
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1093
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

static const int MOD = 1000000007;
static const int MAXL = 100001;
static char str[MAXL];
static int lastTpos = -1;
static int lastApos = -1;
static int pNumBeforeLastA = 0;
static long long pABeforeLastT = 0;

long long count_pa_added(int thisTPos)
{
    long long res = 0;
    for (int i = lastApos + 1; i != thisTPos; ++i)
    {
        if (str[i] == 'A')
        {
            int pNumBeforeThisA = pNumBeforeLastA +
            count(str + lastApos + 1, str + i, 'P');
            lastApos = i;
            pNumBeforeLastA = pNumBeforeThisA;
            res += pNumBeforeThisA;
        }
    }
    return res % MOD;
}

int main(int argc, char const *argv[])
{
    long long res = 0;
    gets(str);
    int l = strlen(str);
    for (int i = 0; i != l; ++i)
    {
        if (str[i] == 'T')
        {
            long long pAAdded = count_pa_added(i);
            // printf("pAAdded = %lld\n", pAAdded);
            res += pABeforeLastT + pAAdded;
            pABeforeLastT += pAAdded;
            res %= MOD;
            // printf("res = %lld\n", res);
            lastTpos = i;
        }
    }
    printf("%lld\n", res);
    return 0;
}
