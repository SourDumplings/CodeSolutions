/*
 @Date    : 2018-03-02 10:27:41
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
#include <cmath>
#include <queue>

using namespace std;

struct AVLTNode
{
    shared_ptr<AVLTNode> parent = nullptr, left = nullptr, right = nullptr;
    int height = 1;
    int key;
};

bool is_balance(shared_ptr<AVLTNode> &T)
{
    int hl = T->left ? T->left->height : 0;
    int hr = T->right ? T->right->height : 0;
    if (abs(hl - hr) == 2)
        return false;
    return true;
}

void update_height(shared_ptr<AVLTNode> T)
{
    int hl = T->left ? T->left->height : 0;
    int hr = T->right ? T->right->height : 0;
    T->height = max(hl, hr) + 1;
    return;
}

shared_ptr<AVLTNode> taller_child(shared_ptr<AVLTNode> T)
{
    int hl = T->left ? T->left->height : 0;
    int hr = T->right ? T->right->height : 0;
    auto c = hl > hr ? T->left : T->right;
    return c;
}

shared_ptr<AVLTNode>& from_parent_to(shared_ptr<AVLTNode> g)
{
    auto pg = g->parent;
    if (g == pg->left)
        return pg->left;
    else return pg->right;
}

shared_ptr<AVLTNode> connect34(shared_ptr<AVLTNode> a, shared_ptr<AVLTNode> b,
    shared_ptr<AVLTNode> c, shared_ptr<AVLTNode> T0, shared_ptr<AVLTNode> T1,
    shared_ptr<AVLTNode> T2, shared_ptr<AVLTNode> T3)
{
    a->left = T0; if (T0) T0->parent = a;
    a->right = T1; if (T1) T1->parent = a; update_height(a);
    c->left = T2; if (T2) T2->parent = c;
    c->right = T3; if (T3) T3->parent = c; update_height(c);
    a->parent = c->parent = b;
    b->left = a; b->right = c; update_height(b);
    return b;
}

shared_ptr<AVLTNode> rotateAt(shared_ptr<AVLTNode> T)
{
    auto p = T->parent;
    auto g = p->parent;
    // printf("T->key = %d, p->key = %d, g->key = %d\n", T->key, p->key, g->key);
    if (p == g->left)
    {
        if (T == p->left)
        {
            p->parent = g->parent;
            return connect34(T, p, g, T->left, T->right, p->right, g->right);
        }
        else
        {
            T->parent = g->parent;
            return connect34(p, T, g, p->left, T->left, T->right, g->right);
        }
    }
    else
    {
        if (T == p->left)
        {
            T->parent = g->parent;
            return connect34(g, T, p, g->left, T->left, T->right, p->right);
        }
        else
        {
            p->parent = g->parent;
            return connect34(g, p, T, g->left, p->left, T->left, T->right);
        }
    }
}

shared_ptr<AVLTNode>& search_in_tree_and_insert(shared_ptr<AVLTNode> &T, int k,
    shared_ptr<AVLTNode> parent)
{
    if (!T)
    {
        T = make_shared<AVLTNode>();
        T->parent = parent;
        T->key = k;
        return T;
    }
    else if (k < T->key)
    {
        // printf("now go to %d's left\n", T->key);
        return search_in_tree_and_insert(T->left, k, T);
    }
    else if (T->key < k)
    {
        // printf("now go to %d's right\n", T->key);
        return search_in_tree_and_insert(T->right, k, T);
    }
    else
        return T;
}

shared_ptr<AVLTNode> insert_node(shared_ptr<AVLTNode> T,
    int k)
{
    auto &insertPos = search_in_tree_and_insert(T, k, T);
    for (shared_ptr<AVLTNode> g = insertPos->parent; g; g = g->parent)
    {
        if (!is_balance(g))
        {
            // printf("%d is unbalanced\n", g->key);
            if (g->parent)
            {
                auto &fromParentTo = from_parent_to(g);
                // printf("%d has child %d\n", g->parent->key, fromParentTo->key);
                // printf("taller_child(%d) is %d\n", g->key, taller_child(g)->key);
                // printf("taller_child(%d) is %d\n", taller_child(g)->key,
                //     taller_child(taller_child(g))->key);
                fromParentTo = rotateAt(taller_child(taller_child(g)));
            }
            else
            {
                T = rotateAt(taller_child(taller_child(g)));
                T->parent = nullptr;
            }
            break;
        }
        else
        {
            update_height(g);
            // printf("%d is ok, it's height is %d\n", g->key, g->height);
        }
    }
    return T;
}

static vector<shared_ptr<AVLTNode>> nodeData;

void level_order_traversal(shared_ptr<AVLTNode> T)
{
    if (!T) return;
    queue<shared_ptr<AVLTNode>> Q;
    Q.push(T);
    while (!Q.empty())
    {
        auto t = Q.front();
        Q.pop();
        nodeData.push_back(t);
        if (t->left)
            Q.push(t->left);
        if (t->right)
            Q.push(t->right);
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
        // printf("\nnow going to insert %d\n", k);
        T = insert_node(T, k);
        // printf("after insertion, T->key = %d\n", T->key);
    }
    level_order_traversal(T);
    int output = 0;
    bool isComplete = true, noMoreHeight2 = false;
    for (auto pN : nodeData)
    {
        if (output++) putchar(' ');
        printf("%d", pN->key);
    }
    putchar('\n');
    for (int i = 0; i != N; ++i)
    {
        if (nodeData[i]->height > 2 && (!nodeData[i]->left ||
            !nodeData[i]->right))
        {
            isComplete = false;
            break;
        }
        else if (nodeData[i]->height == 1) noMoreHeight2 = true;
        else if (nodeData[i]->height == 2)
        {
            if (noMoreHeight2 || (nodeData[i]->right && !nodeData[i]->left))
            {
                isComplete = false;
                break;
            }
            if (nodeData[i]->left && !nodeData[i]->right) noMoreHeight2 = true;
        }
    }
    if (isComplete) printf("YES\n");
    else printf("NO\n");
    return 0;
}
