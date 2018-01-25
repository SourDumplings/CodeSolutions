/*
 @Date    : 2017-12-24 11:34:44
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p350
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
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> v;
    list<int> l;
    for (int i : ia)
    {
        v.push_back(i);
        l.push_back(i);
    }
    // cout << "s" << endl;
    for (auto it = v.begin(); it != v.end();)
    {
        // if (*it % 2 == 0)
        if (!(*it & 1))
        {
            it = v.erase(it);
        }
        else
        {
            ++it;
        }
    }
    for (auto it = l.begin(); it != l.end();)
    {
        // if (*it % 2)
        if (*it & 1)
        {
            it = l.erase(it);
        }
        else
        {
            ++it;
        }
    }
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
