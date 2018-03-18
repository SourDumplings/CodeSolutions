/*
 @Date    : 2018-01-28 14:36:41
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1053
 */

#include <cstdio>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

struct treeNode
{
    int id, weight;
    vector<int> children;
};

vector<int> tempPath;

void recordPath(vector<vector<int>> &path)
{
    path.push_back(tempPath);
    return;
}

void DFS(const array<treeNode, 100> &T, vector<vector<int>> &path, int root,
    int nowWeight, int S)
{
    tempPath.push_back(T[root].weight);
    if (T[root].weight + nowWeight >= S)
    {
        if (T[root].weight + nowWeight == S && T[root].children.size() == 0)
            recordPath(path);
        tempPath.pop_back();
        return;
    }
    else
    {
        if (T[root].children.size())
        {
            for (auto c : T[root].children)
                DFS(T, path, c, nowWeight+T[root].weight, S);
        }
        else
        {
            tempPath.pop_back();
            return;
        }
    }
    tempPath.pop_back();
    return;
}

int main(int argc, char const *argv[])
{
    int N, M, S;
    array<treeNode, 100> T;
    scanf("%d %d %d", &N, &M, &S);
    int W;
    for (int i = 0; i != N; ++i)
    {
        scanf("%d", &W);
        T[i].weight = W;
        T[i].id = i;
    }
    int id, K;
    int cid;
    for (int i = 0; i != M; ++i)
    {
        scanf("%d %d", &id, &K);
        for (int j = 0; j != K; ++j)
        {
            scanf("%d", &cid);
            T[id].children.push_back(cid);
        }
    }

    vector<vector<int>> path;
    DFS(T, path, 0, 0, S);

    sort(path.rbegin(), path.rend());
    int output;
    for (const auto &eachPath : path)
    {
        output = 0;
        for (auto w : eachPath)
        {
            if (output++)
            {
                putchar(' ');
            }
            printf("%d", w);
        }
        putchar('\n');
    }
    return 0;
}
