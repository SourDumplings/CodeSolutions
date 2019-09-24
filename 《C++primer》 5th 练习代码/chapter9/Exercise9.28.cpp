/*
 @Date    : 2017-12-24 12:29:40
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p352
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

forward_list<string>& addStr(forward_list<string> &fl, string &s1, string &s2)
{
    auto pre = fl.before_begin();
    for (auto curr = fl.begin(); curr != fl.end(); ++curr)
    {
        if (*curr == s1)
        {
            fl.insert_after(curr, s2);
            return fl;
        }
        else
        {
            pre = curr;
        }
    }
    fl.insert_after(pre, s2);
    return fl;
}

int main(int argc, char const *argv[])
{
    forward_list<string> fl{"I", "love", "you"};
    string s1{"he"}, s2{" and him"};
    fl = addStr(fl, s1, s2);
    for (string i : fl)
    {
        cout << i << endl;
    }
    return 0;
}
