/*
 @Date    : 2017-12-27 21:15:20
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
    vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> l;
    copy(v.rbegin()+2, v.rend()-3, back_inserter(l));
    for_each(l.begin(), l.end(), [] (int i) {cout << i << " ";});
    return 0;
}
