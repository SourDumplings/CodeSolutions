/*
 @Date    : 2017-12-18 15:23:56
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p219
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

void print1(const int *p, const unsigned n)
{
    for (unsigned i = 0; i < n; ++i)
    {
        cout << p[i] << endl;
    }
    return;
}

void print2(const int (&A)[2])
{
    for (int i : A)
    {
        cout << i << endl;
    }
    return;
}

int main()
{
    int i = 0, j[2] = {0, 1};
    print1(&i, 1);
    print1(j, 2);
    print2(j);
    return 0;
}

