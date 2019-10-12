/*
 @Date    : 2018-02-27 08:57:56
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1110
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <string>

#define EMPTY -1

using namespace std;

struct TNode
{
    int left, right;
    int father = EMPTY;
};

static int N;
static const int MAXN = 100;
static TNode data[MAXN];

int find_root()
{
    for (int i = 0; i != N; ++i)
        if (data[i].father == EMPTY)
            return i;
}

int level_traversal(int root)
{
    queue<int> Q;
    Q.push(root);
    int v;
    int lastNode = root;
    int count = 0;
    while (!Q.empty())
    {
        v = Q.front();
        Q.pop();
        if (v != EMPTY)
        {
            ++count;
            lastNode = v;
        }
        else
        {
            if (count < N)
                return -1;
            else
                break;
        }
        Q.push(data[v].left);
        Q.push(data[v].right);
    }
    return lastNode;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    string l, r;
    int left, right;
    for (int i = 0; i != N; ++i)
    {
        cin >> l >> r;
        left = (l[0] == '-' ? EMPTY : stoi(l));
        right = (r[0] == '-' ? EMPTY : stoi(r));
        data[i].left = left;
        data[i].right = right;
        if (left != EMPTY) data[left].father = i;
        if (right != EMPTY) data[right].father = i;
    }
    int root = find_root();
    int lastNode = level_traversal(root);
    if (lastNode != -1)
        printf("YES %d\n", lastNode);
    else
        printf("NO %d\n", root);
    return 0;
}
