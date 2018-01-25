/*
 @Date    : 2018-01-14 11:51:20
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p706
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include "StrVec.h"
#include "Vec_template.h"

using namespace std;

int main(int argc, char const *argv[])
{
    // StrVec vs;
    // string s1{"hello"}, s2{"word"};
    // vs.push_back(s1);
    // vs.emplace_back(s2);
    // vs.emplace_back(10, 'c');
    // for (const auto &s : vs)
    // {
    //     cout << s << endl;
    // }

    Vec<string> vs;
    string s1{"hello"}, s2{"word"};
    vs.push_back(s1);
    vs.emplace_back(s2);
    vs.emplace_back(10, 'c');
    for (const auto &s : vs)
    {
        cout << s << endl;
    }
    return 0;
}
