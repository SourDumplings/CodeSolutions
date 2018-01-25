/*
 @Date    : 2017-12-19 11:24:20
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p238
 */

#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list>

using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending = "s");

int main()
{
    string s1 = "success", s2 = "failure";
    cout << make_plural(2, s1) << endl;
    cout << make_plural(2, s2) << endl;
    return 0;
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return ctr > 1 ? word + ending : word;
}

