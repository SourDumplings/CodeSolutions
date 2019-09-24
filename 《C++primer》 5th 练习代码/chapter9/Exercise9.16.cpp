/*
 @Date    : 2017-12-23 19:41:41
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p341
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

bool l_v_equal(list<int> l, vector<int> v)
{
    auto itv = v.cbegin();
    auto itl = l.cbegin();
    for (; itv != v.cend() && itl != l.cend(); ++itl, ++itv)
    {
        if (*itl != *itv)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    list<int> l = {1, 2, 4, 5, 6, 7};
    if (l_v_equal(l, v))
    {
        cout << "equal" << endl;
    }
    else
    {
        cout << "unequal" << endl;
    }
    return 0;
}
