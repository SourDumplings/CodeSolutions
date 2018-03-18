/*
 @Date    : 2018-03-05 19:57:08
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1130
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <memory>

using namespace std;

struct TNode
{
    string data;
    int left, right;
    TNode(string data_, int left_, int right_):
        data(data_), left(left_), right(right_) {}
};

static const int MAXN = 21;
static shared_ptr<TNode> treeNodeData[MAXN];
static int N;

int get_root(int sub)
{
    for (int i = 0; i != N; ++i)
    {
        if (treeNodeData[i]->left == sub || treeNodeData[i]->right == sub)
            return get_root(i);
    }
    return sub;
}

bool not_leaf(int node)
{
    return treeNodeData[node]->left >= 0 || treeNodeData[node]->right >= 0;
}

void in_order_traversal(int this_root, int root)
{
    if (root >= 0 && treeNodeData[this_root])
    {
        if (this_root != root && not_leaf(this_root)) putchar('(');
        in_order_traversal(treeNodeData[this_root]->left, root);
        cout << treeNodeData[this_root]->data;
        in_order_traversal(treeNodeData[this_root]->right, root);
        if (this_root != root && not_leaf(this_root)) putchar(')');
    }
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    fill(treeNodeData, treeNodeData + N, nullptr);
    string data;
    int left, right;
    for (int i = 0; i != N; ++i)
    {
        cin >> data >> left >> right;
        treeNodeData[i] = make_shared<TNode>(data, left-1, right-1);
    }
    int root = get_root(0);
    in_order_traversal(root, root);
    putchar('\n');
    return 0;
}

