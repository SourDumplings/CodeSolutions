/*
 @Date    : 2018-03-15 09:26:56
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/859
无奇度结点的连通图存在欧拉回路，
奇度结点的个数为2的连通图存在半欧拉回路
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

static const int MAXN = 1001;
static int N, M;
static int degree[MAXN];
static int root[MAXN];

int get_root(int c)
{
    if (root[c] < 0)
        return c;
    return get_root(root[c]);
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
    fill(degree, degree+MAXN, 0);
    fill(root, root+MAXN, -1);
    for (int i = 0; i != M; ++i)
    {
        int v, w;
        scanf("%d %d", &v, &w);
        ++degree[v-1];
        ++degree[w-1];
        my_union(v-1, w-1);
    }
    int rootNum = count_if(root, root+N, [] (const int &i) { return i < 0; });
    if (rootNum == 1)
    {
        int oddDegreeNum = count_if(degree, degree+N, [] (const int &d) { return d & 1; });
        if (oddDegreeNum == 0)
            printf("1\n");
        else
            printf("0\n");
    }
    else
        printf("0\n");
    return 0;
}

