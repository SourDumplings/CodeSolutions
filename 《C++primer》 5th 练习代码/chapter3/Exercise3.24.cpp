/*
 @Date    : 2017-12-15 19:17:07
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p113
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int i;
    vector<int> v;

    while (cin >> i)
    {
        v.push_back(i);
    }

    int sum;
    if (v.cbegin() == v.cend())
    {
        cout << "No elements." << endl;
    }
    else
    {
        for (auto it = v.cbegin(); it != v.cend(); it++)
        {
            if (it != v.cend() - 1)
            {
                sum = *it + *(++it);
                cout << sum << endl;
            }
        }
        // for (auto itb = v.cbegin(), ite = v.cend(); itb != ite - 1; itb++, ite--)
        // {
        //     sum = *itb + *(ite - 1);
        //     cout << sum << endl;
        // }
    }

    return 0;
}

