/*
 @Date    : 2018-09-07 18:28:11
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/16/problems/667
 */

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct TreeNode
{
    TreeNode *left = nullptr, *right = nullptr;
    int key;
};

int N;
const int MAXN = 35;
int in[MAXN], pre[MAXN];
int inI = 0, preI = 0;

TreeNode* build_tree(int preB, int preE, int inB, int inE)
{
    if (preB == preE)
        return nullptr;
    TreeNode *root = new TreeNode;
    root->key = pre[preB];
    if (preB + 1 == preE)
        return root;
    int leftE = inE - 1;
    for (int i = inB; i != inE; ++i)
    {
        if (in[i] == pre[preB])
        {
            leftE = i;
            break;
        }
    }
    root->left = build_tree(preB + 1, preB + 1 + leftE - inB, inB, leftE);
    root->right = build_tree(preB + 1 + leftE - inB, preE, leftE + 1, inE);
    return root;
}

int output = 0;

void post_order_traversal(TreeNode *T)
{
    if (T)
    {
        post_order_traversal(T->left);
        post_order_traversal(T->right);
        if (output++)
            putchar(' ');
        printf("%d", T->key);
    }
    return;
}

int main()
{
    scanf("%d", &N);
    TreeNode *T = nullptr;
    stack<int> S;
    for (int i = 0; i != 2 * N; ++i)
    {
        char order[10];
        int v;
        scanf("%s", order);
        if (order[1] == 'u')
        {
            scanf("%d", &v);
            S.push(v);
            pre[preI++] = v;
        }
        else
        {
            in[inI++] = S.top();
            S.pop();
        }
    }
    T = build_tree(0, N, 0, N);
    post_order_traversal(T);
    putchar('\n');
    return 0;
}

