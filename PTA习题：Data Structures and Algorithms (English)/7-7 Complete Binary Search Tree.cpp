/*
 @Date    : 2018-09-07 19:17:07
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/16/problems/669
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
const int MAXN = 1005;
int level[MAXN], num[MAXN];
int inI = 0;

void in_order_traversal(int r)
{
    if (r <= N)
    {
        in_order_traversal(r * 2);
        level[r] = num[inI++];
        in_order_traversal(r * 2 + 1);
    }
    return;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
        scanf("%d", &num[i]);
    sort(num, num+N);
    in_order_traversal(1);
    int output = 0;
    for (int i = 1; i != N + 1; ++i)
    {
        if (output++)
            putchar(' ');
        printf("%d", level[i]);
    }
    return 0;
}
