/*
 @Date    : 2018-03-17 10:14:20
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/897
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

static const int MAXN = 101;
static int root[MAXN];

struct Edge
{
    int v, w;
    int c;
    bool operator>(const Edge &r) const
    {
        return c > r.c;
    }
    Edge(int v_, int w_, int c_): v(v_), w(w_), c(c_) {}
};

static int N;

int find_root(int c)
{
    if (root[c] < 0)
    {
        return c;
    }
    return find_root(root[c]);
}

void my_union(int v, int w)
{
    int r1 = find_root(v);
    int r2 = find_root(w);
    if (r1 != r2)
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
    }
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    int M = N * (N - 1) / 2;
    priority_queue<Edge, vector<Edge>, greater<Edge>> Q;
    fill(root, root+N, -1);
    for (unsigned i = 0; i < M; ++i)
    {
        int v, w, c, status;
        scanf("%d %d %d %d", &v, &w, &c, &status);
        if (status == 1)
        {
            my_union(v, w);
        }
        else
        {
            Q.push(Edge(v, w, c));
        }
    }
    int cost = 0;
    while (!Q.empty())
    {
        Edge e = Q.top(); Q.pop();
        if (find_root(e.v) != find_root(e.w))
        {
            cost += e.c;
            my_union(e.v, e.w);
        }
    }
    printf("%d\n", cost);
    return 0;
}

