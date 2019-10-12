/*
 @Date    : 2017-12-15 18:56:30
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p110
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(10);
    for (auto &i : v)
    {
        cin >> i;
        i *= 2;
    }
    for (auto it = v.cbegin(); it != v.cend(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}

