/*
 @Date    : 2017-12-15 16:49:40
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
#include <cctype>

using namespace std;

int main()
{
    string word;
    vector<string> v;

    while (cin >> word)
    {
        v.push_back(word);
    }

    for (auto &w : v)
    {
        for (auto &c : w)
        {
            c = toupper(c);
        }
    }

    for (auto &w : v)
    {
        cout << w << endl;
    }
    return 0;
}

