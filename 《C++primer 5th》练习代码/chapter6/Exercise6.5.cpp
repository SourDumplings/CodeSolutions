/*
 @Date    : 2017-12-18 10:33:43
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p205
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

unsigned abs(int n)
{
    if (n < 0)
    {
        n *= -1;
    }
    return n;
}

int main()
{
    int n;
    cin >> n;
    cout << "Its absolute value is " << abs(n) << endl;
    return 0;
}

