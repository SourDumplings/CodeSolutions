/*
 @Date    : 2017-12-14 15:28:01
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p70
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto g = ci;
    cout << a << " " << b << " " << c << " " << d << " "
         << e << " " << g << endl;
    a = 42;
    b = 42;
    c = 42;
    d = 42;
    e = 42;
    g = 42;
    cout << a << " " << b << " " << c << " " << d << " "
         << e << " " << g << endl;
    return 0;
}

