/*
 @Date    : 2017-12-18 14:07:04
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p212
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

void reset(int &n)
{
    n = 1;
    return;
}

int main()
{
    int n = 5;
    reset(n);
    cout << n << endl;
    return 0;
}

