/*
 @Date    : 2018-03-18 09:45:58
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/6103
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory>

using namespace std;

struct AVLTNode
{
    int data;
    shared_ptr<AVLTNode> left = nullptr, right = nullptr;
};

int get_height(shared_ptr<AVLTNode> T)
{
    if (!T)
    {
        return 0;
    }
    return max(get_height(T->left), get_height(T->right)) + 1;
}

shared_ptr<AVLTNode> single_left_rotation(shared_ptr<AVLTNode> A)
{
    shared_ptr<AVLTNode> B = A->left, C = B->left;
    A->left = B->right;
    B->right = A;
    return B;
}

shared_ptr<AVLTNode> single_right_rotation(shared_ptr<AVLTNode> A)
{
    shared_ptr<AVLTNode> B = A->right, C = B->right;
    A->right = B->left;
    B->left = A;
    return B;
}

shared_ptr<AVLTNode> double_left_right_rotation(shared_ptr<AVLTNode> A)
{
    shared_ptr<AVLTNode> B = A->left, C = B->right;
    A->left = single_right_rotation(B);
    return single_left_rotation(A);
}

shared_ptr<AVLTNode> double_right_left_rotation(shared_ptr<AVLTNode> A)
{
    shared_ptr<AVLTNode> B = A->right, C = B->left;
    A->right = single_left_rotation(B);
    return single_right_rotation(A);
}

shared_ptr<AVLTNode> my_insert(shared_ptr<AVLTNode> T, int num)
{
    if (!T)
    {
        T = make_shared<AVLTNode>();
        T->data = num;
        return T;
    }
    if (num < T->data)
    {
        T->left = my_insert(T->left, num);
        if (get_height(T->left) - get_height(T->right) == 2)
        {
            if (num < T->left->data)
            {
                T = single_left_rotation(T);
            }
            else
                T = double_left_right_rotation(T);
        }
    }
    else if (num > T->data)
    {
        T->right = my_insert(T->right, num);
        if (get_height(T->right) - get_height(T->left) == 2)
        {
            if (num < T->right->data)
            {
                T = double_right_left_rotation(T);
            }
            else
                T = single_right_rotation(T);
        }
    }
    return T;
}

int main(int argc, char const *argv[])
{
    shared_ptr<AVLTNode> T = nullptr;
    int N;
    scanf("%d", &N);
    for (unsigned i = 0; i < N; ++i)
    {
        int num;
        scanf("%d", &num);
        T = my_insert(T, num);
    }
    printf("%d\n", T->data);
    return 0;
}

