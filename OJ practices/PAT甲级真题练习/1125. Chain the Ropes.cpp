/*
 @Date    : 2018-03-03 18:39:42
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1125
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    double num[N];
    for (int i = 0; i != N; ++i) scanf("%lf", &num[i]);
    sort(num, num+N);
    double sum = num[0] / pow(2, N - 1);
    for (int i = 1; i != N; ++i)
        sum += num[i] / pow(2, N - i);
    printf("%d\n", static_cast<int>(sum));
    return 0;
}
