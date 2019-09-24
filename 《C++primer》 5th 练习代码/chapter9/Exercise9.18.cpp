/*
 @Date    : 2017-12-23 21:08:05
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p346
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
    deque<string> q;
    string s;
    while (cin >> s)
    {
        q.push_back(s);
    }
    for (auto it = q.cbegin(); it != q.cend(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}
