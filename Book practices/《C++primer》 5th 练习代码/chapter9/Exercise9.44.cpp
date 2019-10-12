/*
 @Date    : 2017-12-25 09:29:40
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
    unsigned p = 0;
    while ((p = s.find(oldVal, p)) != string::npos)
    {
        s.replace(p, oldVal.size(), newVal);
        p += newVal.size();
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
