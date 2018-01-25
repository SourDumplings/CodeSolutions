/*
 @Date    : 2017-12-15 21:26:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p126
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
    // vector<int> v(A, A+8);
    vector<int> v(begin(A), end(A));
    for (const auto i : v)
    {
        cout << i << endl;
    }
    return 0;
}

