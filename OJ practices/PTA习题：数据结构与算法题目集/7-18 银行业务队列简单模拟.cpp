/*
 @Date    : 2018-03-13 13:00:49
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/825
 */

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    queue<int> odds, evens;
    int id;
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
    {
        scanf("%d", &id);
        if ((id & 1) == 0) evens.push(id);
        else odds.push(id);
    }
    int Ap = 0;
    int output = 0;
    while (!odds.empty() || !evens.empty())
    {
        for (Ap = 0; Ap != 2 && !odds.empty(); ++Ap)
        {
            if (output++) putchar(' ');
            printf("%d", odds.front()); odds.pop();
        }
        if (!evens.empty())
        {
            if (output++) putchar(' ');
            printf("%d", evens.front()); evens.pop();
        }
    }
    putchar('\n');
    return 0;
}

