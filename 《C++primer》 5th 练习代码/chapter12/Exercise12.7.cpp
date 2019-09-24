/*
 @Date    : 2017-12-29 21:37:23
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p463
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

shared_ptr<vector<int>> new_vector(void)
{
    return make_shared<vector<int>>();
}

void read_ints(shared_ptr<vector<int>> pv)
{
    int i;
    while (cin >> i)
    {
        pv->push_back(i);
    }
    return;
}

void print_ints(const shared_ptr<vector<int>> pv)
{
    for (const auto &i : *pv)
    {
        cout << i << " ";
    }
    return;
}

int main(int argc, char const *argv[])
{
    auto pv = new_vector();

    read_ints(pv);

    print_ints(pv);

    return 0;
}
