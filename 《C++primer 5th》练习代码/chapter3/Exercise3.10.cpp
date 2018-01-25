/*
 @Date    : 2017-12-15 13:16:57
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p96
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    string s;
    cin >> s;
    string result;
    for (auto c : s)
    {
        if (!ispunct(c))
        {
            result += c;
        }
    }
    cout << result << endl;
    return 0;
}

