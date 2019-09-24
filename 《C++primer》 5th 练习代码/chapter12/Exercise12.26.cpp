/*
 @Date    : 2018-01-01 20:25:37
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p484
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
#include <memory>
#include <new>

using namespace std;
using namespace std::placeholders;

int main(int argc, char const *argv[])
{
    unsigned n = 5;
    allocator<string> alloc;
    auto const p = alloc.allocate(n);
    auto *q = p;
    string s;
    while (cin >> s && q != p + n)
    {
        alloc.construct(q++, s);
    }
    for_each(p, q, [](const string &s) {cout << s << endl;});
    while (q != p)
    {
        alloc.destroy(--q);
    }
    alloc.deallocate(p, n);
    return 0;
}
