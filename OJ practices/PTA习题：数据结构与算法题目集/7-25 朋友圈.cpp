/*
 @Date    : 2018-03-13 21:38:24
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/840
并查集注意对同根不必合并
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

static const int MAXN = 30001;
static int N, M;
static int root[MAXN];

int get_root(int p)
{
    if (root[p] < 0)
        return p;
    return get_root(root[p]);
}

void my_union(int c1, int c2)
{
    int r1 = get_root(c1);
    int r2 = get_root(c2);
    if (r1 == r2) return;
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

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    fill(root, root+N, -1);
    for (int i = 0; i != M; ++i)
    {
        int Mi, id, lastId;
        bool first = true;
        scanf("%d", &Mi);
        for (int j = 0; j != Mi; ++j)
        {
            scanf("%d", &id);
            if (first)
                first = false;
            else
                my_union(id, lastId);
            lastId = id;
        }
    }
    int max = 0;
    for (int num : root)
    {
        if (num < max)
            max = num;
    }
    printf("%d\n", -max);
    return 0;
}

