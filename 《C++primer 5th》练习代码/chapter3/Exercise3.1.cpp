/*
 @Date    : 2017-12-15 09:53:09
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p83
重写了Exercise1.9
 */

#include <iostream>

using std :: cin;
using std :: cout;
using std :: endl;

int main()
{
    int sum = 0;
    for (int i = 50; i <= 100; i++)
    {
        sum += i;
    }
    cout << sum << endl;
    return 0;
}

