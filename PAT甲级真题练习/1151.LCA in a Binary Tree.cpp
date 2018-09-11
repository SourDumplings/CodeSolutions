/*
 @Date    : 2018-09-11 09:07:02
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/1038430130011897856
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
    TreeNode *left = nullptr, *right = nullptr;
    int key;
    TreeNode *father = nullptr;
    int level;
};

int M, N;
const int MAXN = 10005;
int pre[MAXN], in[MAXN];

TreeNode* build_tree(int preB, int preE, int inB, int inE)
{
    if (preB == preE)
        return nullptr;
    TreeNode *r = new TreeNode;
    r->key = pre[preB];
    if (preB + 1 == preE)
        return r;
    int leftE;
    for (int i = inB; i != inE; ++i)
    {
        if (in[i] == pre[preB])
        {
            leftE = i;
            break;
        }
    }
    r->left = build_tree(preB + 1, preB + 1 + leftE - inB, inB, leftE);
    if (r->left)
        r->left->father = r;
    r->right = build_tree(preB + 1 + leftE - inB, preE, leftE + 1, inE);
    if (r->right)
        r->right->father = r;
    return r;
}

TreeNode* search(TreeNode *T, int c, int level)
{
    if (!T)
        return nullptr;
    if (T->key == c)
    {
        T->level = level;
        return T;
    }
    else
    {
        TreeNode *lRes = search(T->left, c, level + 1);
        if (lRes)
            return lRes;
        else
        {
            TreeNode *rRes = search(T->right, c, level + 1);
            return rRes;
        }
    }
}

int main()
{
    scanf("%d %d", &M, &N);
    for (int i = 0; i != N; ++i)
        scanf("%d", &in[i]);

    for (int i = 0; i != N; ++i)
        scanf("%d", &pre[i]);

    TreeNode *T = nullptr;
    T = build_tree(0, N, 0, N);
    while (M--)
    {
        int c1, c2;
        scanf("%d %d", &c1, &c2);
        TreeNode *r1 = search(T, c1, 1), *r2 = search(T, c2, 1);
        if (r1 && r2)
        {
            int res = -1;
            int tempC1 = c1, tempC2 = c2;
            if (r1->level < r2->level)
            {
                swap(r1, r2);
                swap(tempC1, tempC2);
            }
            int dLevel = r1->level - r2->level;
            for (int i = 0; i != dLevel; ++i)
                r1 = r1->father;
            while (r1 != r2)
            {
                r1 = r1->father;
                r2 = r2->father;
            }
            res = r1->key;
            if (res == tempC1)
                printf("%d is an ancestor of %d.\n", tempC1, tempC2);
            else if (res == tempC2)
                printf("%d is an ancestor of %d.\n", tempC2, tempC1);
            else
                printf("LCA of %d and %d is %d.\n", c1, c2, res);
        }
        else if (r2)
        {
            printf("ERROR: %d is not found.\n", c1);
        }
        else if (r1)
        {
            printf("ERROR: %d is not found.\n", c2);
        }
        else
        {
            printf("ERROR: %d and %d are not found.\n", c1, c2);
        }
    }
    return 0;
}
