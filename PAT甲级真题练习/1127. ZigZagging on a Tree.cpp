/*
 @Date    : 2018-03-04 10:38:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1127
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <memory>
#include <queue>

using namespace std;

struct TNode
{
    int key;
    shared_ptr<TNode> left = nullptr, right = nullptr;
    int depth = 0;
};

shared_ptr<TNode> build_tree(shared_ptr<TNode> T, int in[], int inB, int inE,
                             int post[], int postB, int postE, int depth)
{
    if (inB == inE) return T;
    int root = post[postE - 1];
    T = make_shared<TNode>();
    T->key = root;
    T->depth = depth;
    if (postB + 1 == postE) return T;
    int rootInPos;
    for (int i = inB; i != inE; ++i)
    {
        if (in[i] == root)
        {
            rootInPos = i;
            break;
        }
    }
    int leftLenghth = rootInPos - inB;
    T->left = build_tree(T->left, in, inB, rootInPos, post, postB, postB + leftLenghth, depth + 1);
    T->right = build_tree(T->right, in, rootInPos + 1, inE, post, postB + leftLenghth, postE - 1, depth + 1);
    return T;
}

void level_order_traversal(shared_ptr<TNode> T, queue<shared_ptr<TNode>> &level)
{
    queue<shared_ptr<TNode>> Q;
    Q.push(T);
    while (!Q.empty())
    {
        auto v = Q.front(); Q.pop();
        level.push(v);
        if (v->left) Q.push(v->left);
        if (v->right) Q.push(v->right);
    }
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    int in[N], post[N];
    for (int i = 0; i != N; ++i) scanf("%d", &in[i]);
    for (int i = 0; i != N; ++i) scanf("%d", &post[i]);
    shared_ptr<TNode> T = nullptr;
    T = build_tree(T, in, 0, N, post, 0, N, 0);
    queue<shared_ptr<TNode>> level;
    level_order_traversal(T, level);
    int nowDepth = 0;
    vector<shared_ptr<TNode>> sameLevel;
    int direction = -1;
    int output = 0;
    while (!level.empty())
    {
        for (; !level.empty() && level.front()->depth == nowDepth; level.pop())
            sameLevel.push_back(level.front());
        if (direction == 1)
        {
            for (auto node : sameLevel)
            {
                if (output++) putchar(' ');
                printf("%d", node->key);
            }
        }
        else
        {
            for (auto it = sameLevel.rbegin(); it != sameLevel.rend(); ++it)
            {
                if (output++) putchar(' ');
                printf("%d", (*it)->key);
            }
        }
        sameLevel.clear();
        ++nowDepth;
        direction *= -1;
    }
    putchar('\n');
    return 0;
}
