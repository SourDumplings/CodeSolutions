/*
 @Date    : 2018-02-21 22:52:24
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1102
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define EMPTY -1
static int output = 0;

struct TNode
{
    int left, right;
    int father = EMPTY;
};

int read_child()
{
    char c;
    scanf("%c", &c);
    if (c == '-')
        return EMPTY;
    else
        return c - '0';
}

void level_traversal(TNode T[], int root)
{
    queue<int> Q;
    Q.push(root);
    int i;
    while (!Q.empty())
    {
        i = Q.front();
        Q.pop();
        if (output++) putchar(' ');
        printf("%d", i);
        if (T[i].right != EMPTY) Q.push(T[i].right);
        if (T[i].left != EMPTY) Q.push(T[i].left);

    }
    return;
}

void in_traversal(TNode T[], int root)
{
    if (T[root].right != EMPTY) in_traversal(T, T[root].right);
    if (output++) putchar(' ');
    printf("%d", root);
    if (T[root].left != EMPTY) in_traversal(T, T[root].left);
    return;
}

int find_root(TNode T[])
{
    int root = 0;
    while (T[root].father != EMPTY)
        root = T[root].father;
    return root;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d\n", &N);
    TNode T[N];
    for (int i = 0; i != N; ++i)
    {
        T[i].left = read_child();
        getchar();
        T[i].right = read_child();
        getchar();
        T[T[i].left].father = i;
        T[T[i].right].father = i;
    }
    int root = find_root(T);
    level_traversal(T, root);
    putchar('\n');
    output = 0;
    in_traversal(T, root);
    putchar('\n');
    return 0;
}
