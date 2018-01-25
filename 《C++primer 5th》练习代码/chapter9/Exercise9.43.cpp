/*
 @Date    : 2017-12-24 21:16:34
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p364
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

void replace_string(string &s, const string &oldVal, const string &newVal)
{
    auto l = oldVal.size();
    if (!l)
    {
        return;
    }
    auto it = s.begin();
    while (it <= s.end() - 1)
    {
        auto it1 = it;
        auto it2 = oldVal.begin();
        while (it2 != oldVal.end() && *it1 == *it2)
        {
            ++it1;
            ++it2;
        }
        if (it2 == oldVal.end())
        {
            it = s.erase(it, it1);
            if (newVal.size())
            {
                it2 = newVal.end();
                do
                {
                    --it2;
                    it = s.insert(it, *it2);
                } while (it2 > newVal.begin());
            }
            it += newVal.size();
        }
        else
        {
            ++it;
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    string s = "tho thru tho!";
    replace_string(s, "thru", "through");
    cout << s << endl;
    replace_string(s, "tho", "though");
    cout << s << endl;
    replace_string(s, "through", "");
    cout << s << endl;
    return 0;
}
