/*
 @Date    : 2018-02-16 17:10:13
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1085
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, p;
    scanf("%d %d", &N, &p);
    long long num[N];
    for (int i = 0; i != N; ++i)
        scanf("%lld", &num[i]);
    sort(num, num+N);
    int maxl = 0;
    int l, last_s = N - 1;
    for (int e = N - 1; e != -1; --e)
    {
        int s;
        if (last_s > 0 && num[e] > num[last_s-1] * p)
            continue;
        for (s = last_s - 1; s != -1; --s)
        {
            if (num[e] > num[s] * p)
                break;
        }
        l = e - s;
        last_s = s + 1;
        if (l > maxl)
            maxl = l;
    }
    printf("%d\n", maxl);
    return 0;
}
