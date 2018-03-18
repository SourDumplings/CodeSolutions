/*
 @Date    : 2018-02-28 15:51:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1115
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

struct TNode
{
    int key;
    TNode(int key_) : key(key_) {}
    shared_ptr<TNode> left = nullptr, right = nullptr;
    int depth;
};

static vector<shared_ptr<TNode>> data;

void insert_node(shared_ptr<TNode> &T, int key)
{
    if (T == nullptr)
    {
        T = make_shared<TNode>(key);
        data.push_back(T);
    }
    else if (key <= T->key)
        insert_node(T->left, key);
    else
        insert_node(T->right, key);
    return;
}

void get_depth(shared_ptr<TNode> &root, int depth)
{
    root->depth = depth;
    if (root->left) get_depth(root->left, depth + 1);
    if (root->right) get_depth(root->right, depth + 1);
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    shared_ptr<TNode> T;
    int key;
    while (N--)
    {
        scanf("%d", &key);
        insert_node(T, key);
    }
    get_depth(T, 0);
    sort(data.begin(), data.end(), []
        (const shared_ptr<TNode> p1, const shared_ptr<TNode> &p2)
        { return p1->depth < p2->depth; });
    int maxDepth = (*data.rbegin())->depth;
    int lowestNum = 0, secondLowestNum = 0;
    for (auto it = data.rbegin(); it != data.rend(); ++it)
    {
        if ((*it)->depth == maxDepth) ++lowestNum;
        else if ((*it)->depth == maxDepth - 1) ++secondLowestNum;
        else break;
    }
    printf("%d + %d = %d\n", lowestNum, secondLowestNum, lowestNum + secondLowestNum);
    return 0;
}
