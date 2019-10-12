/*
 @Date    : 2018-03-07 18:59:03
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1139
注意题目中说的是用负号来表示性别，如果是-0000则读入整数为0便无法得知其性别
因此要用字符串接收
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>

using namespace std;

static const int MAXID = 10000;

static vector<set<int>> G(MAXID);
static bool isBoy[MAXID];
static int N, M;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    string temp_v, temp_w;
    int v, w;

    for (int i = 0; i != M; ++i)
    {
        cin >> temp_v >> temp_w;
        if (temp_v[0] == '-')
        {
            v = stoi(temp_v.substr(1, 4));
            isBoy[v] = false;
        }
        else
        {
            v = stoi(temp_v);
            isBoy[v] = true;
        }
        if (temp_w[0] == '-')
        {
            w = stoi(temp_w.substr(1, 4));
            isBoy[w] = false;
        }
        else
        {
            w = stoi(temp_w);
            isBoy[w] = true;
        }
        G[v].insert(w);
        G[w].insert(v);
    }

    int K;
    scanf("%d", &K);
    for (int i = 0; i != K; ++i)
    {
        cin >> temp_v >> temp_w;
        if (temp_v[0] == '-')
            v = stoi(temp_v.substr(1, 4));
        else
            v = stoi(temp_v);
        if (temp_w[0] == '-')
            w = stoi(temp_w.substr(1, 4));
        else
            w = stoi(temp_w);
        vector<pair<int, int>> solutions;
        for (int C : G[v])
        {
            if (C == w || isBoy[v] != isBoy[C]) continue;
            for (int D : G[C])
            {
                if (D != v && isBoy[D] == isBoy[w] && G[D].find(w) != G[D].end())
                    solutions.push_back(make_pair(C, D));
            }
        }
        sort(solutions.begin(), solutions.end(), cmp);
        printf("%d\n", solutions.size());
        for (auto eachSolution : solutions)
            printf("%04d %04d\n", eachSolution.first, eachSolution.second);
    }
    return 0;
}

