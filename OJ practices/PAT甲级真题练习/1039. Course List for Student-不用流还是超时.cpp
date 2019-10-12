/*
 @Date    : 2018-01-27 19:51:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1039
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cstring>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, K;
    scanf("%d %d", &N, &K);
    int c, Ni;
    char name[5];
    map<string, set<int>> data;
    for (int i = 0; i != K; ++i)
    {
        scanf("%d %d", &c, &Ni);
        for (int i = 0; i != Ni; ++i)
        {
            scanf("%s", name);
            data[string(name)].insert(c);
        }
    }
    vector<string> query;
    for (int i = 0; i != N; ++i)
    {
        scanf("%s", name);
        query.push_back(string(name));
    }

    for (auto &name : query)
    {
        printf("%s %d", name.c_str(), data[name].size());
        for (auto it = data[name].begin(); it != data[name].end(); ++it)
            printf(" %d", *it);
        putchar('\n');
    }
    return 0;
}
