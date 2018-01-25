/*
 @Date    : 2017-12-28 15:48:47
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p428
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
#include <utility>

using namespace std;
using namespace std::placeholders;

void add_family(map<string, vector<pair<string, string>>> &families, const string &family)
{
    if (families.find(family) == families.end())
    {
        families[family] = vector<pair<string, string>>();
    }
    return;
}

void add_children(map<string, vector<pair<string, string>>> &families, const string &family,
                  const string &children, const string &birth)
{
    pair<string, string> p{children, birth};
    families[family].push_back(p);
    return;
}

int main(int argc, char const *argv[])
{
    map<string, vector<pair<string, string>>> families;

    add_family(families, "Zhang");
    add_children(families, "Zhang", "Qiang", "19940226");
    add_children(families, "Zhang", "Gang", "19930929");
    add_children(families, "Wang", "Wu", "19701103");
    add_family(families, "Wang");

    for (auto f : families)
    {
        cout << f.first << "'s children: ";
        for (auto c : f.second)
        {
            cout << c.first << " " << c.second << " ";
        }
        cout << endl;
    }
    return 0;
}
