/*
 @Date    : 2018-12-26 12:52:46
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/1071785055080476672
 */

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int stonum(char num[], int b, int k)
{
    int res = 0;
    for (int i = b; i != b + k; ++i)
    {
        res *= 10;
        res += num[i] - '0';
    }
    return res;
}

int lastNum = -1;
int mod;

bool judge(char num[], int b, int k)
{
    int n;
    if (lastNum == -1)
    {
        n = stonum(num, b, k);
    }
    else
    {
        n = lastNum % mod * 10 + num[b + k - 1] - '0';
    }
    lastNum = n;

    if (n == 2)
        return true;
    else if (n % 2 == 0)
    {
        return false;
    }
    else
    {
        for (int i = 3; i <= sqrt(n); i += 2)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int L, K;
    scanf("%d %d", &L, &K);
    char num[L+1];
    scanf("%s", num);
    bool flag = false;
    mod = pow(10, K-1);

    for (int i = 0; i + K <= L; ++i)
    {
        if(judge(num, i, K))
        {
            for (int j = i; j < i + K; ++j)
            {
                printf("%c", num[j]);
            }
            putchar('\n');
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        printf("404\n");
    }
    return 0;
}

