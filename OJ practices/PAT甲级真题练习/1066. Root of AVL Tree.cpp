/*
 @Date    : 2018-02-06 10:44:11
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1066
 */

#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct TreeNode *Tree;
struct TreeNode
{
    int data;
    int height = 0;
    Tree left = nullptr, right = nullptr;
};

int get_height(Tree T)
{
    int hl, hr, maxh;
    if (T)
    {
        hl = get_height(T->left);
        hr = get_height(T->right);
        maxh = max(hl, hr);
        return maxh + 1;
    }
    else
        return 0;
}

Tree single_left_rotation(Tree A)
{
    Tree B = A->left;
    A->left = B->right;
    B->right = A;
    A->height = max(get_height(A->left), get_height(A->right)) + 1;
    B->height = max(get_height(B->left), A->height) + 1;
    return B;
}

Tree single_right_rotation(Tree A)
{
    Tree B = A->right;
    A->right = B->left;
    B->left = A;
    A->height = max(get_height(A->left), get_height(A->right)) + 1;
    B->height = max(get_height(B->right), A->height) + 1;
    return B;
}

Tree double_left_right_rotation(Tree A)
{
    A->left = single_right_rotation(A->left);
    return single_left_rotation(A);
}

Tree double_right_left_rotation(Tree A)
{
    A->right = single_left_rotation(A->right);
    return single_right_rotation(A);
}

Tree insert(Tree T, int item)
{
    if (!T)
    {
        T = new TreeNode;
        T->data = item;
    }
    else if (item < T->data)
    {
        T->left = insert(T->left, item);
        if (get_height(T->left) - get_height(T->right) == 2)
        {
            if (item < T->left->data)
                T = single_left_rotation(T);
            else
                T = double_left_right_rotation(T);
        }
    }
    else if (item > T->data)
    {
        T->right = insert(T->right, item);
        if (get_height(T->left) - get_height(T->right) == -2)
        {
            if ( item > T->right->data)
                T = single_right_rotation(T);
            else
                T = double_right_left_rotation(T);
        }
    }
    T->height = max(get_height(T->left), get_height(T->right));
    return T;
}

int main(int argc, char const *argv[])
{
    Tree T = nullptr;
    int n;
    scanf("%d", &n);
    int temp;
    while (n--)
    {
        scanf("%d", &temp);
        T = insert(T, temp);
        // printf("%d\n", temp);
    }
    printf("%d\n", T->data);
    return 0;
}
