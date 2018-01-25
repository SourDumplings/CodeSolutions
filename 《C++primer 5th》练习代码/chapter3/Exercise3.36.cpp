/*
 @Date    : 2017-12-15 20:49:15
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
    int A1[10] = {0}, A2[10] = {0};
    int flag = 1;
    for (unsigned i = 0; i < 10; i++)
    {
        if (A1[i] != A2[i])
        {
            flag = 0;
            break;
        }
    }
    vector<int> v1 = {1, 3, 3}, v2 = {1, 2, 3};
    for (unsigned i = 0; i < 3; i++)
    {
        if (v1[i] != v2[i])
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        cout << "same" << endl;
    }
    else
    {
        cout << "different" << endl;
    }
    return 0;
}

