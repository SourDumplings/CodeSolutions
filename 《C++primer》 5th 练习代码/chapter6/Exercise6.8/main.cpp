/*
 @Date    : 2017-12-18 11:01:39
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p207
 */

#include <iostream>
#include "Chapter6.h"

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << "The abosulte value of n is " << abs(n) << endl;
    return 0;
}

unsigned abs(int n)
{
    return n < 0 ? -1 * n : n;
}


