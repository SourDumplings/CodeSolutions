/*
 @Date    : 2017-12-24 18:22:38
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p359
输出结果：
capacity: 0 size: 0
capacity: 1 size: 1
capacity: 2 size: 2
capacity: 4 size: 3
capacity: 8 size: 5
capacity: 16 size: 9
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
    vector<int> v;
    int s, c;

    cout << "capacity: " << v.capacity() << " size: " << v.size() << endl;

    for (s = v.size(), c = v.capacity(); s <= c; ++s)
    {
        v.push_back(0);
    }
    cout << "capacity: " << v.capacity() << " size: " << v.size() << endl;

    for (s = v.size(), c = v.capacity(); s <= c; ++s)
    {
        v.push_back(0);
    }
    cout << "capacity: " << v.capacity() << " size: " << v.size() << endl;

    for (s = v.size(), c = v.capacity(); s <= c; ++s)
    {
        v.push_back(0);
    }
    cout << "capacity: " << v.capacity() << " size: " << v.size() << endl;

    for (s = v.size(), c = v.capacity(); s <= c; ++s)
    {
        v.push_back(0);
    }
    cout << "capacity: " << v.capacity() << " size: " << v.size() << endl;

    for (s = v.size(), c = v.capacity(); s <= c; ++s)
    {
        v.push_back(0);
    }
    cout << "capacity: " << v.capacity() << " size: " << v.size() << endl;

    return 0;
}
