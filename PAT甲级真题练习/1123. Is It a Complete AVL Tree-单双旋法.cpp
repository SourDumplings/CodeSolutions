/*
 @Date    : 2018-03-03 14:47:43
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1123
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <memory>
#include <queue>

using namespace std;

struct AVLTNode
{
    shared_ptr<AVLTNode> left = nullptr, right = nullptr;
    int key;
};

shared_ptr<AVLTNode> signle_left_rotation(shared_ptr<AVLTNode> T)
{
    auto root = T->left;
    T->left = root->right;
    root->right = T;
    return root;
}

shared_ptr<AVLTNode> single_right_rotation(shared_ptr<AVLTNode> T)
{
    auto root = T->right;
    T->right = root->left;
    root->left = T;
    return root;
}

shared_ptr<AVLTNode> double_left_right_rotation(shared_ptr<AVLTNode> T)
{
    T->left = single_right_rotation(T->left);
    return signle_left_rotation(T);
}

shared_ptr<AVLTNode> double_right_left_rotation(shared_ptr<AVLTNode> T)
{
    T->right = signle_left_rotation(T->right);
    return single_right_rotation(T);
}

int get_height(shared_ptr<AVLTNode> T)
{
    if (!T) return 0;
    int hl = get_height(T->left);
    int hr = get_height(T->right);
    return max(hl, hr) + 1;
}

shared_ptr<AVLTNode> insert_node(shared_ptr<AVLTNode> T, int k)
{
    if (!T)
    {
        T = make_shared<AVLTNode>();
        T->key = k;
    }
    else if (k < T->key)
    {
        T->left = insert_node(T->left, k);
        if (get_height(T->left) - get_height(T->right) == 2)
        {
            if (k < T->left->key)
                T = signle_left_rotation(T);
            else
                T = double_left_right_rotation(T);
        }
    }
    else if (T->key < k)
    {
        T->right = insert_node(T->right, k);
        if (get_height(T->right) - get_height(T->left) == 2)
        {
            if (T->right->key < k)
                T = single_right_rotation(T);
            else
                T = double_right_left_rotation(T);
        }
    }
    return T;
}

static vector<shared_ptr<AVLTNode>> nodeData;
static bool isComplete = true;

void level_order_traversal(shared_ptr<AVLTNode> T)
{
    if (!T) return;
    queue<shared_ptr<AVLTNode>> Q;
    Q.push(T);
    bool noMoreHeight2 = false;
    while (!Q.empty())
    {
        auto t = Q.front();
        Q.pop();
        nodeData.push_back(t);
        if (t->left || t->right)
        {
            if (noMoreHeight2) isComplete = false;
            if (t->left)
            {
                Q.push(t->left);
                if (!t->right) noMoreHeight2 = true;
            }
            if (t->right)
            {
                Q.push(t->right);
                if (!t->left) isComplete = false;
            }
        }
        else noMoreHeight2 = true;
    }
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    shared_ptr<AVLTNode> T = nullptr;
    int k;
    for (int i = 0; i != N; ++i)
    {
        scanf("%d", &k);
        T = insert_node(T, k);
    }
    level_order_traversal(T);
    int output = 0;
    for (auto pN : nodeData)
    {
        if (output++) putchar(' ');
        printf("%d", pN->key);
    }
    putchar('\n');
    if (isComplete) printf("YES\n");
    else printf("NO\n");
    return 0;
}
