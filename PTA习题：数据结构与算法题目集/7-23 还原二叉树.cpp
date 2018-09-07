/*
 @Date    : 2018-03-13 20:40:38
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/838
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory>

using namespace std;

struct TNode
{
    shared_ptr<TNode> left = nullptr, right = nullptr;
};

shared_ptr<TNode> build_tree(shared_ptr<TNode> &T, char pre[], int preB, int preE,
                             char in[], int inB, int inE)
{
    if (preB == preE) return T;
    T = make_shared<TNode>();
    if (preB == preE - 1) return T;
    char root = pre[preB];
    int lLength;
    for (int i = inB; i != inE; ++i)
    {
        if (in[i] == root)
        {
            lLength = i - inB;
            break;
        }
    }
    T->left = build_tree(T->left, pre, preB + 1, preB + lLength + 1, in, inB, inB + lLength);
    T->right = build_tree(T->right, pre, preB + lLength + 1, preE, in, inB + lLength + 1, inE);
    return T;
}

int get_height(shared_ptr<TNode> T)
{
    if (!T) return 0;
    int hl = get_height(T->left);
    int hr = get_height(T->right);
    return max(hr, hl) + 1;
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    char pre[N], in[N];
    for (int i = 0; i != N; ++i) cin >> pre[i];
    for (int i = 0; i != N; ++i) cin >> in[i];
    shared_ptr<TNode> T = nullptr;
    T = build_tree(T, pre, 0, N, in, 0, N);
    printf("%d\n", get_height(T));
    return 0;
}

