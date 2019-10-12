/*
 @Date    : 2018-01-17 19:52:17
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
using namespace std::regex_constants;

int main(int argc, char const *argv[])
{
    string zipcod = "(\\d{5})-?(\\d{4})";
    string fmt = "$1-$2";
    regex r(zipcod);
    ifstream fin("zipcode");
    ofstream fout("results");
    string s;
    while (getline(fin, s))
    {
        string result = regex_replace(s, r, fmt, format_no_copy);
        if (!result.empty())
            fout << result << endl;
    }
    return 0;
}
