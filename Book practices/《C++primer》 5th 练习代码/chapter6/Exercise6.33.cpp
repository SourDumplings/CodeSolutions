/*
 @Date    : 2017-12-18 22:03:31
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p228
 */

#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list>

using namespace std;

// void printV(vector<int> v, unsigned i)
// {
//     if (i == v.size())
//     {
//         return;
//     }
//     else
//     {
//         cout << v[i] << " ";
//         printV(v, i+1);
//     }
// }

void printV(const vector<int> &v, vector<int> :: iterator it)
{
    if (it == v.end())
    {
        return;
    }
    else
    {
        cout << *it << " ";
        printV(v, it+1);
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    // printV(v, 0);
    printV(v, v.begin());
    return 0;
}

