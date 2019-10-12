/*
 @Date    : 2018-02-28 10:06:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1113
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    int num[N];
    for (int i = 0; i != N; ++i)
        scanf("%d", &num[i]);
    sort(num, num+N);
    int n2 = N / 2;
    int S2 = 0, S1 = 0;
    S2 = accumulate(num, num+n2, 0);
    S1 = accumulate(num+n2, num+N, 0);
    if ((N & 1) == 0)
        printf("0 %d\n", S1 - S2);
    else
        printf("1 %d\n", S1 - S2);
    return 0;
}
