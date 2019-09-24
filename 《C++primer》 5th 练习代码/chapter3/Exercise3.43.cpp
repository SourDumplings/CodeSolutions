/*
 @Date    : 2017-12-16 09:26:42
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

    // for (const auto &row : ia)
    // {
    //     for (auto col : row)
    //     {
    //         cout << col << " ";
    //     }
    //     cout << endl;
    // }

    // for (unsigned i = 0; i < 3; i++)
    // {
    //     for (unsigned j = 0; j < 4; j++)
    //     {
    //         cout << ia[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int (*p)[4] = begin(ia); p != end(ia); p++)
    {
        for (int *q = begin(*p); q != end(*p); q++)
        {
            cout << *q << " ";
        }
        cout << endl;
    }
    return 0;
}

