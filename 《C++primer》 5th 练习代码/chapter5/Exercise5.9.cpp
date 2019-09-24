/*
 @Date    : 2017-12-17 15:42:50
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p183
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
    int cnt = 0;
    for (char c : s)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

