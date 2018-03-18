/*
 @Date    : 2018-02-21 11:58:11
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1099
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <stack>
#include <array>

using namespace std;

#define EMPTY -1

struct TNode
{
    int num;
    int left, right;
};

static const int MAXN = 101;
static array<TNode, MAXN> T;
static int N;

void left_go(int root, stack<int> &S)
{
    while (root != EMPTY)
    {
        S.push(root);
        root = T[root].left;
    }
    return;
}

void solve(int root, deque<int> &seq)
{
    int leftMost;
    stack<int> S;
    left_go(root, S);
    while (!S.empty())
    {
        leftMost = S.top();
        S.pop();
        T[leftMost].num = seq.front();
        seq.pop_front();
        if (T[leftMost].right != EMPTY)
            solve(T[leftMost].right, seq);
    }
    return;
}

void level_order_traversal()
{
    deque<int> Q;
    Q.push_back(0);
    int r;
    int output = 0;
    while (!Q.empty())
    {
        r = Q.front();
        Q.pop_front();
        if (output++)
            putchar(' ');
        printf("%d", T[r].num);
        if (T[r].left != EMPTY) Q.push_back(T[r].left);
        if (T[r].right != EMPTY) Q.push_back(T[r].right);
    }
    putchar('\n');
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
    {
        scanf("%d %d", &T[i].left, &T[i].right);
        T[i].num = EMPTY;
    }
    deque<int> seq(N);
    for (int i = 0; i != N; ++i)
        scanf("%d", &seq[i]);
    sort(seq.begin(), seq.end());
    solve(0, seq);
    level_order_traversal();
    return 0;
}
