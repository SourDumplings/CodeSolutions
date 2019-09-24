/*
 @Date    : 2017-12-14 10:08:24
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p56
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    int i = 5, j =10;
    int *p = &i;
    cout << p << " " << *p << endl;
    p = &j;
    cout << p << " " << *p << endl;
    *p = 20;
    cout << p << " " << *p << endl;
    j = 30;
    cout << p << " " << *p << endl;
    return 0;
}

