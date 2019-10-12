/*
 @Date    : 2018-02-01 19:26:08
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1058
 */

#include <cstdio>

using namespace std;

long long getInput()
{
    long long G, S, K;
    scanf("%lld.%lld.%lld", &G, &S, &K);
    return K + S * 29 + G * 17 * 29;
}

void OutPut(long long kValue)
{
    long long K = kValue % 29;
    kValue /= 29;
    long long S = kValue % 17;
    long long G = kValue / 17;
    printf("%lld.%lld.%lld\n", G, S, K);
    return;
}

int main(int argc, char const *argv[])
{
    long long A = getInput();
    long long B = getInput();
    OutPut(A+B);
    return 0;
}
