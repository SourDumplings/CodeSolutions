/*
 @Date    : 2018-02-15 16:10:15
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1079
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <cmath>

using namespace std;

struct TNode
{
    int supplier = -1;
    vector<int> distributors;
    int sell = 0;
};

static const int MAXN = 100001;
int N;
double P, r;
static array<TNode, MAXN> T;

double calc_price(int supplier, int exp)
{
    double price = 0;
    if (T[supplier].distributors.size())
    {
        for (auto dis_it = T[supplier].distributors.begin();
            dis_it != T[supplier].distributors.end(); ++dis_it)
            price += calc_price(*dis_it, exp + 1);
    }
    else
        price = T[supplier].sell * P * pow((1 + r / 100), exp);
    return price;
}

int main(int argc, char const *argv[])
{
    scanf("%d %lf %lf", &N, &P, &r);
    int K;
    int distributor, sell;
    for (int i = 0; i != N; ++i)
    {
        scanf("%d", &K);
        if (K)
        {
            while (K--)
            {
                scanf("%d", &distributor);
                T[i].distributors.push_back(distributor);
            }
        }
        else
        {
            scanf("%d", &sell);
            T[i].sell = sell;
        }
    }
    double price = calc_price(0, 0);
    printf("%.1f\n", price);
    return 0;
}
