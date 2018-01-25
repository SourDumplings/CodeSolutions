/*
 @Date    : 2017-12-11 13:19:09
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
    int a, b;
    cout << "Please input the a b:" <<endl;
    int i;
    cin >> a >> b;
    if (a <= b)
    {
        i = a;
    }
    else
    {
        i = b;
        b = a;
    }
    while (i <= b)
    {
        cout << i << endl;
        i++;
    }
    return 0;
}
