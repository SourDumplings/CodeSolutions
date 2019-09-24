/*
 @Date    : 2017-12-27 20:59:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p410
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

using namespace std;
using namespace std::placeholders;

int main(int argc, char const *argv[])
{
    vector<int> v{1, 2, 3, 4, 5};
    for (auto it = v.end() - 1; it + 1 != v.begin(); --it)
    {
        cout << *it << " ";
    }
    return 0;
}
