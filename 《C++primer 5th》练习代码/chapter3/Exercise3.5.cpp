/*
 @Date    : 2017-12-15 10:55:57
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
    s1 += s2;
    cout << s1 << endl;
    s1 = s1 + " " + s2;
    cout << s1 << endl;
    return 0;
}

