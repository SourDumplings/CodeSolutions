/*
 @Date    : 2017-12-17 10:33:02
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p158
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int x[10], *p = x;
    cout << sizeof(x) / sizeof(*x) << endl;
    cout << sizeof(p) / sizeof(*p) << endl;
    return 0;
}

