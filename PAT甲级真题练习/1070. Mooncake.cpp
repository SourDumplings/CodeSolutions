/*
 @Date    : 2018-02-07 14:39:31
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1070
需要注意的是，存货应该也用double存储，否则会有个case报错，可能是精度问题。
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1001;

struct MoonCake
{
    double p, total_price;
    double total_amount;
} data[MAXN];

int main(int argc, char const *argv[])
{
    int N, D;
    scanf("%d %d", &N, &D);
    for (int i = 0; i != N; ++i)
        scanf("%lf", &data[i].total_amount);
    for (int i = 0; i != N; ++i)
    {
        scanf("%lf", &data[i].total_price);
        data[i].p = data[i].total_price / data[i].total_amount;
    }
    sort(data, data + N,
    [] (const MoonCake &m1, const MoonCake &m2) { return m1.p > m2.p; });
    double result = 0;
    for (int i = 0; i != N; ++i)
    {
        if (D > data[i].total_amount)
        {
            result += data[i].total_price;
            D -= data[i].total_amount;
        }
        else
        {
            result += data[i].p * D;
            break;
        }
    }
    printf("%.2f\n", result);

    return 0;
}
