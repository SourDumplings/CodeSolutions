/*
 @Date    : 2018-03-15 13:17:04
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/865
 */

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);
    priority_queue<int> Q;
    for (unsigned i = 0; i < N; ++i)
    {
        int w;
        scanf("%d", &w);
        Q.push(w);
    }
    int output = 0;
    for (int i = 0; i != N && i != M; ++i)
    {
        if (output++)
        {
            putchar(' ');
        }
        printf("%d", Q.top()); Q.pop();
    }
    putchar('\n');
    return 0;
}

