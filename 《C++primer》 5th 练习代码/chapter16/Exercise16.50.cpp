/*
 @Date    : 2018-01-13 20:59:02
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p699
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T> void f(T) { cout << "f(T)" << endl; return; };
template <typename T> void f(const T*) { cout << "f(const T*)" << endl; return; };
template <typename T> void g(T) { cout << "g(T)" << endl; return; };
template <typename T> void g(T*) { cout << "g(T*)" << endl; return; };

int main(int argc, char const *argv[])
{
    int i = 42, *p = &i;
    const int ci = 0, *pc = &ci;
    g(42);
    g(p);
    g(ci);
    g(pc);
    f(42);
    f(p);
    f(ci);
    f(pc);
    return 0;
}
