/*
 @Date    : 2017-12-14 10:36:12
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
    int i = 0;
    int *p1 = nullptr;
    int *p = &i;
    if (p1)
    {
        cout << "p1 pass" << endl;
    }
    if (p)
    {
        cout << "p pass" << endl;
    }
    if (*p)
    {
        cout << "*p pass" << endl;
    }
    return 0;
}

