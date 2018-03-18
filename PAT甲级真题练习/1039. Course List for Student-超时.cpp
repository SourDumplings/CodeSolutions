/*
 @Date    : 2018-01-27 19:17:10
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
#include <map>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, K;
    scanf("%d %d", &N, &K);
    int Ni, c;
    map<string, set<int>> data;
    string name;
    for (int i = 0; i != K; ++i)
    {
        scanf("%d %d", &c, &Ni);
        for (int j = 0; j != Ni; ++j)
        {
            cin >> name;
            data[name].insert(c);
        }
    }
    vector<string> query;
    for (int i = 0; i != N; ++i)
    {
        cin >> name;
        query.push_back(name);
    }

    for (auto name : query)
    {
        cout << name << " " << data[name].size();
        for (auto it = data[name].begin(); it != data[name].end(); ++it)
            printf(" %d", *it);
        putchar('\n');
    }
    return 0;
}
