/*
 @Date    : 2017-12-19 16:03:04
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p250
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list>

using namespace std;

int f1(int a, int b)
{
    return a * b;
}
int f2(int a, int b)
{
    return a / b;
}
int f3(int a, int b)
{
    return a + b;
}
int f4(int a, int b)
{
    return a - b;
}

int main()
{
    decltype(f1) *p1 = f1, *p2 = f2, *p3 = f3, *p4 = f4;
    vector<decltype(f1)*> v{p1, p2, p3, p4};
    int a = 2, b = 3;

    cout << v[0](a, b) << endl;
    cout << v[1](a, b) << endl;
    cout << v[2](a, b) << endl;
    cout << v[3](a, b) << endl;

    return 0;
}

