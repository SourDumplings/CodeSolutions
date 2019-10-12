/*
 @Date    : 2017-12-18 14:28:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p215
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stdexcept>
#include <cctype>

using namespace std;

void detectCap(const string &s)
{
    for (auto c : s)
    {
        if (isupper(c))
        {
            printf("Yes\n");
            return;
        }
    }
}

void convert(string &s)
{
    for (auto &c : s)
    {
        c = tolower(c);
    }
    return;
}

int main()
{
    string s;
    cin >> s;

    detectCap(s);

    convert(s);
    cout << s;
    return 0;
}

