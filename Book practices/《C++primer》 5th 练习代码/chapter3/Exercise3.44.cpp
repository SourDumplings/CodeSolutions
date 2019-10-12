/*
 @Date    : 2017-12-16 09:33:29
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

    using int_array = int[4];

    for (int_array *p = ia; p != ia + 3; p++)
    {
        for (int *q = *p; q != *p + 4; q++)
        {
            cout << *q << " ";
        }
        cout << endl;
    }
    return 0;
}

