/*
 @Date    : 2018-03-11 10:45:04
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/712
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

shared_ptr<TNode> insert(shared_ptr<TNode> &T, int x)
{
    if (T == nullptr)
    {
        T = make_shared<TNode>();
        T->data = x;
    }
    else if (x < T->data)
        T->left = insert(T->left, x);
    else if (T->data < x)
        T->right = insert(T->right, x);
    return T;
}

bool cmp(const shared_ptr<TNode> To, const shared_ptr<TNode> T)
{
    if (!T && !To)
        return true;
    else if ((To && !T) || (!To && T))
        return false;
    else
        return cmp(To->left, T->left) && cmp(To->right, T->right);
}

int main(int argc, char const *argv[])
{
    while (true)
    {
        int N;
        scanf("%d", &N);
        if (N == 0) break;
        int L;
        scanf("%d", &L);
        shared_ptr<TNode> To = nullptr;
        for (int i = 0; i != N; ++i)
        {
            int x;
            scanf("%d", &x);
            To = insert(To, x);
        }
        for (int i = 0; i != L; ++i)
        {
            shared_ptr<TNode> T = nullptr;
            int x;
            for (int j = 0; j != N; ++j)
            {
                scanf("%d", &x);
                T = insert(T, x);
            }
            if (cmp(To, T))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}

