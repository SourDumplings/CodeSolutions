/*
 @Date    : 2018-02-02 15:42:52
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1063
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solveAndOutput(const set<int> &s1, const set<int> &s2)
{
    int total = s2.size();
    int common = 0;
    for (int i : s1)
    {
        if (s2.find(i) != s2.end())
            ++common;
        else
            ++total;
    }

    printf("%.1f%%\n", static_cast<double>(common) * 100 / total);
    return;
}

int main(int argc, char const *argv[])
{
    vector<set<int>> v;
    int N;
    scanf("%d", &N);
    int M;
    int d;
    set<int> temp;
    while (N--)
    {
        scanf("%d", &M);
        while (M--)
        {
            scanf("%d", &d);
            temp.insert(d);
        }
        v.push_back(temp);
        temp.clear();
    }
    int K;
    scanf("%d", &K);
    int s1, s2;
    while (K--)
    {
        scanf("%d %d", &s1, &s2);
        solveAndOutput(v[s1-1], v[s2-1]);
    }
    return 0;
}
