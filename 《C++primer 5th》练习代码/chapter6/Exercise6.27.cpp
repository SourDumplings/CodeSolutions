/*
 @Date    : 2017-12-18 16:21:23
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p222
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list>

using namespace std;

int sum(initializer_list<int> l)
{
    int r = 0;
    for (int i : l)
    {
        r += i;
    }
    return r;
}

int main()
{
    int r = sum({1, 2, 3});
    cout << r << endl;
    return 0;
}

