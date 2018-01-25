/*
 @Date    : 2018-01-17 21:19:59
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

unsigned getRand(unsigned seed)
{
    static default_random_engine e(seed);
    static uniform_int_distribution<unsigned> u(0, 9);
    return u(e);
}

int main(int argc, char const *argv[])
{
    cout << "seed 0: ";
    for (int i = 0; i != 10; ++i)
        cout << getRand(0) << " ";
    cout << endl;

    cout << "seed 1: ";
    for (int i = 0; i != 10; ++i)
        cout << getRand(1) << " ";
    cout << endl;

    cout << "seed 2: ";
    for (int i = 0; i != 10; ++i)
        cout << getRand(2) << " ";
    cout << endl;

    cout << "seed 0: ";
    for (int i = 0; i != 10; ++i)
        cout << getRand(0) << " ";
    cout << endl;

    return 0;
}
