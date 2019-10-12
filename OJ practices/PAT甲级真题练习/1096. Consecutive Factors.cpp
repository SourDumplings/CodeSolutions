/*
 @Date    : 2018-02-20 11:38:33
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1096
 */

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    int tempN = N;
    int maxConFactorNum = 0;
    int b = 0, e = 0;
    bool firstFactor = true;
    for (int i = 2; i < sqrt(N) + 1; ++i)
    {
        int j;
        tempN = N;
        if (tempN % i == 0)
        {
            if (firstFactor)
            {
                b = i;
                e = i + 1;
                firstFactor = false;
                maxConFactorNum = 1;
            }
            for (j = i; j < sqrt(N) + 1; ++j)
            {
                if (tempN % j == 0)
                    tempN /= j;
                else
                    break;
            }
            if (j - i > maxConFactorNum)
            {
                maxConFactorNum = j - i;
                b = i;
                e = j;
            }
        }
    }
    if (maxConFactorNum == 0)
    {
        maxConFactorNum = 1;
        b = N;
        e = N + 1;
    }
    printf("%d\n", maxConFactorNum);
    int output = 0;
    for (int i = b; i != e; ++i)
    {
        if (output++)
            putchar('*');
        printf("%d", i);
    }
    putchar('\n');
    return 0;
}
