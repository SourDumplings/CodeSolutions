/*
 @Date    : 2017-12-11 13:13:00
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p18
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int currVal = 0, Val = 0;
    if (cin >> currVal)
    {
        int cnt = 1;
        while (cin >> Val)
        {
            if (Val == currVal)
            {
                cnt++;
            }
            else
            {
                cout << currVal << " occurs "
                     << cnt << " times" << endl;
                currVal = Val;
                cnt = 1;
            }
        }
        cout << currVal << " occurs "
             << cnt << " times" << endl;
    }
    return 0;
}

