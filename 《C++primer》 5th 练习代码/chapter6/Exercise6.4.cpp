/*
 @Date    : 2017-12-18 10:31:36
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

int fact(int n)
{
    int result = 1;
    while (n)
    {
        result *= n--;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    cout << fact(n) << endl;
    return 0;
}

