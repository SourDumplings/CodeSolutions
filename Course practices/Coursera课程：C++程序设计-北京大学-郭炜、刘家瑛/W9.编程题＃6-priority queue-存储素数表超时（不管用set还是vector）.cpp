/*
 @Date    : 2018-02-12 13:59:00
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/W/
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

static vector<int> primeNums = {2};
static map<int, int> primeFactorNums;

bool is_prime(int n)
{
    for (auto it = primeNums.begin(); it != primeNums.end(); ++it)
    {
        if (n % *it == 0)
            return false;
    }
    return true;
}

int get_next_prime()
{
    int lastPrime = primeNums.back();
    int nextPrime;
    for (nextPrime = lastPrime + 1; !is_prime(nextPrime); ++nextPrime);
    primeNums.push_back(nextPrime);
    return nextPrime;
}

int get_prime_factor_num(int n)
{
    int res = 1;
    while (n > 1)
    {
        bool foundPrimeFactor = false;
        for (auto it = primeNums.begin(); it != primeNums.end(); ++it)
        {
            if (n % *it == 0)
            {
                foundPrimeFactor = true;
                do { n /= *it; } while (n % *it); // 这里浪费时间了
                ++res;
                break;
            }
        }
        if (n > 1 && !foundPrimeFactor)
        {
            int nextPrime;
            do
            {
                nextPrime = get_next_prime();
            } while (n % nextPrime);
            do { n /= nextPrime; } while (n % nextPrime); // 这里浪费时间了
            ++res;
        }
    }
    return res;
}

bool cmp(const int &i1, const int &i2)
{
    int primeFactorNum1 = primeFactorNums[i1];
    int primeFactorNum2 = primeFactorNums[i2];
    if (primeFactorNum1 == primeFactorNum2)
        return i1 > i2;
    else
        return primeFactorNum1 > primeFactorNum2;
}

int main(int argc, char const *argv[])
{
    int num;
    scanf("%d", &num);
    set<int, decltype(cmp)*> s(cmp);
    while (num--)
    {
        int temp;
        for (int i = 0; i != 10; ++i)
        {
            scanf("%d", &temp);
            primeFactorNums[temp] = get_prime_factor_num(temp);
            s.insert(temp);
        }
        printf("%d %d\n", *s.begin(), *s.rbegin());
        s.erase(*s.begin());
        s.erase(*s.rbegin());
    }
    return 0;
}
