/*
 @Date    : 2017-12-16 16:20:49
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p152
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    for (auto &i : v)
    {
        i = (i % 2) ? i * 2 : i;
    }
    for (auto &i : v)
    {
        cout << i << endl;
    }
    return 0;
}

