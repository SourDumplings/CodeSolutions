/*
 @Date    : 2018-01-17 21:23:38
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p749
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

unsigned getRand(unsigned min, unsigned max)
{
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(0, 9999);
    u = uniform_int_distribution<unsigned>(min, max);
    return u(e);
}

int main(int argc, char const *argv[])
{
    cout << "min 0 max 9: ";
    for (int i = 0; i != 10; ++i)
        cout << getRand(0, 9) << " ";
    cout << endl;

    cout << "min 10 max 100: ";
    for (int i = 0; i != 10; ++i)
        cout << getRand(10, 100) << " ";
    cout << endl;

    cout << "min 0 max 9: ";
    for (int i = 0; i != 10; ++i)
        cout << getRand(0, 9) << " ";
    cout << endl;

    return 0;
}

