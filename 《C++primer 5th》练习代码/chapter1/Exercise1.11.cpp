/*
 @Date    : 2017-12-11 10:06:23
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p13
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a, b;
    cout << "Please input the a b(a < b):" <<endl;
    int i;
    cin >> a >> b;
    i = a;
    while (i <= b)
    {
        cout << i << endl;
        i++;
    }
    return 0;
}

