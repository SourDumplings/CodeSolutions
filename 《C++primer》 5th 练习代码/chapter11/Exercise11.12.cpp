/*
 @Date    : 2017-12-28 15:38:24
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

int main(int argc, char const *argv[])
{
    // pair<string, int> p;
    vector<pair<string, int>> v;
    string s;
    int i;
    // while (cin >> s && cin >> i)
    // {
    //     p = {s, i};
    //     v.push_back(p);
    // }
    while (cin >> s && cin >> i)
    {
        v.push_back(pair<string, int> {s, i});
    }
    for (auto &p : v)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
