/*
 @Date    : 2017-12-16 09:37:13
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p130
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int ia[3][4] =
    {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    for (auto p = begin(ia); p != end(ia); p++)
    {
        for (auto q = begin(*p); q != end(*p); q++)
        {
            cout << *q << " ";
        }
        cout << endl;
    }
    return 0;
}

