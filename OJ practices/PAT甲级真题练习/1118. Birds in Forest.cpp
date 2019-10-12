/*
 @Date    : 2018-03-01 14:41:45
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1118
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory>
#include <queue>
#include <set>

using namespace std;

static const int MAXB = 10001;
static bool birds[MAXB];
static bool checked[MAXB];
struct Bird
{
    vector<int> treeMates;
    shared_ptr<set<int>> tree;
};
static Bird G[MAXB];

void read_picture()
{
    int K;
    scanf("%d", &K);
    int b, lastb = -1;
    while (K--)
    {
        scanf("%d", &b);
        if (birds[b] == false)
            birds[b] = true;
        if (lastb == - 1)
            lastb = b;
        else
        {
            G[b].treeMates.push_back(lastb);
            G[lastb].treeMates.push_back(b);
        }
    }
    return;
}

void BFS(int s)
{
    queue<int> Q;
    Q.push(s);
    auto tree = make_shared<set<int>>(set<int>());
    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        tree->insert(v);
        G[v].tree = tree;
        checked[v] = true;
        for (auto treeMate : G[v].treeMates)
        {
            if (!checked[treeMate])
                Q.push(treeMate);
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    fill(birds, birds+MAXB, false);
    while (N--)
        read_picture();
    int birdsNum = count(birds, birds+MAXB, true);
    fill(checked, checked+MAXB, false);
    int treeNum = 0;
    for (int i = 1; i != birdsNum + 1; ++i)
    {
        if (!checked[i])
        {
            ++treeNum;
            BFS(i);
        }
    }
    printf("%d %d\n", treeNum, birdsNum);
    int Q;
    scanf("%d", &Q);
    int b1, b2;
    while (Q--)
    {
        scanf("%d %d", &b1, &b2);
        if (G[b1].tree->find(b2) != G[b1].tree->end())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
