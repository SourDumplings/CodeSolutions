/*
 @Date    : 2018-02-23 20:00:05
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1106
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

static double P, r;
static double minRetailorExp = 99999;

struct Person
{
    vector<int> distributors;
    int exp;
};

void DFS(Person data[], int root, int exp)
{
    data[root].exp = exp;
    if (data[root].distributors.empty())
    {
        if (data[root].exp < minRetailorExp)
            minRetailorExp = data[root].exp;
    }
    else
    {
        for (int d : data[root].distributors)
            DFS(data, d, exp + 1);
    }
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d %lf %lf", &N, &P, &r);
    int K, distributor;
    Person data[N];
    for (int i = 0; i != N; ++i)
    {
        scanf("%d", &K);
        for (int j = 0; j != K; ++j)
        {
            scanf("%d", &distributor);
            data[i].distributors.push_back(distributor);
        }
    }
    DFS(data, 0, 0);
    int minPriceNum;
    minPriceNum = count_if(data, data+N,
        [] (const Person &p) { return p.exp == minRetailorExp && p.distributors.empty(); });
    double minPrice = P * pow((1 + r / 100), minRetailorExp);
    printf("%.4f %d\n", minPrice, minPriceNum);
    return 0;
}
