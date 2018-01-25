/*
 @Date    : 2017-12-28 20:45:35
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p434
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

void add_children(multimap<string, string> &families, const string &family,
                  const string &children)
{
    families.insert({family, children});
    return;
}

int main(int argc, char const *argv[])
{
    multimap<string, string> families;

    add_children(families, "Zhang", "Qiang");
    add_children(families, "Zhang", "Gang");
    add_children(families, "Wang", "Wu");

    for (auto f : families)
    {
        cout << f.first << "'s children: " << f.second << endl;
    }
    return 0;
}
