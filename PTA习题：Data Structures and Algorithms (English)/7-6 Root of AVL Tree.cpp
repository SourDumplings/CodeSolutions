/*
 @Date    : 2018-09-07 19:05:45
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/16/problems/668
 */

#include <iostream>
#include <cstdio>

using namespace std;

struct TreeNode
{
    TreeNode *left = nullptr, *right = nullptr;
    int key;
};

int N;

int get_height(TreeNode *T)
{
    int ret = 0;
    if (T)
    {
        int lH = get_height(T->left), rH = get_height(T->right);
        ret = lH > rH ? lH + 1 : rH + 1;
    }
    return ret;
}

TreeNode* single_left_rotate(TreeNode *A)
{
    TreeNode *B = A->left;
    A->left = B->right;
    B->right = A;
    return B;
}

TreeNode* single_right_rotate(TreeNode *A)
{
    TreeNode *B = A->right;
    A->right = B->left;
    B->left = A;
    return B;
}

TreeNode* double_left_right_rotate(TreeNode *A)
{
    A->left = single_right_rotate(A->left);
    return single_left_rotate(A);
}

TreeNode* double_right_left_rotate(TreeNode *A)
{
    A->right = single_left_rotate(A->right);
    return single_right_rotate(A);
}

TreeNode* insert(TreeNode *T, int x)
{
    if (!T)
    {
        T = new TreeNode;
        T->key = x;
    }
    else
    {
        if (x < T->key)
        {
            T->left = insert(T->left, x);
            if (get_height(T->left) - get_height(T->right) == 2)
            {
                if (x < T->left->key)
                {
                    T = single_left_rotate(T);
                }
                else
                {
                    T = double_left_right_rotate(T);
                }
            }
        }
        else
        {
            T->right = insert(T->right, x);
            if (get_height(T->right) - get_height(T->left) == 2)
            {
                if (x > T->right->key)
                {
                    T = single_right_rotate(T);
                }
                else
                {
                    T = double_right_left_rotate(T);
                }
            }
        }
    }
    return T;
}

int main()
{
    scanf("%d", &N);
    TreeNode *T = nullptr;
    for (int i = 0; i != N; ++i)
    {
        int x;
        scanf("%d", &x);
        T = insert(T, x);
    }
    printf("%d\n", T->key);
    return 0;
}

