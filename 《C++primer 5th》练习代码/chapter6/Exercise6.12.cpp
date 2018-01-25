/*
 @Date    : 2017-12-18 14:08:53
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p212
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    return;
}

int main()
{
    int a = 3, b = 5;
    swap(a, b);
    cout << "a = " << a << " b = " << b << endl;
    return 0;
}

