/*
 @Date    : 2018-03-17 19:24:54
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1034
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Person
{
    char name[4];
    int w = 0;
};

static const int MAXN = 26 * 26 * 26 + 10;

int my_hash(char name[])
{
    return (name[0] - 'A') * 26 * 26 + (name[1] - 'A') * 26 + (name[2] - 'A');
}

static int N, K;
static Person data[MAXN];
static int root[MAXN];
static int head[MAXN];

int find_root(int c)
{
    if (root[c] < 0)
    {
        return c;
    }
    return find_root(root[c]);
}

static int total_w[MAXN];

void my_union(int h1, int h2, int w)
{
    int r1 = find_root(h1), r2 = find_root(h2);
    if (data[h1].w > data[head[r1]].w)
    {
        head[r1] = h1;
    }
    if (data[h2].w > data[head[r2]].w)
    {
        head[r2] = h2;
    }
    total_w[r1] += w; total_w[r2] += w;
    if (r1 != r2)
    {
        int headID = (data[head[r1]].w > data[head[r2]].w ?
            head[r1] : head[r2]);
        if (root[r1] <= root[r2])
        {
            root[r1] += root[r2];
            root[r2] = r1;
            total_w[r1] += total_w[r2];
            head[r1] = headID;
        }
        else
        {
            root[r2] += root[r1];
            root[r1] = r2;
            total_w[r2] += total_w[r1];
            head[r2] = headID;
        }
    }
    return;
}

void re_hash(char name[], int h)
{
    name[2] = h % 26 + 'A';
    h /= 26;
    name[1] = h % 26 + 'A';
    h /= 26;
    name[0] = h + 'A';
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &K);
    fill(root, root+MAXN, -1);
    fill(total_w, total_w+MAXN, 0);
    for (unsigned i = 0; i < MAXN; ++i)
    {
        head[i] = i;
    }
    for (unsigned i = 0; i < N; ++i)
    {
        char name1[4], name2[4];
        int w;
        getchar();
        scanf("%s %s %d", name1, name2, &w);
        int h1 = my_hash(name1), h2 = my_hash(name2);
        data[h1].w += w; data[h2].w += w;
        my_union(h1, h2, w);
    }
    vector<pair<int, int>> gangs;
    for (unsigned i = 0; i < MAXN; ++i)
    {
        if (root[i] < -2 && total_w[i] / 2 > K)
        {
            gangs.push_back(make_pair(head[i], -root[i]));
        }
    }
    printf("%d\n", gangs.size());
    for (auto &g : gangs)
    {
        char name[4];
        re_hash(name, g.first);
        printf("%s %d\n", name, g.second);
    }
    return 0;
}

