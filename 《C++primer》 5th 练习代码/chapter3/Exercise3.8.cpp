/*
 @Date    : 2017-12-15 13:12:51
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p96
与Exercise3.6相比，使用范围的for明显更加简洁直观
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    // for (decltype(s.size()) i = 0; i < s.size(); i++)
    // {
    //     s[i] = 'X';
    // }
    decltype(s.size()) i = 0;
    while (i < s.size())
    {
        s[i++] = 'X';
    }
    cout << s << endl;
    return 0;
}

