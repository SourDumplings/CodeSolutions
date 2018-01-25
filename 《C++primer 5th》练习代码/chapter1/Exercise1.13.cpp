/*
 @Date    : 2017-12-11 10:10:40
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p14
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int sum = 0;

    for (int i = 50; i <= 100; i++)
    {
        sum += i;
    }
    cout << sum << endl;

    for (int i = 10; i >= 0; i--)
    {
        cout << i << endl;
    }

    int a, b;
    cout << "Please input the value of a b(a < b):" << endl;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        cout << i << endl;
    }
    return 0;
}

