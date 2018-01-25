/*
 @Date    : 2017-12-27 14:43:46
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p401
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

bool check_size(const string &a, unsigned sz)
{
    return a.size() > sz;
}

int main(int argc, char const *argv[])
{
    vector<string> words{"sdjhkja", "adsda", "asdadad", "asd", "weiudhiun"};
    auto it = find_if(words.begin(), words.end(), bind(check_size, _1, 6));
    cout << *it << endl;
    return 0;
}
