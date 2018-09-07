/*
 @Date    : 2018-03-12 10:42:08
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/718
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

static int N, M;

struct Edge
{
    int v, w;
    int c;
    Edge(int v_, int w_, int c_): v(v_), w(w_), c(c_) {}
};

bool operator<(const Edge &e1, const Edge &e2)
{
    return e1.c > e2.c;
}

static const int MAXN = 1001;
static priority_queue<Edge> E;
static int minC = 0;
static int root[MAXN];

int get_root(int child)
{
    if (root[child] < 0)
        return child;
    return get_root(root[child]);
}

void my_union(int r1, int r2)
{
    if (root[r1] < root[r2])
    {
        root[r1] += root[r2];
        root[r2] = r1;
    }
    else
    {
        root[r2] += root[r1];
        root[r1] = r2;
    }
    return;
}

bool Kruskal()
{
    fill(root, root+N, -1);
    vector<Edge> mst;
    while (!E.empty() && mst.size() < N - 1)
    {
        Edge e = E.top(); E.pop();
        int r1 = get_root(e.v), r2 = get_root(e.w);
        if (r1 != r2)
        {
            mst.push_back(e);
            my_union(r1, r2);
            minC += e.c;
        }
    }
    if (mst.size() == N - 1)
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i != M; ++i)
    {
        int v, w, c;
        scanf("%d %d %d", &v, &w, &c);
        E.push(Edge(v - 1, w - 1, c));
    }
    bool ok = Kruskal();
    if (ok)
        printf("%d\n", minC);
    else
        printf("-1\n");
    return 0;
}

