/*
 @Date    : 2018-03-13 12:48:25
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/821
 */

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct SubP
{
    int n;
    char s, m, d;
    SubP(int n_, char s_, char m_, char d_): n(n_), s(s_), m(m_), d(d_) {}
};

void hanoi(int n)
{
    stack<SubP> S;
    S.push(SubP(n, 'a', 'b', 'c'));
    while (!S.empty())
    {
        auto p = S.top(); S.pop();
        if (p.n == 1)
            printf("%c -> %c\n", p.s, p.d);
        else
        {
            S.push(SubP(p.n-1, p.m, p.s, p.d));
            S.push(SubP(1, p.s, p.m, p.d));
            S.push(SubP(p.n-1, p.s, p.d, p.m));
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    hanoi(n);
    return 0;
}

