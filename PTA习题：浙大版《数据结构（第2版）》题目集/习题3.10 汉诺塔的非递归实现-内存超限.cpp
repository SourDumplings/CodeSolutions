/*
 @Date    : 2018-03-12 08:50:25
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/5892
 */

#include <iostream>
#include <cstdio>
#include <stack>
#include <tuple>

using namespace std;

void hanoi(int n, char s, char m, char d)
{
    stack<tuple<int, char, char, char>> S;
    S.push(make_tuple(n, s, m, d));
    while (!S.empty())
    {
        auto t = S.top(); S.pop();
        if (get<0>(t) == 1)
            printf("%c -> %c\n", get<1>(t), get<3>(t));
        else if (get<0>(t) == 2)
        {
            printf("%c -> %c\n", get<1>(t), get<2>(t));
            printf("%c -> %c\n", get<1>(t), get<3>(t));
            printf("%c -> %c\n", get<2>(t), get<3>(t));
        }
        else
        {
            S.push(make_tuple(n-1, get<2>(t), get<1>(t), get<3>(t)));
            S.push(make_tuple(1, get<1>(t), get<2>(t), get<3>(t)));
            S.push(make_tuple(n-1, get<1>(t), get<3>(t), get<2>(t)));
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    hanoi(n, 'a', 'b', 'c');
    return 0;
}

