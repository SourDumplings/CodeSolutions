/*
 @Date    : 2018-01-17 15:08:09
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p741
 */

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

bool valid(const smatch &m)
{
    if (m[1].matched)
        return m[3].matched &&
               (m[4].matched == false || m[4].str() == " ");
    else
        return !m[3].matched &&
               (m[4].str() == m[6].str());
}

int main(int argc, char const *argv[])
{
    string phone = "(\\()?(\\d{3})(\\))?([-.]|(\\s)*)?(\\d{3})([-.]|(\\s)*)?(\\d{4})";
    regex r(phone);
    smatch m;
    string s;
    ifstream fin("phones");
    while (getline(fin, s))
    {
        for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
        {
            if (valid(*it))
                cout << "valid: " << it->str() << endl;
            else
                cout << "not valid: " << it->str() << endl;
        }
    }
    return 0;
}
