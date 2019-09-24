/*
 @Date    : 2017-12-15 20:47:07
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p121
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int A[10];
    int *p = nullptr;
    for (p = A; p != &A[10]; p++)
    {
        *p = 0;
    }
    for (auto i : A)
    {
        cout << i << endl;
    }
    return 0;
}

