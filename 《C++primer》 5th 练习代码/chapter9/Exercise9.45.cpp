/*
 @Date    : 2017-12-25 10:02:13
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

void name_string(string &name, const string &pre, const string &suff)
{
    name.insert(0, pre);
    name.append(" " + suff);
    return;
}

int main(int argc, char const *argv[])
{
    string s = "James Bond";
    name_string(s, "Mr.", "II");
    cout << s << endl;

    s = "M";
    name_string(s, "Mrs.", "Jr.");
    cout << s << endl;
    return 0;
}
