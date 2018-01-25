/*
 @Date    : 2017-12-15 18:48:24
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p110
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> text;
    string s;
    while (getline(cin, s))
    {
        text.push_back(s);
    }
    for (auto it = text.begin(); it != text.end() && !it->empty(); it++)
    {
        for (auto itc = it->begin(); itc != it->end(); itc++)
        {
            *itc = toupper(*itc);
        }
        cout << *it << endl;
    }
    return 0;
}

