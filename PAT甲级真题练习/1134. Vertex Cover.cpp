/*
 @Date    : 2018-03-06 19:49:46
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1134
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

static int N, M;

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    vector<pair<int, int>> edgeData(M);
    for (int i = 0; i != M; ++i)
    {
        int v, w;
        scanf("%d %d", &v, &w);
        auto p = make_pair(v, w);
        edgeData[i] = p;
    }
    int K;
    scanf("%d", &K);
    for (int i = 0; i != K; ++i)
    {
        int Nv, v;
        scanf("%d", &Nv);
        set<int> s;
        for (int i = 0; i != Nv; ++i)
        {
            scanf("%d", &v);
            s.insert(v);
        }
        bool ok = true;
        for (auto eachEdge : edgeData)
        {
            if (s.find(eachEdge.first) == s.end() && s.find(eachEdge.second) == s.end())
            {
                ok = false;
                break;
            }
        }
        if (ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

