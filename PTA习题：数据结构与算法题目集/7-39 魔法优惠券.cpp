/*
 @Date    : 2018-03-15 13:25:38
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/866
 */

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d", &N);
    priority_queue<long long> cP;
    priority_queue<long long, vector<long long>, greater<long long>> cN;
    long long c;
    for (unsigned i = 0; i < N; ++i)
    {
        scanf("%lld", &c);
        if (c > 0)
            cP.push(c);
        else
            cN.push(c);
    }
    scanf("%d", &M);
    priority_queue<long long> pP;
    priority_queue<long long, vector<long long>, greater<long long>> pN;
    long long p;
    for (unsigned i = 0; i < M; ++i)
    {
        scanf("%lld", &p);
        if (p > 0)
            pP.push(p);
        else
            pN.push(p);
    }
    long long res = 0;
    while (!cN.empty() && !pN.empty())
    {
        res += cN.top() * pN.top();
        cN.pop(); pN.pop();
    }
    while (!cP.empty() && !pP.empty())
    {
        res += cP.top() * pP.top();
        cP.pop(); pP.pop();
    }
    printf("%lld\n", res);
    return 0;
}

