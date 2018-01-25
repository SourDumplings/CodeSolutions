/*
 @Date    : 2017-12-24 19:43:25
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p361
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
    string s;
    s.reserve(100);
    char c;
    while (cin >> c)
    {
        s.push_back(c);
    }
    cout << s << endl;
    return 0;
}
