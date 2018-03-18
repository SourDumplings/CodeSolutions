/*
 @Date    : 2018-03-07 08:39:51
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1135
思路：
先根据先序遍历序列建BST树，如果建树的过程中发现不是BST则直接返回；
在建树的同时记录每个结点的黑高度，如果左右子树黑高度不等则表示条件4不满足
然后层序遍历判断条件4
 */

#include <iostream>
#include <cstdio>
#include <memory>
#include <cmath>
#include <queue>

using namespace std;

struct TNode
{
    int data;
    shared_ptr<TNode> left = nullptr, right = nullptr;
    int blackH = 0;
};

static bool isBST = true;
static bool isRB = true;

shared_ptr<TNode> build_tree(shared_ptr<TNode> T, int pre[], int preB, int preE)
{
    if (preB == preE || !isRB || !isBST) return T;
    int root = pre[preB];
    T = make_shared<TNode>();
    T->data = root;
    if (preB + 1 == preE)
    {
        if (T->data > 0) T->blackH = 1;
        return T;
    }
    int lLength = preE - preB - 1;
    for (int i = preB + 1; i != preE; ++i)
    {
        if (lLength == preE - preB - 1 && abs(pre[i]) > abs(root))
            lLength = i - preB - 1;
        if (lLength != preE - preB - 1)
        {
            if (abs(pre[i]) <= abs(root))
            {
                isBST = false;
                return T;
            }
        }
    }
    T->left = build_tree(T->left, pre, preB + 1, preB + 1 + lLength);
    T->right = build_tree(T->right, pre, preB + 1 + lLength, preE);
    int hl = T->left ? T->left->blackH : 0;
    int hr = T->right ? T->right->blackH : 0;
    if (hl != hr) isRB = false;
    else T->blackH = T->data > 0 ? hl + 1 : hl;
    return T;
}

bool judge(shared_ptr<TNode> T)
{
    if (!isBST || !isRB || T->data < 0) return false;
    queue<shared_ptr<TNode>> Q;
    Q.push(T);
    while (!Q.empty())
    {
        auto node = Q.front(); Q.pop();
        if (node->left)
        {
            if (node->data < 0 && node->left->data < 0) return false;
            Q.push(node->left);
        }
        if (node->right)
        {
            if (node->data < 0 && node->right->data < 0) return false;
            Q.push(node->right);
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int K, N;
    scanf("%d", &K);
    while (K--)
    {
        scanf("%d", &N);
        int pre[N];
        for (int i = 0; i != N; ++i)
            scanf("%d", &pre[i]);
        shared_ptr<TNode> T = nullptr;
        isBST = isRB = true;
        T = build_tree(T, pre, 0, N);
        if (judge(T)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

