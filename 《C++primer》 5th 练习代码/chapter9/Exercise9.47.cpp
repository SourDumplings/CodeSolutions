/*
 @Date    : 2017-12-24 20:39:49
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p367
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

void find_char(const string &s, const string &chars)
{
    cout << "We are searching " << chars << " in " << s << endl;
    unsigned pos = 0;
    while ((pos = s.find_first_of(chars, pos)) != string::npos)
    {
        cout << "pos: " << pos << ", char: " << s[pos] << endl;

        ++pos;
    }
    return;
}

void find_not_char(const string &s, const string &chars)
{
    cout << "We are searching not of " << chars << " in " << s << endl;
    unsigned pos = 0;
    while ((pos = s.find_first_not_of(chars, pos)) != string::npos)
    {
        cout << "pos: " << pos << ", char: " << s[pos] << endl;

        ++pos;
    }
    return;
}

int main(int argc, char const *argv[])
{
    string s = "ab2c3d7R4E6";
    string num = "0123456789";
    string alpha = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPSDFGHJKLZXCVBNM";
    // find_char(s, num);
    // find_char(s, alpha);
    find_not_char(s, alpha);
    find_not_char(s, num);
    return 0;
}
