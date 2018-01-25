/*
 @Date    : 2017-12-17 21:26:59
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p191
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string thisword, lastword;
    while (cin >> thisword)
    {
        if (thisword == lastword)
        {
            cout << thisword << endl;
            break;
        }
        lastword = thisword;
    }
    return 0;
}

