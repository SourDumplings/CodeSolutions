/*
 @Date    : 2018-01-13 17:00:24
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p695
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
    f(t2, t1);
    return;
}

template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2)
{
    f(t2, t1);
    return;
}

template <typename F, typename T1, typename T2>
void flip3(F f, T1 &&t1, T2 &&t2)
{
    f(std::forward<T2>(t2), std::forward<T1>(t1));
    return;
}

void f(int v1, int &v2)
{
    ++v1;
    ++v2;
    return;
}

void g(int &&i, int &j)
{
    i = 1;
    j = 2;
    ++i;
    ++j;
    return;
}

int main(int argc, char const *argv[])
{
    int t1 = 10, t2 = 20;

    cout << "for function f:" << endl;
    printf("Before calling flip1, t1 = %d, t2 = %d\n", t1, t2);
    flip1(f, t1, t2);
    printf("After calling flip1, t1 = %d, t2 = %d\n", t1, t2);

    printf("Before calling flip2, t1 = %d, t2 = %d\n", t1, t2);
    flip2(f, t1, t2);
    printf("After calling flip2, t1 = %d, t2 = %d\n", t1, t2);

    printf("Before calling flip3, t1 = %d, t2 = %d\n", t1, t2);
    flip3(f, t1, t2);
    printf("After calling flip3, t1 = %d, t2 = %d\n", t1, t2);

    cout << "for function g:" << endl;
    // flip1(g, t1, 20);
    // flip2(g, t1, 20);
    flip3(g, t1, 20);

    return 0;
}
