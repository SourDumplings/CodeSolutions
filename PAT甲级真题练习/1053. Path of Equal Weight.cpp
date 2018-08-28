/*
 @Date    : 2018-08-28 20:41:41
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1053
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 101;
int N, M, S;

struct TreeNode
{
    int weight;
    vector<int> children;
};

TreeNode T[MAXN];

vector<int> thisPath;
vector<vector<int>> resPaths;
int thisW = 0;

void dfs(int r)
{
    thisPath.push_back(T[r].weight);
    thisW += T[r].weight;
    if (thisW == S)
    {
        if (T[r].children.empty())
        {
            resPaths.push_back(thisPath);
        }
    }
    else if (thisW < S)
    {
        for (int c : T[r].children)
        {
            dfs(c);
        }
    }

    thisPath.pop_back();
    thisW -= T[r].weight;
    return;
}

int main()
{
    scanf("%d %d %d", &N, &M, &S);
    for (int i = 0; i != N; ++i)
        scanf("%d", &T[i].weight);
    for (int i = 0; i != M; ++i)
    {
        int id, k;
        scanf("%d %d", &id, &k);
        for (int j = 0; j != k; ++j)
        {
            int c;
            scanf("%d", &c);
            T[id].children.push_back(c);
        }
    }

    dfs(0);

    sort(resPaths.rbegin(), resPaths.rend());
    for (auto &path : resPaths)
    {
        int output = 0;
        for (int p : path)
        {
            if (output++)
                putchar(' ');
            printf("%d", p);
        }
        putchar('\n');
    }
    return 0;
}
