/*
 @Date    : 2017-12-28 20:31:07
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

int main(int argc, char const *argv[])
{
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
    {
        auto it = word_count.insert({word, 1});
        if (!it.second)
        {
            ++it.first->second;
        }
    }
    for (auto &w : word_count)
    {
        cout << w.first << " : " << w.second
        << ((w.second > 1) ? " times" : " time") << endl;
    }
    return 0;
}
