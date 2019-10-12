/*
 @Date    : 2018-03-13 11:10:38
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/722
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    map<long long, int> data;
    while (N--)
    {
        long long n1, n2;
        cin >> n1 >> n2;
        ++data[n1];
        ++data[n2];
    }
    auto maxP = *max_element(data.begin(), data.end(),
        [] (const pair<long long, int> &p1, const pair<long long, int> &p2)
        {
            return p1.second < p2.second;
        });
    int maxN = maxP.second;
    int c = count_if(data.begin(), data.end(), [maxN] (const pair<long long, int> &p)
        { return p.second == maxN; });
    printf("%lld %d", maxP.first, maxP.second);
    if (c != 1)
        printf(" %d", c);
    putchar('\n');
    return 0;
}

