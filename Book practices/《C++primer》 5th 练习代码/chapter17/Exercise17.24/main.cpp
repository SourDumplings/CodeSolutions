/*
 @Date    : 2018-01-17 19:07:43
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p744
 */

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

int main(int argc, char const *argv[])
{
    string phone = "(\\()?(\\d{3})(\\))?([ -.])?(\\d{3})([ -.])?(\\d{4})";
    regex r(phone);
    smatch m;
    string s;
    string fmt = "$2.$5.$7";
    ifstream fin("phones");
    while (getline(fin, s))
        cout << regex_replace(s, r, fmt) << endl;
    return 0;
}
