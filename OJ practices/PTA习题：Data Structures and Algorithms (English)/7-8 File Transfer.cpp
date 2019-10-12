/*
 @Date    : 2018-09-07 19:28:57
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/16/problems/670
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
const int MAXN = 10005;
int root[MAXN];

int get_root(int x)
{
    if (root[x] < 0)
        return x;
    else
        return get_root(root[x]);
}

void my_union(int x1, int x2)
{
    int r1 = get_root(x1), r2 = get_root(x2);
    if (r1 != r2)
    {
        if (root[r1] <= root[r2])
        {
            root[r1] += root[r2];
            root[r2] = root[x2] = r1;
        }
        else
        {
            root[r2] += root[r1];
            root[r1] = root[x1] = r2;
        }
    }
    return;
}

int main()
{
    scanf("%d", &N);
    fill(root + 1, root + N + 1, -1);
    char order;
    int c1, c2;
    bool stop = false;
    while (!stop)
    {
        getchar();
        scanf("%c", &order);
        switch (order)
        {
        case 'I':
            {
                scanf("%d %d", &c1, &c2);
                my_union(c1, c2);
                break;
            }
        case 'C':
            {
                scanf("%d %d", &c1, &c2);
                if (get_root(c1) == get_root(c2))
                {
                    printf("yes\n");
                }
                else
                    printf("no\n");
                break;
            }
        case 'S':
            {
                stop = true;
                break;
            }
        }
    }
    int num = 0;
    for (int i = 1; i != N + 1; ++i)
    {
        if (root[i] < 0)
            ++num;
    }
    if (num == 1)
        printf("The network is connected.\n");
    else
        printf("There are %d components.\n", num);
    return 0;
}

