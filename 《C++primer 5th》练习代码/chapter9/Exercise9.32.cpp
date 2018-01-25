/*
 @Date    : 2017-12-24 17:42:17
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p356
 */

#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <fstream>
#include <sstream>
#include <list>
#include <forward_list>
#include <array>
#include <deque>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto it = v.begin(); it != v.end();)
    {
        if (*it & 1)
        {
            it = v.insert(it, *it++);
            ++it;
        }
        else
        {
            it = v.erase(it);
        }
    }

    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
