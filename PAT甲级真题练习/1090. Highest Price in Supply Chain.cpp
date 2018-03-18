/*
 @Date    : 2018-02-17 12:30:23
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1090
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

struct Person
{
    int exp;
    int id;
};

static int N;
static double P, r;

void get_exp(multimap<int, Person> &data, Person &root, int exp)
{
    root.exp = exp;
    auto b = data.lower_bound(root.id), e = data.upper_bound(root.id);
    for (auto it = b; it != e; ++it)
        get_exp(data, it->second, exp+1);
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %lf %lf", &N, &P, &r);
    multimap<int, Person> data;
    int supplier;
    for (int i = 0; i != N; ++i)
    {
        scanf("%d", &supplier);
        Person tempP;
        tempP.id = i;
        data.insert(make_pair(supplier, tempP));
    }
    Person root = data.find(-1)->second;
    get_exp(data, root, 0);
    int maxExp = max_element(data.begin(), data.end(),
        [] (const pair<int, Person> &p1, const pair<int, Person> &p2)
        { return p1.second.exp < p2.second.exp; })->second.exp;
    double maxPrice = P * pow((1 + r / 100), maxExp);
    int maxNum = count_if(data.begin(), data.end(),
        [maxExp] (const pair<int, Person> &p) { return p.second.exp == maxExp; });
    printf("%.2f %d\n", maxPrice, maxNum);
    return 0;
}
