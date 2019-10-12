/*
 @Date    : 2017-12-18 13:58:41
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p210
 */

#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int main()
{
    int a = 3, b = 5;
    swap(a, b);
    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}

