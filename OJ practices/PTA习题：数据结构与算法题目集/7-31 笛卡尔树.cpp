/*
 @Date    : 2018-03-15 08:42:59
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/858
注意判断BST要用中序遍历，用层序遍历是错误的
比如反例：
      5
  2       6
1   7
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct TNode
{
    int K1, K2;
    int left = -1, right = -1;
    int p = -1;
};

static const int MAXN = 1001;
static TNode data[MAXN];

int get_root(int c)
{
    if (data[c].p == -1)
        return c;
    return get_root(data[c].p);
}

static vector<int> level(1);
static vector<int> in;
static bool isBST = true;

void in_traversal(int root)
{
    if (root != -1)
    {
        in_traversal(data[root].left);
        in.push_back(data[root].K1);
        in_traversal(data[root].right);
    }
    return;
}

void level_traversal(int root)
{
    queue<int> Q;
    Q.push(root);
    while (!Q.empty())
    {
        int p = Q.front(); Q.pop();
        level.push_back(p);
        if (data[p].left != -1)
            Q.push(data[p].left);
        if (data[p].right != -1)
            Q.push(data[p].right);
    }
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
    {
        scanf("%d %d %d %d", &data[i].K1, &data[i].K2, &data[i].left, &data[i].right);
        if (data[i].left != -1) data[data[i].left].p = i;
        if (data[i].right != -1) data[data[i].right].p = i;
    }
    int root = get_root(0);
    in_traversal(root);
    for (int i = 0; i != N; ++i)
    {
        if (i != 0 && in[i] <= in[i-1])
        {
            isBST = false;
            break;
        }
    }
    if (isBST)
    {
        level_traversal(root);
        bool isSmallHeap = true;
        for (int p = 1; p * 2 <= N; ++p)
        {
            int c = p * 2;
            if (data[level[p]].K2 >= data[level[c]].K2 ||
                (c + 1 <= N && data[level[p]].K2 >= data[level[c+1]].K2))
            {
                isSmallHeap = false;
                break;
            }
        }
        if (isSmallHeap)
            printf("YES\n");
        else
            printf("NO\n");
    }
    else
        printf("NO\n");
    return 0;
}

