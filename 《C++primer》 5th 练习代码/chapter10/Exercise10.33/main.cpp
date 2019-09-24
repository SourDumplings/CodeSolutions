/*
 @Date    : 2017-12-27 20:18:29
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
    ifstream fin("iostream_iter");
    ofstream fodd("odd"), feven("oeven");
    istream_iterator<int> in(fin), eof;
    ostream_iterator<int> out_odd(fodd, " "), out_even(feven, " ");
    vector<int> v;
    while (in != eof)
    {
        v.push_back(*in++);
    }
    auto first_even = partition(v.begin(), v.end(), [] (const int i) {return i & 1;});
    copy(v.begin(), first_even, out_odd);
    copy(first_even, v.end(), out_even);
    return 0;
}
