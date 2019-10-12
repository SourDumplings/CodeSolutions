/*
 @Date    : 2018-02-22 19:04:55
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1103
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static const int MAXN = 401;
static vector<int> powerData(401);
static vector<int> thisFactors, resFactors;
static int thisFactorSum = 0, maxFactorSum = 0;
static int lastFactor; // 后一个因子不能大于前一个因子

void DFS(int N, int K, int P)
{
    if (K == 0)
    {
        if (N == 0)
        {
            if (thisFactorSum > maxFactorSum)
            {
                maxFactorSum = thisFactorSum;
                resFactors = thisFactors;
            }
            else if (thisFactorSum == maxFactorSum && thisFactors > resFactors)
                resFactors = thisFactors;
        }
    }
    else if (N != 0)
    {
        int tempLastFactor = lastFactor;
        for (int i = 1; i <= lastFactor; ++i)
        {
            if (powerData[i] > N) break;
            thisFactorSum += i;
            thisFactors.push_back(i);
            lastFactor = i;
            DFS(N - powerData[i], K - 1, P);
            lastFactor = tempLastFactor;
            thisFactorSum -= i;
            thisFactors.pop_back();
        }
    }
    return;
}

int my_power(int x, int e)
{
    int res = x;
    for (int i = 2; i != e + 1; ++i)
        res *= x;
    return res;
}

int main(int argc, char const *argv[])
{
    int N, K, P;
    scanf("%d %d %d", &N, &K, &P);
    for (int i = 1; i <= N; ++i)
        powerData[i] = my_power(i, P);
    lastFactor = N;
    DFS(N, K, P);
    if (!resFactors.empty())
    {
        int output = 0;
        printf("%d =", N);
        for (int f : resFactors)
        {
            if (output++) printf(" +");
            printf(" %d^%d", f, P);
        }
        putchar('\n');
    }
    else
        printf("Impossible\n");
    return 0;
}
