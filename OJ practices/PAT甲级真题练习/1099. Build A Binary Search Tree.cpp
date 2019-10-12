/*
 @Date    : 2018-09-03 22:54:19
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805367987355648
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N;
const int MAXN = 101;

struct TreeNode
{
    int key;
    int left = -1, right = -1;
};

TreeNode T[MAXN];
int keys[MAXN];
int n = 0;

void in_order_traversal(int f)
{
    if (f != -1)
    {
        in_order_traversal(T[f].left);
        T[f].key = keys[n++];
        in_order_traversal(T[f].right);
    }
    return;
}

int output = 0;

void level_order_traversal(int r)
{
    queue<int> q;
    q.push(r);
    while (!q.empty())
    {
        int f = q.front(); q.pop();
        if (output++)
            putchar(' ');
        printf("%d", T[f].key);
        if (T[f].left != -1)
            q.push(T[f].left);
        if (T[f].right != -1)
            q.push(T[f].right);
    }
    putchar('\n');
    return;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
    {
        scanf("%d %d", &T[i].left, &T[i].right);
    }
    for (int i = 0; i != N; ++i)
        scanf("%d", &keys[i]);
    sort(keys, keys+N);
    in_order_traversal(0);
    level_order_traversal(0);
    return 0;
}

