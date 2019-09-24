/*
 @Date    : 2017-12-15 16:54:12
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p105
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
    int first = 1;
    if (v.empty())
    {
        cout << "No elements." << endl;
    }
    else
    {
        // for (decltype(v.size()) i = 0; i < v.size(); i++)
        // {
        //     if (first)
        //     {
        //         sum = v[i];
        //         first = 0;
        //     }
        //     else
        //     {
        //         sum += v[i];
        //         cout << sum << endl;
        //         first = 1;
        //     }
        // }
        for (decltype(v.size()) i = 0; i < v.size(); i++)
        {
            auto f = i, s = v.size() - i - 1;
            if (f >= s)
            {
                break;
            }
            sum = v[f] + v[s];
            cout << sum << endl;
        }
    }

    return 0;
}

