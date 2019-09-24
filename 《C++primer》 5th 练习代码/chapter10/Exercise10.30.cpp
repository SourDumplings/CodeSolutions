/*
 @Date    : 2017-12-27 19:45:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p407
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
    istream_iterator<int> in(cin), eof;
    vector<int> v;
    while (in != eof)
    {
        v.push_back(*in++);
    }
    sort(v.begin(), v.end());
    ostream_iterator<int> out(cout, " ");
    copy(v.begin(), v.end(), out);
    return 0;
}
