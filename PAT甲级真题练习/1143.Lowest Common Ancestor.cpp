/*
 @Date    : 2018-08-04 21:46:12
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805343727501312
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct BST
{
    int key;
    BST *left = nullptr, *right = nullptr;
};

const int MAXN = 10005;
int data[MAXN];
int m, n;
set<int> nodes;

BST* build_tree(int b, int e)
{
    if (e == b)
    {
        return nullptr;
    }

    BST *r = new BST;
    r->key = data[b];
    nodes.insert(r->key);
    if (b + 1 == e)
    {
        return r;
    }

    int right = e;
    for (int i = b + 1; i < e; ++i)
    {
        if (data[i] >= r->key)
        {
            right = i;
            break;
        }
    }

    r->left = build_tree(b+1, right);
    r->right = build_tree(right, e);
    return r;
}

void search_LCA(BST *r, int u, int v)
{
    if (r->key == u)
    {
        printf("%d is an ancestor of %d.\n", u, v);
    }
    else if (r->key == v)
    {
        printf("%d is an ancestor of %d.\n", v, u);
    }
    else
    {
        if ((r->key < u && r->key > v) || (r->key < v && r->key > u))
        {
            printf("LCA of %u and %d is %d.\n", u, v, r->key);
        }
        else if (r->key < v && r->key < u)
        {
            return search_LCA(r->right, u, v);
        }
        else
            return search_LCA(r->left, u, v);
    }
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &data[i]);
    }

    BST *T = build_tree(0, n);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        if (nodes.find(u) == nodes.end())
        {
            if (nodes.find(v) == nodes.end())
            {
                printf("ERROR: %d and %d are not found.\n", u, v);
            }
            else
            {
                printf("ERROR: %d is not found.\n", u);
            }
        }
        else if (nodes.find(v) == nodes.end())
        {
            printf("ERROR: %d is not found.\n", v);
        }
        else
        {
            search_LCA(T, u, v);
        }
    }
    return 0;
}

