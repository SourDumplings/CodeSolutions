/*
 @Date    : 2018-09-05 23:10:38
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805346063728640
 */

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int K;
const int MAXN = 35;
int pre[MAXN];

struct TreeNode
{
    TreeNode() = default;
    TreeNode(int k, bool black_): key(k), black(black_) {}
    int key;
    bool black = true;
    int blackHeight = -1;
    TreeNode *left = nullptr, *right = nullptr;
};

TreeNode* build_tree(int b, int e)
{
    if (e == b)
        return nullptr;
    int k = pre[b];
    bool black = true;
    if (k < 0)
    {
        k = -k;
        black = false;
    }
    TreeNode *r = new TreeNode(k, black);
    if (b + 1 == e)
        return r;
    int leftE = e;
    for (int i = b + 1; i != e; ++i)
    {
        if (abs(pre[i]) >= k)
        {
            leftE = i;
            break;
        }
    }
    r->left = build_tree(b+1, leftE);
    r->right = build_tree(leftE, e);
    return r;
}

int get_black_height(TreeNode *r)
{
    int ret = 0;
    if (r)
    {
        if (r->blackHeight != -1)
            ret = r->blackHeight;
        else
        {
            int lH = get_black_height(r->left);
            int rH = get_black_height(r->right);
            if (lH != rH)
                ret = -2;
            else
            {
                if (r->black)
                {
                    ret = lH + 1;
                }
                else
                {
                    ret = lH;
                }
            }
        }
    }
    return ret;
}

bool post_order_traversal(TreeNode *T)
{
    bool ret = true;
    if (T)
    {
        bool ret1 = post_order_traversal(T->left);
        bool ret2 = post_order_traversal(T->right);
        T->blackHeight = get_black_height(T);
        if (T->blackHeight == -2)
            ret = false;
        else
        {
            if (!T->black && ((T->left && !T->left->black) || (T->right && !T->right->black)))
                ret = false;
            else
            {
                ret = ret1 && ret2;
            }
        }
    }
    return ret;
}

bool judge(TreeNode *T)
{
    bool ret = true;
    if (!T->black)
        ret = false;
    else
    {
        ret = post_order_traversal(T);
    }
    return ret;
}

int main()
{
    scanf("%d", &K);
    while (K--)
    {
        int N;
        scanf("%d", &N);
        TreeNode *T = nullptr;
        for (int i = 0; i != N; ++i)
            scanf("%d", &pre[i]);
        T = build_tree(0, N);
        if (judge(T))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}


