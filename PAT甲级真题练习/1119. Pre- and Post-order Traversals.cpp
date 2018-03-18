/*
 @Date    : 2018-03-01 15:27:07
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1119
 */

#include <iostream>
#include <cstdio>
#include <memory>

using namespace std;

static bool uniqueTree = true;

struct TNode
{
    int key;
    shared_ptr<TNode> left = nullptr, right = nullptr;
};

shared_ptr<TNode> solve(shared_ptr<TNode> &T, int pre[], int preB, int preE,
    int post[], int postB, int postE)
{
    if (preE == preB) return T;
    T = make_shared<TNode>();
    int root = pre[preB];
    T->key = root;
    if (preE == preB + 1) return T;
    int subRoot = pre[preB+1];
    int subRootInPostPos;
    for (int i = postB; i != postE; ++i)
    {
        if (post[i] == subRoot)
        {
            subRootInPostPos = i;
            break;
        }
    }
    if (subRootInPostPos == postE - 2) uniqueTree = false;
    int lLength = subRootInPostPos - postB + 1;
    T->left = solve(T->left, pre, preB+1, preB+1+lLength, post,
        postB, postB+lLength);
    T->right = solve(T->right, pre, preB+1+lLength, preE, post,
        postB+lLength, postE-1);
    return T;
}

static int output = 0;
void in_order_traversal(const shared_ptr<TNode> &T)
{
    if (T != nullptr)
    {
        in_order_traversal(T->left);
        if (output++) putchar(' ');
        printf("%d", T->key);
        in_order_traversal(T->right);
    }
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    int pre[N], post[N];
    for (int i = 0; i != N; ++i) scanf("%d", &pre[i]);
    for (int i = 0; i != N; ++i) scanf("%d", &post[i]);
    shared_ptr<TNode> T = nullptr;
    T = solve(T, pre, 0, N, post, 0, N);
    if (uniqueTree) printf("Yes\n");
    else printf("No\n");
    in_order_traversal(T);
    putchar('\n');
    return 0;
}
