/*
 @Date    : 2017-12-15 13:09:56
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p96
和Exercise3.6结果一样
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
    for (char &c : s)
    {
        c = 'X';
    }
    cout << s << endl;
    return 0;
}

