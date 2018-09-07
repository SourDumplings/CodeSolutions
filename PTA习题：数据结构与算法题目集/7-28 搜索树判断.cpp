/*
 @Date    : 2018-03-14 10:46:56
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/843
注意所谓的镜像二叉搜索树是每个子树都是镜像二叉搜索树，不能混搭
注意默认左子树的长度应该是所有子节点的个数
 */

#include <iostream>
#include <cstdio>
#include <memory>

using namespace std;

struct TNode
{
    int data;
    shared_ptr<TNode> left = nullptr, right = nullptr;
};

static const int MAXN = 1001;
static int pre[MAXN];
static bool isBST = true, isRBST = true;

shared_ptr<TNode> build_BSTtree(shared_ptr<TNode> T, int preB, int preE)
{
    if (preB == preE || !isBST) return T;
    int root = pre[preB];
    T = make_shared<TNode>();
    T->data = root;
    if (preB == preE - 1) return T;
    int lLength = preE - preB - 1;
    for (int i = preB + 1; i != preE; ++i)
    {
        if (pre[i] >= root)
        {
            lLength = i - preB - 1;
            break;
        }
    }
    for (int i = preB + 1 + lLength; i != preE; ++i)
    {
        if (pre[i] < root)
        {
            isBST = false;
            // printf("this is not BST\n");
            break;
        }
    }
    T->left = build_BSTtree(T->left, preB+1, preB+1+lLength);
    T->right = build_BSTtree(T->right, preB+1+lLength, preE);
    return T;
}

shared_ptr<TNode> build_RBSTtree(shared_ptr<TNode> T, int preB, int preE)
{
    if (preB == preE || !isRBST) return T;
    int root = pre[preB];
    T = make_shared<TNode>();
    T->data = root;
    if (preB == preE - 1) return T;
    int lLength = preE - preB - 1;
    for (int i = preB + 1; i != preE; ++i)
    {
        if (pre[i] < root)
        {
            lLength = i - preB - 1;
            break;
        }
    }
    for (int i = preB + 1 + lLength; i != preE; ++i)
    {
        if (pre[i] >= root)
        {
            // printf("%d cannot in %d's right substree\n", pre[i], root);
            isRBST = false;
            break;
        }
    }
    T->left = build_RBSTtree(T->left, preB+1, preB+1+lLength);
    T->right = build_RBSTtree(T->right, preB+1+lLength, preE);
    return T;
}

static int output = 0;

void post_traversal(shared_ptr<TNode> T)
{
    if (T)
    {
        post_traversal(T->left);
        post_traversal(T->right);
        if (output++) putchar(' ');
        printf("%d", T->data);
    }
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    for (int i = 0; i != N; ++i)
        scanf("%d", &pre[i]);
    shared_ptr<TNode> T = nullptr;
    T = build_BSTtree(T, 0, N);
    if (!isBST)
    {
        T = nullptr;
        T = build_RBSTtree(T, 0, N);
    }
    if (isBST || isRBST)
    {
        printf("YES\n");
        post_traversal(T);
        putchar('\n');
    }
    else
        printf("NO\n");
    return 0;
}

