/*
 @Date    : 2017-12-15 10:49:47
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p90
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    // if (s1 != s2)
    // {
    //     string s;
    //     s = s1 > s2 ? s1 : s2;
    //     cout << s << endl;
    // }
    // else
    // {
    //     cout << "Two strings are equal." << endl;
    // }

    auto l1 = s1.size(), l2 = s2.size();
    if (l1 != l2)
    {
        string s;
        s = l1 > l2 ? s1 : s2;
        cout << s << " is longer." << endl;
    }
    else
    {
        cout << "They have same length." << endl;
    }
    return 0;
}

