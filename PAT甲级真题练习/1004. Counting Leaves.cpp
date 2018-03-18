/*
 @Date    : 2018-03-17 11:09:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1004
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int level = 0;
    vector<int> children;
};

static const int MAXN = 100;
static Node data[MAXN];
static int N, M;

static vector<int> res;

void BFS(int r)
{
    queue<int> Q;
    data[r].level = 0;
    Q.push(r);
    int nowLevel = 0;
    int nowLevelNum = 0;
    while (!Q.empty())
    {
        int p = Q.front(); Q.pop();
        if (data[p].level > nowLevel)
        {
            res.push_back(nowLevelNum);
            nowLevelNum = 0;
            nowLevel = data[p].level;
        }
        if (data[p].children.empty())
        {
            ++nowLevelNum;
        }
        else
        {
            for (auto &c : data[p].children)
            {
                data[c].level = data[p].level + 1;
                Q.push(c);
            }
        }
    }
    res.push_back(nowLevelNum);
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    for (unsigned i = 0; i < M; ++i)
    {
        int id, K;
        scanf("%d %d", &id, &K);
        for (unsigned j = 0; j < K; ++j)
        {
            int c;
            scanf("%d", &c);
            data[id].children.push_back(c);
        }
    }
    BFS(1);
    int output = 0;
    for (auto &i : res)
    {
        if (output++)
        {
            putchar(' ');
        }
        printf("%d", i);
    }
    putchar('\n');
    return 0;
}

