/*
 @Date    : 2018-02-12 16:17:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/W/
 */

#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>

using namespace std;

bool is_prime(int n)
{
    for (int i = 2; i <= sqrt(static_cast<float>(n)); ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int get_prime_factor_num(int n)
{
    int res = 0;
    int k;
    for (int i = 2; i <= sqrt(static_cast<float>(n)); ++i)
    {
        if (n % i == 0)
        {
            k = n / i;
            if (i != k && is_prime(k))
                ++res;
            if (is_prime(i))
                ++res;
        }
    }
    return res;
}

bool cmp(const int &i1, const int &i2)
{
    int primeFactNum1 = get_prime_factor_num(i1);
    int primeFactNum2 = get_prime_factor_num(i2);
    if (primeFactNum1 == primeFactNum2)
        return i1 > i2;
    else
        return primeFactNum1 > primeFactNum2;
}

int main(int argc, char const *argv[])
{
    set<int, decltype(cmp)*> s(cmp);
    int num;
    scanf("%d", &num);
    while (num--)
    {
        int temp;
        for (int i = 0; i != 10; ++i)
        {
            scanf("%d", &temp);
            s.insert(temp);
        }
        int min = *s.begin();
        int max = *s.rbegin();
        s.erase(min);
        s.erase(max);
        printf("%d %d\n", min, max);
    }
    return 0;
}
