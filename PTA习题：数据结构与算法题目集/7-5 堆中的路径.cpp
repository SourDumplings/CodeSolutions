/*
 @Date    : 2018-03-10 11:31:30
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/713
 */

#include <iostream>
#include <cstdio>

using namespace std;

static const int MAXN = 1001;

struct Heap
{
    int heapSize = 0;
    int data[MAXN];
    void insert(int i);
};

void Heap::insert(int x)
{
    data[++heapSize] = x;
    int c;
    for (c = heapSize; c >> 1 > 0 && data[c >> 1] > x; c >>= 1)
        data[c] = data[c >> 1];
    data[c] = x;
    return;
}

void print_path(const Heap &H, int index)
{
    int output = 0;
    for (int p = index; p > 0; p >>= 1)
    {
        if (output++) putchar(' ');
        printf("%d", H.data[p]);
    }
    putchar('\n');
    return;
}

int main(int argc, char const *argv[])
{
    int N, M, x;
    scanf("%d %d", &N, &M);
    Heap H;
    for (int i = 0; i != N; ++i)
    {
        scanf("%d", &x);
        H.insert(x);
    }
    for (int i = 0; i != M; ++i)
    {
        int index;
        scanf("%d", &index);
        print_path(H, index);
    }
    return 0;
}

