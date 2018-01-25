/*
 @Date    : 2017-12-15 21:30:31
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
    vector<int> v{1, 2, 3, 5};
    int A[4];
    for (unsigned i = 0; i < 4; i++)
    {
        A[i] = v[i];
    }
    for (unsigned i = 0; i < 4; i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}

