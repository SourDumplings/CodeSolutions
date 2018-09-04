/*
 @Date    : 2018-09-04 22:11:54
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805361586847744
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
const int MAXN = 1005;
int root[MAXN];
vector<int> peopleHobbies[MAXN], hobbyPeople[MAXN];

int get_root(int p)
{
    if (root[p] < 0)
        return p;
    else
        return get_root(root[p]);
}

void my_union(int p1, int p2)
{
    int r1 = get_root(p1), r2 = get_root(p2);
    if (r1 != r2)
    {
        if (root[r1] <= root[r2])
        {
            root[r1] += root[r2];
            root[r2] = root[p2] = r1;
        }
        else
        {
            root[r2] += root[r1];
            root[r1] = root[p1] = r2;
        }
    }
    return;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
    {
        root[i] = -1;
        int K;
        scanf("%d:", &K);
        for (int j = 0; j != K; ++j)
        {
            int h;
            scanf("%d", &h);
            peopleHobbies[i].push_back(h);
            hobbyPeople[h].push_back(i);
        }
    }
    for (int i = 0; i != N; ++i)
    {
        for (int h : peopleHobbies[i])
        {
            for (int p : hobbyPeople[h])
            {
                if (p != i)
                    my_union(i, p);
            }
        }
    }
    vector<int> res;
    for (int i = 0; i != N; ++i)
    {
        if (root[i] < 0)
            res.push_back(-root[i]);
    }
    sort(res.begin(), res.end());
    printf("%d\n", res.size());
    int output = 0;
    for (auto it = res.rbegin(); it != res.rend(); ++it)
    {
        if (output++)
            putchar(' ');
        printf("%d", *it);
    }
    putchar('\n');
    return 0;
}


