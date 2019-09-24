/*
 @Date    : 2017-12-14 16:33:23
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p72
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <typeinfo>

using namespace std;

int main()
{
    int a = 3;
    auto c1 = a;
    decltype(a) c2 = a;
    decltype((a)) c3 = a;

    const int d = 5;
    auto f1 = d;
    decltype(d) f2 = d;

    cout << typeid(c1).name() << endl;
    cout << typeid(c1).name() << endl;
    cout << typeid(c1).name() << endl;
    cout << typeid(c1).name() << endl;
    cout << typeid(c1).name() << endl;

    c1++;
    c2++;
    c3++;
    f1++;
    // f2++;

    cout << a << " " << c1 << " " << c2 << " " << c3 << " "
         << f1 << " " << f2 << endl;
    return 0;
}

