/*
 @Date    : 2018-09-07 18:03:09
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/16/problems/666
 */

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int N;
const int MAXN = 15;

struct TreeNode
{
    int left = -1, right = -1;
    int father = -1;
};

TreeNode T[MAXN];

void level_order_traversal(int r)
{
    queue<int> q;
    q.push(r);
    int output = 0;
    while (!q.empty())
    {
        int f = q.front(); q.pop();
        if (T[f].left == -1 && T[f].right == -1)
        {
            if (output++)
                putchar(' ');
            printf("%d", f);
        }
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
        char l, r;
        getchar();
        scanf("%c %c", &l, &r);
        if (l != '-')
        {
            T[i].left = l - '0';
            T[l - '0'].father = i;
        }
        if (r != '-')
        {
            T[i].right = r - '0';
            T[r - '0'].father = i;
        }
    }
    int root;
    for (int i = 0; i != N; ++i)
    {
        if (T[i].father == -1)
        {
            root = i;
            break;
        }
    }
    level_order_traversal(root);
    return 0;
}


