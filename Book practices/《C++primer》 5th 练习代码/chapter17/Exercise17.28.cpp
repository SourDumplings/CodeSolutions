/*
 @Date    : 2018-01-17 21:15:13
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

unsigned getRand()
{
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(0, 9);
    return u(e);
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i != 10; ++i)
        cout << getRand() << endl;
    return 0;
}
