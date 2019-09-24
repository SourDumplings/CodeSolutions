/*
 @Date    : 2017-12-15 20:11:06
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p117
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int A[10];
    for (unsigned i = 0; i < 10; i++)
    {
        A[i] = i;
    }
    for (auto i : A)
    {
        cout << i << endl;
    }
    return 0;
}

