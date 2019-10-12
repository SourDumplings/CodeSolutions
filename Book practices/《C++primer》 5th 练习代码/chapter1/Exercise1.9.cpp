/*
 @Date    : 2017-12-11 09:55:57
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p13
 */

#include <iostream>

using namespace std;

int main()
{
    int i = 50;
    int sum = 0;
    while (i <= 100)
    {
        sum += i;
        i++;
    }
    cout << sum <<endl;
    return 0;
}

