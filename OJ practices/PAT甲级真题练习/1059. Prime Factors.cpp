/*
 @Date    : 2018-02-01 19:40:32
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1059
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> primeNum = {2};
int output = 0;
int k = 0;

bool isPrime(long long num)
{
    auto it = primeNum.begin();
    for (; it != primeNum.end(); ++it)
    {
        if (num % *it == 0)
            return false;
    }
    return true;
}

long long nextPrime(long long last_one)
{
    long long next_prime;
    if (last_one == 2)
        next_prime = 3;
    else
        for (next_prime = last_one + 2; !isPrime(next_prime); next_prime += 2);
    return next_prime;
}

void deFactor(long long N)
{
    if (N == 1)
        putchar('\n');
    else
    {
        long long last_try = primeNum[primeNum.size()-1];
        k = 0;
        while (N % last_try != 0)
        {
            last_try = nextPrime(last_try);
            primeNum.push_back(last_try);
        }
        primeNum.push_back(last_try);
        while (N % last_try == 0)
        {
            ++k;
            N /= last_try;
        }
        if (output++)
            putchar('*');
        if (k > 1)
            printf("%lld^%d", last_try, k);
        else
            printf("%lld", last_try);
        deFactor(N);
    }
    return;
}

int main(int argc, char const *argv[])
{
    long long N;
    scanf("%lld", &N);
    printf("%lld=", N);
    if (N == 1)
        printf("1\n");
    else
        deFactor(N);
    return 0;
}
