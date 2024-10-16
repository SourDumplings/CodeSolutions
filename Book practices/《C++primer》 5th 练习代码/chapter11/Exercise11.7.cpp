/*
 @Date    : 2017-12-28 13:47:13
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p424
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
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using namespace std::placeholders;

void add_family(map<string, vector<string>> &families, const string &family)
{
    if (families.find(family) == families.end())
    {
        families[family] = vector<string>();
    }
    return;
}

void add_children(map<string, vector<string>> &families, const string family, const string children)
{
    families[family].push_back(children);
    return;
}

int main(int argc, char const *argv[])
{
    map<string, vector<string>> families;

    add_family(families, "Zhang");
    add_children(families, "Zhang", "Qiang");
    add_children(families, "Zhang", "Gang");
    add_children(families, "Wang", "Wu");
    add_family(families, "Wang");

    for (auto f : families)
    {
        cout << f.first << "'s children: ";
        for (auto c : f.second)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}
