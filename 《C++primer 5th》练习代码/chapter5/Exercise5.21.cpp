/*
 @Date    : 2017-12-17 21:29:49
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p192
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    string thisword, lastword;
    while (cin >> thisword)
    {
        if (thisword == lastword && isupper(thisword[0]))
        {
            cout << thisword << endl;
            break;
        }
        lastword = thisword;
    }
    return 0;
}

